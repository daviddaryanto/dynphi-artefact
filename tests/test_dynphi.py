# Copyright (c) 2026 David Daryanto
# SPDX-License-Identifier: Apache-2.0
"""Executable checks of every claim in the paper.  Run: python -m unittest -v tests.test_dynphi"""
import itertools, math, random, unittest
from dynphi.ir import Ins, Func, run
from dynphi.cfg import reaching_defs, rd_of, entry_def
from dynphi.core import (Evidence, collect, build, triage, prune, zero_hit_u, INF, UNK, FEAS)
from dynphi.gen import gen_function
from dynphi.oracle import Oracle, ExactVerifier, LossyVerifier, SampledVerifier
from dynphi.baselines import cold_filter, resolve_list, edge_coverage, eliminated
from dynphi.static_corr import static_rd, eliminated_pairs

D = 32
I = Ins


def ex_A():   # opaque predicate
    return Func([I("mov", "r1", 17), I("mov", "r2", 17), I("br", None, "r1", "r2", "==", 5),
                 I("mov", "r0", 0xDEAD), I("jmp", tgt=6), I("mov", "r0", 0xC0DE), I("ret", None, "r0")],
                inputs=("a",))

def ex_B(k=7):  # rare but live arm: taken iff a == k
    return Func([I("br", None, "a", k, "==", 3), I("mov", "r", 1), I("jmp", tgt=4),
                 I("mov", "r", 2), I("ret", None, "r")], inputs=("a",))

def ex_C():   # loop
    return Func([I("mov", "i", 0), I("bin", "i", "i", 1, "+"), I("br", None, "i", "n", "<", 1),
                 I("ret", None, "i")], inputs=("n",))

def ex_D():   # definition reachable, but cannot flow to its use
    return Func([I("mov", "r", 1), I("br", None, "a", 16, "<", 3), I("jmp", tgt=8),
                 I("mov", "r", 2), I("mov", "t", 0), I("br", None, "t", 0, "==", 7),
                 I("jmp", tgt=8), I("mov", "r", 9), I("bin", "s", "r", 1, "+"), I("ret", None, "s")],
                inputs=("a",))

def traces_for(f, inputs):
    return [run(f, a)[0] for a in inputs]

def evidence(f, rd, trs):
    ev = Evidence()
    for t in trs:
        collect(f, rd, t, ev)
    return ev

def rand_inputs(f, n, rng):
    return [tuple(rng.randrange(D) for _ in f.inputs) for _ in range(n)]

CORPUS = [gen_function(s) for s in range(40)] + [gen_function(500 + s, profile="rich") for s in range(40)]


# ---------------------------------------------------------------- reference (spec-level) implementations
def rd_bruteforce(f):
    """RD straight from the path definition of Section IV."""
    n = len(f); res = {p: {r: set() for r in f.regs} for p in range(n)}
    reach_entry = set(); st = [0]
    while st:
        p = st.pop()
        if p in reach_entry: continue
        reach_entry.add(p); st.extend(f.succ(p))
    for r in f.regs:
        # entry pseudo-definition: path p_in = p_1 -> ... -> p_m = p with r not in Def(p_i), i < m
        seen, st = set(), [0]
        while st:
            p = st.pop()
            if p in seen: continue
            seen.add(p); res[p][r].add(entry_def(r))
            if r not in f.defs(p): st.extend(f.succ(p))
        for q in range(n):
            if q not in reach_entry or r not in f.defs(q): continue
            seen, st = set(), list(f.succ(q))
            while st:
                p = st.pop()
                if p in seen: continue
                seen.add(p); res[p][r].add((q, r))
                if r not in f.defs(p): st.extend(f.succ(p))
    return {p: {r: frozenset(ds) for r, ds in m.items() if ds} for p, m in res.items() if p in reach_entry}

def counters_bruteforce(f, rd, trs):
    """Eq. (1)-(2): recompute lambda_t from scratch at every step."""
    F, M = {}, {}
    for t in trs:
        visited = set()
        for i, p in enumerate(t):
            for r in f.uses(p):
                d = entry_def(r)
                for s in range(i - 1, -1, -1):
                    if r in f.defs(t[s]): d = (t[s], r); break
                rds = rd_of(rd, p, r)
                if len(rds) >= 2 or d not in rds:
                    F[((p, r), d)] = F.get(((p, r), d), 0) + 1; visited.add((p, r))
        for s in visited: M[s] = M.get(s, 0) + 1
    return F, M


class TestDifferential(unittest.TestCase):
    def test_rd_matches_path_definition(self):
        for f in CORPUS + [ex_A(), ex_B(), ex_C(), ex_D()]:
            self.assertEqual(reaching_defs(f), rd_bruteforce(f), f"seed {getattr(f, 'seed', '?')}")

    def test_algorithm1_matches_formulas(self):
        rng = random.Random(1)
        for f in CORPUS[:25]:
            rd = reaching_defs(f)
            trs = traces_for(f, rand_inputs(f, 12, rng))
            ev = evidence(f, rd, trs)
            F, M = counters_bruteforce(f, rd, trs)
            self.assertEqual({(s, d): c for s, dd in ev.F.items() for d, c in dd.items()}, F)
            self.assertEqual({s: m for s, m in ev.M.items() if m}, M)


class TestExamples(unittest.TestCase):
    def test_example_A(self):
        f = ex_A(); rd = reaching_defs(f)
        self.assertEqual(len(rd_of(rd, 6, "r0")), 2)
        ev = evidence(f, rd, traces_for(f, [(i,) for i in range(30)]))
        self.assertEqual(ev.M[(6, "r0")], 30)
        self.assertEqual(dict(ev.F[(6, "r0")]), {(5, "r0"): 30})
        nodes, cands = build(rd, ev, 0.05, 0.1)
        self.assertAlmostEqual(cands[0][0], 0.095, places=3)
        self.assertEqual(cands[0][2], (3, "r0"))
        res = triage(f, rd, ev, ExactVerifier(Oracle(f, D)), 0.05, 0.1)
        self.assertEqual(res.K, {3})
        succ, rd2, doomed = prune(f, res.K)
        self.assertEqual(len(rd_of(rd2, 6, "r0")), 1)

    def test_example_B(self):
        f = ex_B(); rd = reaching_defs(f); o = Oracle(f, D)
        ev = evidence(f, rd, traces_for(f, [(3,), (5,)]))
        self.assertAlmostEqual(zero_hit_u(2, 0.05), 0.776, places=3)
        self.assertEqual(build(rd, ev, 0.05, 0.1)[1], [])           # withheld at M = 2
        ev = evidence(f, rd, traces_for(f, [(i % 7,) for i in range(50)]))   # a = 7 never drawn
        self.assertAlmostEqual(zero_hit_u(50, 0.05), 0.058, places=3)
        c = build(rd, ev, 0.05, 0.1)[1]; self.assertEqual(len(c), 1)
        res = triage(f, rd, ev, ExactVerifier(o), 0.05, 0.1)
        self.assertEqual((res.K, res.P, res.fed_back), (set(), set(), 1))
        self.assertEqual(ev.F[(4, "r")][(3, "r")], 1)                # feedback made it non-cold
        self.assertEqual(build(rd, ev, 0.05, 1.0)[1], [])

    def test_example_C(self):
        f = ex_C(); rd = reaching_defs(f)
        ev = evidence(f, rd, [run(f, (3,))[0]])
        self.assertEqual(dict(ev.F[(1, "i")]), {(0, "i"): 1, (1, "i"): 2})
        self.assertEqual(ev.M[(1, "i")], 1)
        n = build(rd, ev)[0][(1, "i")]
        self.assertTrue(n.split); self.assertEqual(n.cold, [])


class TestPropositions(unittest.TestCase):
    def test_P1_observation_soundness_and_escape(self):
        rng = random.Random(2); escapes = 0
        for f in CORPUS:
            rd = reaching_defs(f)
            trs = traces_for(f, rand_inputs(f, 15, rng))
            ev = evidence(f, rd, trs)
            self.assertEqual(ev.X, set())                              # complete CFG => no escape
            for s, dd in ev.F.items():
                for d in dd: self.assertIn(d, rd_of(rd, *s))           # observed subset of static
            # now delete one edge of a conditional branch that traces do take
            brs = [p for p in range(len(f)) if f.code[p].op == "br"]
            for p in brs[:3]:
                for drop in f.succ(p):
                    succ = {q: f.succ(q) for q in range(len(f))}
                    succ[p] = tuple(s for s in f.succ(p) if s != drop) or f.succ(p)
                    if succ[p] == f.succ(p): continue
                    rd2 = reaching_defs(f, succ)
                    ev2 = Evidence()
                    for t in trs:
                        if all(t[i] in rd2 for i in range(len(t))): collect(f, rd2, t, ev2)
                    if ev2.X:
                        escapes += 1
                        missing = any((t[i + 1] not in succ[t[i]]) for t in trs for i in range(len(t) - 1))
                        self.assertTrue(missing)                       # X != {} => an executed edge is missing
        self.assertGreater(escapes, 0, "escape check never fired: test would be vacuous")

    def test_P2_dead_implies_cold(self):
        rng = random.Random(3)
        for f in CORPUS:
            rd, o = reaching_defs(f), Oracle(f, D)
            for size in (1, 5, 40):
                ev = evidence(f, rd, traces_for(f, rand_inputs(f, size, rng)))
                nodes, cands = build(rd, ev, 0.05, 1.0)
                cset = {(s, d) for _, s, d in cands}
                for site, n in nodes.items():
                    for d in n.support:
                        if o.flow_inputs.get((d, site), 0) == 0:       # dead pair (stronger than dead site)
                            self.assertEqual(n.tag.get(d, 0), 0)
                            self.assertIn((site, d), cset)
            for p in f.construction_dead:                              # by-construction dead points are unreachable
                self.assertNotIn(p, o.reach_w)

    def test_P3_zero_hit_bound_and_its_failure_under_correlation(self):
        f = Func([I("br", None, "a", 8, "<", 3), I("mov", "r", 1), I("jmp", tgt=4),
                  I("mov", "r", 2), I("ret", None, "r")], inputs=("a",))       # q = 8/32 = 0.25
        rd, o = reaching_defs(f), Oracle(f, D)
        d = (3, "r"); q = o.q(d, (4, "r")); self.assertAlmostEqual(q, 0.25)
        rng, N, M, delta = random.Random(4), 4000, 30, 0.05
        def miss_rate(group):
            miss = 0
            for _ in range(N):
                ev = Evidence()
                for _ in range(M // group):
                    e1 = evidence(f, rd, traces_for(f, [(rng.randrange(D),)]))
                    ev.merge(e1, group)
                miss += ev.F[(4, "r")].get(d, 0) == 0
            return miss / N
        self.assertGreaterEqual(q, zero_hit_u(M, delta))                        # q in the proposition's region
        self.assertLessEqual(miss_rate(1), delta)                               # iid: bound holds (true value ~1.8e-4)
        self.assertGreater(miss_rate(10), delta)                                # correlated traces: bound is optimistic (Section VII-D)

    def test_P6_vacuity(self):
        for f in CORPUS:
            rd = reaching_defs(f)
            sweep = list(range(len(f)))                                # address-ordered sweep, one visit per point
            ev = Evidence(); collect(f, rd, sweep, ev)
            nodes, _ = build(rd, ev)
            self.assertFalse(any(n.split for n in nodes.values()))
            t = run(f, (5, 9))[0]
            if len(set(t)) == len(t):                                  # acyclic single trace
                ev = Evidence(); collect(f, rd, t, ev)
                self.assertFalse(any(n.split for n in build(rd, ev)[0].values()))
        # the sweep is not a trace: with data/unreachable bytes inside a function it can fabricate an escape
        f = Func([I("mov", "r", 1), I("jmp", tgt=3), I("mov", "r", 2), I("ret", None, "r")], inputs=("a",))
        self.assertTrue(self._sweep_escapes(f))
        self.assertFalse(run(f, (0,))[0] == list(range(len(f))))      # and it is not an execution

    @staticmethod
    def _sweep_escapes(f):
        ev = Evidence(); collect(f, reaching_defs(f), list(range(len(f))), ev); return bool(ev.X)

    def test_P4_verifier_soundness(self):
        rng = random.Random(5); bad_exact = bad_lossy = bad_sampled = 0; confirmed = 0
        for f in CORPUS:
            rd0, o = reaching_defs(f), Oracle(f, D)
            def violations(res):
                return (sum(1 for q in res.K if q in o.reach_w) +
                        sum(1 for d, s in res.P if o.flow_inputs.get((d, s), 0) > 0))
            for name, mk in (("exact", lambda: ExactVerifier(o)),
                             ("lossy", lambda: LossyVerifier(ExactVerifier(o), 0.4, seed=f.seed)),
                             ("sampled", lambda: SampledVerifier(f, D, k=6, seed=f.seed))):
                ev = evidence(f, rd0, traces_for(f, rand_inputs(f, 10, rng)))
                res = triage(f, rd0, ev, mk(), 0.05, 1.0)
                v = violations(res)
                if name == "exact": bad_exact += v; confirmed += len(res.P)
                elif name == "lossy": bad_lossy += v
                else: bad_sampled += v
        self.assertEqual((bad_exact, bad_lossy), (0, 0))
        self.assertGreater(confirmed, 20)
        self.assertGreater(bad_sampled, 0, "a path-limited 'verifier' must be caught being unsound")

    def test_P7_cost_independent_of_trace_length_and_count(self):
        f = ex_C(); rd = reaching_defs(f); sizes = set()
        for n in (3, 30, 300):
            ev = Evidence(); collect(f, rd, run(f, (n,), lmax=10**5)[0], ev); sizes.add(ev.n_F_entries())
        self.assertEqual(sizes, {2})
        for f in CORPUS[:10]:
            rd = reaching_defs(f)
            J = sum(len(ds) for p in rd for r, ds in rd[p].items() if len(ds) >= 2 and r in f.uses(p))
            for size in (1, 50, 400):
                ev = evidence(f, rd, traces_for(f, rand_inputs(f, size, random.Random(6))))
                self.assertLessEqual(ev.n_F_entries(), J + len(ev.X))
                self.assertLessEqual(len(ev.M), J)


class TestRevisedFeedbackLoop(unittest.TestCase):
    """Regression test for a defect found by testing the first version of Algorithm 3."""
    def setUp(self):
        self.f = ex_D(); self.rd = reaching_defs(self.f); self.o = Oracle(self.f, D)
        self.ev = evidence(self.f, self.rd, traces_for(self.f, [(i,) for i in range(40)]))
        self.d = (3, "r")

    def test_dB_is_reachable_but_never_flows(self):
        self.assertIn(3, self.o.reach_w)
        self.assertEqual(self.o.flow_inputs.get((self.d, (8, "r")), 0), 0)
        self.assertEqual(self.ev.F[(8, "r")].get(self.d, 0), 0)         # cold

    def test_reach_only_query_never_makes_progress(self):
        res = triage(self.f, self.rd, self.ev, ExactVerifier(self.o), 0.05, 1.0, budget=20, mode="reach_only")
        self.assertGreaterEqual(res.no_progress, 5)                     # burns the budget re-querying d
        self.assertEqual(res.P, set())

    def test_P5_flow_query_progress_and_termination(self):
        res = triage(self.f, self.rd, self.ev, ExactVerifier(self.o), 0.05, 1.0, budget=20, mode="flow")
        self.assertIn((self.d, (8, "r")), res.P)
        self.assertEqual(res.K, set())                                  # site is reachable: not dead *code*
        self.assertEqual(res.no_progress, 0); self.assertLess(res.queries, 20)


class TestIndependentCrossChecks(unittest.TestCase):
    """Checks whose reference is NOT code written alongside the implementation."""
    def test_concrete_flows_are_inside_static_rd(self):
        # the oracle derives flows from concrete execution only; RD comes from the dataflow solver
        for f in CORPUS:
            rd, o = reaching_defs(f), Oracle(f, D)
            for (d, (p, r)), n in o.flow_inputs.items():
                self.assertIn(d, rd_of(rd, p, r), f"seed {f.seed}")

    def test_contextual_piece_is_dead_pair_with_all_edges_hot(self):
        f = Func([I("mov", "r", 1), I("br", None, "a", 16, "<", 3), I("jmp", tgt=4),
                  I("mov", "r", 2), I("br", None, "a", 16, "<", 6), I("jmp", tgt=7),
                  I("mov", "r", 9), I("bin", "s", "r", 1, "+"), I("ret", None, "s")], inputs=("a",))
        rd, o = reaching_defs(f), Oracle(f, D)
        d = (3, "r")
        self.assertIn(d, rd_of(rd, 7, "r"))
        self.assertEqual(o.flow_inputs.get((d, (7, "r")), 0), 0)                 # dead pair
        for p in (1, 4):
            for s in f.succ(p): self.assertIn((p, s), o.edge_w)                  # but every branch edge is feasible
        ev = evidence(f, rd, traces_for(f, [(i,) for i in range(0, 32, 3)]))
        edges = {(t[i], t[i + 1]) for t in traces_for(f, [(i,) for i in range(0, 32, 3)]) for i in range(len(t) - 1)}
        V = ExactVerifier(o)
        rd2, nq, nde = edge_coverage(f, rd, edges, V)
        self.assertEqual((nq, nde), (0, 0))                                      # edge coverage has nothing to ask
        self.assertIn(d, rd_of(rd2, 7, "r"))                                     # ...and the dead pair survives
        found = resolve_list(ExactVerifier(o), cold_filter(rd, ev))[1]
        self.assertIn(((7, "r"), d), found)                                      # Dyn-Phi's definition tag finds it

    def test_edge_baseline_only_removes_dead_pairs(self):
        rng = random.Random(8)
        for f in CORPUS[:30]:
            rd, o = reaching_defs(f), Oracle(f, D)
            trs = traces_for(f, rand_inputs(f, 20, rng))
            edges = {(t[i], t[i + 1]) for t in trs for i in range(len(t) - 1)}
            rd2, _, _ = edge_coverage(f, rd, edges, ExactVerifier(o))
            gone = {((p, r), d) for p in rd for r, ds in rd[p].items() for d in ds if d not in rd_of(rd2, p, r)}
            for (site, d) in gone:
                self.assertEqual(o.flow_inputs.get((d, site), 0), 0)

    def test_guarded_reach_only_terminates_but_cannot_confirm_reachable_site(self):
        f = ex_D(); rd = reaching_defs(f); o = Oracle(f, D)
        ev = evidence(f, rd, traces_for(f, [(i,) for i in range(40)]))
        res = triage(f, rd, ev, ExactVerifier(o), 0.05, 1.0, budget=50, mode="reach_only_guarded")
        self.assertEqual(res.P, set()); self.assertLess(res.queries, 50)

    def test_family_wise_delta_is_more_conservative(self):
        f = CORPUS[3]; rd = reaching_defs(f)
        ev = evidence(f, rd, traces_for(f, rand_inputs(f, 30, random.Random(9))))
        u1 = [c[0] for c in build(rd, ev, 0.05, 1.0)[1]]
        u2 = [c[0] for c in build(rd, ev, 0.05, 1.0, family=True)[1]]
        if u1: self.assertTrue(all(b >= a for a, b in zip(u1, u2)) and any(b > a for a, b in zip(u1, u2)) or len(u1) == 1)



class RecDict(dict):
    def __init__(self, *a):
        super().__init__(*a); self.r, self.w = set(), set()
    def __getitem__(self, k):
        self.r.add(k); return super().__getitem__(k)
    def __setitem__(self, k, v):
        self.w.add(k); super().__setitem__(k, v)


def check_defuse_faithful(tc, f, args, lmax=4000):
    """Def(p) and Use(p) must equal what the interpreter actually writes / reads at p."""
    rec = RecDict(); state = {"p": None}
    def flush():
        p = state["p"]
        if p is None: return
        tc.assertEqual(rec.w, set(f.defs(p)), f"def mismatch at {p}: {f.code[p]}")
        tc.assertEqual(rec.r, set(f.uses(p)), f"use mismatch at {p}: {f.code[p]}")
        rec.r.clear(); rec.w.clear()
    def step(p, regs):
        flush(); state["p"] = p
    run(f, args, lmax, step=step, regs=rec)
    flush()


class TestStaticCorrelationBaseline(unittest.TestCase):
    def test_path_sensitive_rd_is_sound(self):
        removed = 0
        for f in CORPUS:
            rd, o = reaching_defs(f), Oracle(f, D)
            ps = static_rd(f)
            for (d, (p, r)), n in o.flow_inputs.items():                  # every concrete flow survives
                self.assertIn(d, ps[p][r], f"seed {f.seed}: lost flow {d} -> {(p, r)}")
            for p in rd:
                for r, ds in rd[p].items():
                    self.assertLessEqual(ps.get(p, {}).get(r, frozenset()), ds)     # and it only refines RD
                    removed += len(ds - ps.get(p, {}).get(r, frozenset()))
        self.assertGreater(removed, 20)                                   # not vacuous

    def test_static_baseline_sees_correlated_branches_but_not_arithmetic_opaque_predicates(self):
        ctx = Func([I("mov", "r", 1), I("br", None, "a", 16, "<", 3), I("jmp", tgt=4),
                    I("mov", "r", 2), I("br", None, "a", 16, "<", 6), I("jmp", tgt=7),
                    I("mov", "r", 9), I("bin", "s", "r", 1, "+"), I("ret", None, "s")], inputs=("a",))
        self.assertIn((3, "r"), rd_of(reaching_defs(ctx), 7, "r"))
        self.assertNotIn((3, "r"), static_rd(ctx)[7]["r"])                # d_b removed without any trace
        self.assertEqual(len(static_rd(ex_A())[6]["r0"]), 1)              # 17 == 17 is constant
        arith = Func([I("bin", "t", "a", 1, "+"), I("bin", "t", "t", "a", "*"), I("bin", "t", "t", 1, "&"),
                      I("br", None, "t", 0, "==", 6), I("mov", "r", 1), I("jmp", tgt=7),
                      I("mov", "r", 2), I("ret", None, "r")], inputs=("a",))
        self.assertEqual(static_rd(arith)[7]["r"], reaching_defs(arith)[7]["r"])   # needs parity reasoning: out of reach


class TestDefUseFaithfulness(unittest.TestCase):
    """Closes the circularity of the RD cross-check: the Def/Use model itself is checked against the interpreter."""
    def test_generated_functions(self):
        rng = random.Random(10)
        for f in CORPUS:
            for _ in range(4):
                check_defuse_faithful(self, f, tuple(rng.randrange(D) for _ in f.inputs))


if __name__ == "__main__":
    unittest.main(verbosity=2)
