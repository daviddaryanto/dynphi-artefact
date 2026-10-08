# Copyright (c) 2026 David Daryanto
# SPDX-License-Identifier: Apache-2.0
"""Controlled evaluation.  Usage: python -m experiments.run_eval [N_FUNCS] [synthetic|x86|x86v2]

synthetic: corpora C1/C2 (toy-IR generator)               -> results/results.json
x86      : C3, real gcc -O0 x86-64 code lifted to the IR   -> results/results_x86.json   (prereg/PREREG_C3.md)
x86v2    : C4, injected + plain functions, wider predicates -> results/results_x86v2.json (prereg/PREREG_C4.md)
Set DYNPHI_OUT=/path/out.json to write elsewhere (used by the CI smoke run).  The x86 corpora are read from the
committed listings in dynphi/x86/data, so no compiler is needed.

Statistics: cluster bootstrap (function = unit, 2000 resamples).  Paired differences are bootstrapped
over functions on the SAME trace draws; equivalence uses the 90% interval (TOST) against a margin."""
import hashlib, itertools, json, math, os, random, sys, time
import numpy as np
from dynphi.ir import run
from dynphi.cfg import reaching_defs, rd_of
from dynphi.core import Evidence, collect, build, triage, resolve, zero_hit_u
from dynphi.gen import gen_function
from dynphi.oracle import Oracle, ExactVerifier, LossyVerifier, SampledVerifier
from dynphi.baselines import cold_filter, resolve_list, edge_coverage, eliminated
from dynphi.static_corr import static_analysis, eliminated_pairs

D, DELTA = 32, 0.05
N = int(sys.argv[1]) if len(sys.argv) > 1 else 200
MODE = sys.argv[2] if len(sys.argv) > 2 else "synthetic"
SIZES = [1, 2, 5, 10, 30, 100]
THETAS = [0.05, 0.1, 0.25, 0.5, 1.0]
CS = (1, 10, 100)
STRATS = ["cold_filter", "dynphi", "edge", "edge+cold", "static", "static+cold", "static+edge+cold"]
t0 = time.time()
log = lambda *a: print(f"[{time.time()-t0:6.1f}s]", *a, flush=True)


def sha_files(paths):
    h = hashlib.sha256()
    for p in sorted(paths):
        h.update(p.encode()); h.update(open(p, "rb").read())
    return h.hexdigest()


def code_files():
    out = []
    for root in ("dynphi", "experiments", "tests"):
        for dp, _, fs in os.walk(root):
            out += [os.path.join(dp, f) for f in fs if f.endswith(".py")]
    return out


def boot(pairs, B=2000, seed=0):
    a = np.array(pairs, dtype=float)
    if len(a) == 0 or a[:, 1].sum() == 0:
        return [float("nan")] * 3
    rng = np.random.default_rng(seed)
    idx = rng.integers(0, len(a), (B, len(a)))
    r = a[idx, 0].sum(1) / np.maximum(a[idx, 1].sum(1), 1e-12)
    lo, hi = np.percentile(r, [2.5, 97.5])
    return [float(a[:, 0].sum() / a[:, 1].sum()), float(lo), float(hi)]


def boot_diff(triples, B=2000, seed=1):
    """Paired difference sum(n1 - n2) / sum(den) over functions: [est, lo95, hi95, lo90, hi90]."""
    a = np.array(triples, dtype=float)
    if len(a) == 0 or a[:, 2].sum() == 0:
        return [float("nan")] * 5
    rng = np.random.default_rng(seed)
    idx = rng.integers(0, len(a), (B, len(a)))
    r = (a[idx, 0].sum(1) - a[idx, 1].sum(1)) / np.maximum(a[idx, 2].sum(1), 1e-12)
    est = (a[:, 0].sum() - a[:, 1].sum()) / a[:, 2].sum()
    return [float(est)] + [float(x) for x in np.percentile(r, [2.5, 97.5, 5, 95])]


def join_pairs(f, rd):
    out = []
    for p in sorted(rd):
        for r in sorted(f.uses(p)):
            ds = rd_of(rd, p, r)
            if len(ds) >= 2:
                out += [((p, r), d) for d in sorted(ds)]
    return out


class Item:
    def __init__(self, func):
        self.f = func
        self.clean = bool(getattr(func, "clean", False))
        self.rd = reaching_defs(self.f)
        self.lm = getattr(func, "lmax", 400)
        self.o = Oracle(self.f, D, lmax=self.lm)
        assert not self.o.truncated
        self.evs, self.edges = [], []
        for a in itertools.product(range(D), repeat=len(self.f.inputs)):
            tr = run(self.f, a, self.lm)[0]
            ev = Evidence(); collect(self.f, self.rd, tr, ev)
            self.evs.append(ev); self.edges.append(frozenset(zip(tr, tr[1:])))
        self.pairs = join_pairs(self.f, self.rd)
        self.dead = {(s, d) for s, d in self.pairs if self.o.flow_inputs.get((d, s), 0) == 0}
        self.live_q = [(s, d, self.o.q(d, s)) for s, d in self.pairs if self.o.q(d, s) > 0]
        self.rd_s, self.live_edges = static_analysis(self.f)
        self.el_static = eliminated_pairs(self.rd, self.rd_s, self.dead)
        assert self.el_static <= self.dead                       # static analysis must be sound
        self.q_exh = None

    def _fold(self, idxs, group=1):
        ev, edges = Evidence(), set()
        for k in idxs:
            ev.merge(self.evs[k], group); edges |= self.edges[k]
        return ev, edges

    def draw(self, rng, size, group=1):
        return self._fold([rng.randrange(len(self.evs)) for _ in range(max(1, size // group))], group)

    def draw_seeded(self, rng, size, per_seed=10, radius=2):
        idxs = []
        for _ in range(max(1, math.ceil(size / per_seed))):
            ca, cb = rng.randrange(D), rng.randrange(D)
            for _ in range(min(per_seed, size)):
                idxs.append(((ca + rng.randint(-radius, radius)) % D) * D + (cb + rng.randint(-radius, radius)) % D)
        return self._fold(idxs[:size])

    def exhaustive(self):
        if self.q_exh is None:
            V = ExactVerifier(self.o)
            _, found = resolve_list(V, self.pairs)
            assert found == self.dead
            self.q_exh = (V.n_queries, V.verdicts["FEASIBLE"], V.verdicts["INFEASIBLE"])
        return self.q_exh


def copy_ev(ev):
    e = Evidence(); e.merge(ev); return e


def vcount(*Vs):
    return [sum(V.n_queries for V in Vs), sum(V.verdicts["FEASIBLE"] for V in Vs), sum(V.verdicts["INFEASIBLE"] for V in Vs)]


R = {"settings": dict(functions_per_corpus=N, mode=MODE, domain=f"{D}^2 inputs per function", delta=DELTA,
                      ci="cluster bootstrap over functions, 2000 resamples, 95% (paired where stated)",
                      code_sha256=sha_files(code_files()),
                      prereg_sha256={f: hashlib.sha256(open(f, "rb").read()).hexdigest() for f in ("prereg/PREREG_C3.md", "prereg/PREREG_C4.md") if os.path.exists(f)})}
corpora = {}
if MODE == "synthetic":
    specs = [("C1_basic", "basic", 1000), ("C2_rich", "rich", 5000)]
    build_corpus = lambda prof, base: [Item(gen_function(base + i, profile=prof)) for i in range(N)]
elif MODE == "x86":
    from dynphi.x86.corpus import load_corpus
    specs = [("C3_x86", "c3", 0)]
    build_corpus = lambda prof, base: [Item(f) for f in load_corpus(prof, N)]
else:
    from dynphi.x86.corpus import load_corpus
    specs = [("C4_x86v2", "c4", 0)]
    build_corpus = lambda prof, base: [Item(f) for f in load_corpus(prof, N)]
for name, prof, base in specs:
    log("building", name)
    corpora[name] = build_corpus(prof, base)
    its = corpora[name]
    R[name] = dict(avg_instructions=sum(len(i.f) for i in its) / N, join_pairs=sum(len(i.pairs) for i in its),
                   dead_join_pairs=sum(len(i.dead) for i in its),
                   dead_pairs_with_reachable_site=sum(1 for i in its for s, d in i.dead if d[0] == -1 or d[0] in i.o.reach_w),
                   functions_with_dead_pair=sum(1 for i in its if i.dead),
                   functions_without_dead_pair=sum(1 for i in its if not i.dead),
                   avg_visit_fraction=float(np.mean([v / 1024 for i in its for v in i.o.visit_inputs.values()])),
                   static_recall_all=sum(len(i.el_static) for i in its) / max(1, sum(len(i.dead) for i in its)))
    if MODE == "x86v2":
        R[name]["plain_functions"] = sum(1 for i in its if i.clean)
        R[name]["plain_dead_pairs"] = sum(len(i.dead) for i in its if i.clean)

# --------------------------------------------------------------------------- E1 (+ theta sweep)
log("E1")
for name, items in corpora.items():
    rng, out = random.Random(11), {}
    for T in SIZES:
        prec, rec_v, rec_a, ncand, n01 = [], [], [], [], []
        th = {t: [[], []] for t in THETAS}
        for it in items:
            tp = cand = dv = c01 = 0
            tt = {t: [0, 0] for t in THETAS}
            for _ in range(10):
                ev, _e = it.draw(rng, T)
                _, cands = build(it.rd, ev, DELTA, 1.0)
                tp += sum(1 for _, s, d in cands if (s, d) in it.dead); cand += len(cands)
                c01 += sum(1 for u, _, _ in cands if u <= 0.1)
                dv += sum(1 for s, d in it.dead if ev.M.get(s, 0) > 0)
                for t in THETAS:
                    for u, s, d in cands:
                        if u <= t:
                            tt[t][1] += 1; tt[t][0] += (s, d) in it.dead
            prec.append((tp, cand)); rec_v.append((tp, dv)); rec_a.append((tp, 10 * len(it.dead)))
            ncand.append((cand, 10)); n01.append((c01, 10))
            for t in THETAS:
                th[t][0].append(tuple(tt[t])); th[t][1].append((tt[t][0], 10 * len(it.dead)))
        out[str(T)] = dict(precision=boot(prec), recall_visited=boot(rec_v), recall_all=boot(rec_a),
                           cand_per_fn=boot(ncand)[0], cand_per_fn_theta01=boot(n01)[0],
                           theta={str(t): dict(precision=boot(th[t][0]), recall_all=boot(th[t][1]),
                                               cand_per_fn=sum(b for _, b in th[t][0]) / (10 * len(items)))
                                  for t in THETAS})
    R[name]["E1"] = out

# --------------------------------------------------------------------------- E2 strategies (ALL functions)
log("E2")
DRAWS = 3
for name, items in corpora.items():
    rng = random.Random(22)
    recs = []                                                   # one record per function
    for it in items:
        qex = it.exhaustive()
        acc = {k: [0, 0, 0, 0] for k in STRATS}                 # queries, feasible, infeasible, dead pairs found
        nd = len(it.dead)
        for _ in range(DRAWS):
            ev, edges = it.draw(rng, 30)
            cands = cold_filter(it.rd, ev)
            V = ExactVerifier(it.o); _, f1 = resolve_list(V, cands)
            acc["cold_filter"] = [a + b for a, b in zip(acc["cold_filter"], vcount(V) + [len(f1 & it.dead)])]
            V = ExactVerifier(it.o); res = triage(it.f, it.rd, copy_ev(ev), V, DELTA, 1.0)
            fd = {(s_, d) for q, s_, d, out in res.log if out in ("DEADCODE", "DEADPAIR")} & it.dead
            acc["dynphi"] = [a + b for a, b in zip(acc["dynphi"], vcount(V) + [len(fd)])]
            V = ExactVerifier(it.o); rd2, _, _ = edge_coverage(it.f, it.rd, edges, V)
            el = eliminated(it.dead, rd2); assert el <= it.dead
            acc["edge"] = [a + b for a, b in zip(acc["edge"], vcount(V) + [len(el)])]
            V2 = ExactVerifier(it.o)
            resid = [(s_, d) for s_, d in cands if d in rd_of(rd2, s_[0], s_[1])]
            _, f2 = resolve_list(V2, resid)
            acc["edge+cold"] = [a + b for a, b in zip(acc["edge+cold"], vcount(V, V2) + [len((f2 | el) & it.dead)])]
            acc["static"] = [a + b for a, b in zip(acc["static"], [0, 0, 0, len(it.el_static)])]
            V3 = ExactVerifier(it.o)
            resid = [(s_, d) for s_, d in cands if d in rd_of(it.rd_s, s_[0], s_[1])]
            _, f3 = resolve_list(V3, resid)
            acc["static+cold"] = [a + b for a, b in zip(acc["static+cold"], vcount(V3) + [len((f3 | it.el_static) & it.dead)])]
            succ_live = {p: tuple(s for s in it.f.succ(p) if (p, s) in it.live_edges) for p in range(len(it.f))}
            V4 = ExactVerifier(it.o); rd4, _, _ = edge_coverage(it.f, it.rd, edges, V4, base_succ=succ_live)
            el4 = eliminated(it.dead, rd4) | it.el_static
            V5 = ExactVerifier(it.o)
            resid = [(s_, d) for s_, d in cands if d in rd_of(rd4, s_[0], s_[1]) and d in rd_of(it.rd_s, s_[0], s_[1])]
            _, f5 = resolve_list(V5, resid)
            acc["static+edge+cold"] = [a + b for a, b in zip(acc["static+edge+cold"], vcount(V4, V5) + [len((f5 | el4) & it.dead)])]
        recs.append(dict(acc=acc, dead=nd * DRAWS, ex=[x * DRAWS for x in qex], clean=it.clean, has_dead=bool(nd)))
    subsets = {"all": lambda r: True, "with_dead": lambda r: r["has_dead"], "no_dead": lambda r: not r["has_dead"]}
    if MODE == "x86v2":
        subsets.update({"injected": lambda r: not r["clean"], "plain": lambda r: r["clean"]})
    E2 = {}
    for sub, pred in subsets.items():
        rs = [r for r in recs if pred(r)]
        if not rs:
            continue
        e = {"n_functions": len(rs), "exhaustive_queries_total": sum(r["ex"][0] for r in rs)}
        for k in STRATS:
            e[k] = dict(query_ratio_vs_exhaustive=boot([(r["acc"][k][0], r["ex"][0]) for r in rs]),
                        recall=boot([(r["acc"][k][3], r["dead"]) for r in rs]) if sum(r["dead"] for r in rs) else None,
                        queries_per_function=sum(r["acc"][k][0] for r in rs) / (DRAWS * len(rs)),
                        queries_total=int(sum(r["acc"][k][0] for r in rs)),
                        cost_ratio={str(c): boot([(r["acc"][k][1] + c * r["acc"][k][2], r["ex"][1] + c * r["ex"][2]) for r in rs]) for c in CS})
        e["paired"] = dict(
            dynphi_minus_cold_queries=boot_diff([(r["acc"]["dynphi"][0], r["acc"]["cold_filter"][0], r["ex"][0]) for r in rs]),
            dynphi_minus_cold_recall=boot_diff([(r["acc"]["dynphi"][3], r["acc"]["cold_filter"][3], r["dead"]) for r in rs]) if sum(r["dead"] for r in rs) else None,
            sec_minus_cold_queries=boot_diff([(r["acc"]["static+edge+cold"][0], r["acc"]["cold_filter"][0], r["ex"][0]) for r in rs]),
            edgecold_minus_edge_recall=boot_diff([(r["acc"]["edge+cold"][3], r["acc"]["edge"][3], r["dead"]) for r in rs]) if sum(r["dead"] for r in rs) else None)
        E2[sub] = e
    R[name]["E2"] = {**E2["all"], "by_subset": {k: v for k, v in E2.items() if k != "all"}}
    R[name]["E2"]["exhaustive"] = dict(queries_total=E2["all"]["exhaustive_queries_total"], recall=[1.0, 1.0, 1.0])

# --------------------------------------------------------------------------- E3 ordering ablation (paired)
log("E3")
BUD = [i / 20 for i in range(21)]
J50 = BUD.index(0.5)
for name, items in corpora.items():
    out = {}
    for T in (10, 30):
        rng = random.Random(33 + T)
        per = {k: [[0.0] * len(BUD) for _ in items] for k in ("u", "address", "random")}
        den = [0] * len(items); dist_u = []
        for ii, it in enumerate(items):
            for _ in range(10):
                ev, _e = it.draw(rng, T)
                _, cands = build(it.rd, ev, DELTA, 1.0)
                if not cands:
                    continue
                dist_u.append(len({round(u, 12) for u, _, _ in cands}))
                orders = {"u": [(s, d) for _, s, d in cands], "address": sorted((s, d) for _, s, d in cands)}
                rnd = list(orders["address"]); rng.shuffle(rnd); orders["random"] = rnd
                den[ii] += sum(1 for sd in orders["u"] if sd in it.dead)
                for k, od in orders.items():
                    V = ExactVerifier(it.o); lg, _ = resolve_list(V, od); tot = max(1, V.n_queries)
                    for j, b in enumerate(BUD):
                        per[k][ii][j] += sum(1 for q, (s, d), hit in lg if hit and q <= b * tot)
        res = {k: {str(b): boot([(per[k][ii][j], den[ii]) for ii in range(len(items))])
                   for j, b in enumerate(BUD) if b in (0.1, 0.25, 0.5)} for k in per}
        res["curve"] = {k: [float(sum(per[k][ii][j] for ii in range(len(items))) / max(1, sum(den))) for j in range(len(BUD))] for k in per}
        res["paired_half_budget"] = {
            "u_minus_address": boot_diff([(per["u"][ii][J50], per["address"][ii][J50], den[ii]) for ii in range(len(items))]),
            "u_minus_random": boot_diff([(per["u"][ii][J50], per["random"][ii][J50], den[ii]) for ii in range(len(items))])}
        res["distinct_u_per_function_mean"] = float(np.mean(dist_u)) if dist_u else float("nan")
        res["budget_fraction"] = BUD
        out[str(T)] = res
    R[name]["E3"] = out

# --------------------------------------------------------------------------- E4 safety (ONE draw shared by all verifiers)
log("E4")
for name, items in corpora.items():
    rng = random.Random(44)
    E = {k: dict(K_wrong=0, P_wrong=0, K=0, P=0, unknown=0, no_progress=0) for k in ("exact", "lossy30", "sampled8")}
    for it in items:
        ev0, _e = it.draw(rng, 10)
        for k in E:
            V = {"exact": lambda: ExactVerifier(it.o), "lossy30": lambda: LossyVerifier(ExactVerifier(it.o), 0.3, it.f.seed),
                 "sampled8": lambda: SampledVerifier(it.f, D, 8, it.f.seed)}[k]()
            res = triage(it.f, it.rd, copy_ev(ev0), V, DELTA, 1.0)
            e = E[k]; e["K"] += len(res.K); e["P"] += len(res.P); e["unknown"] += len(res.U)
            e["no_progress"] += res.no_progress
            e["K_wrong"] += sum(1 for q in res.K if q in it.o.reach_w)
            e["P_wrong"] += sum(1 for d, s in res.P if it.o.flow_inputs.get((d, s), 0) > 0)
    R[name]["E4"] = E

# --------------------------------------------------------------------------- E5 calibration (synthetic only)
if MODE == "synthetic":
    log("E5")
    items = corpora["C2_rich"]
    rng = random.Random(55)
    E5 = {}
    for T in (30, 100):
        for samp in ("iid", "dup5", "seeded"):
            allp, nearp, nearp_eff = [], [], []
            units, qvals = set(), set()
            for ii, it in enumerate(items):
                a = [0, 0]; nr = [0, 0]; ne = [0, 0]
                for _ in range(6):
                    ev, _e = (it.draw(rng, T) if samp == "iid" else it.draw(rng, T, 5) if samp == "dup5" else it.draw_seeded(rng, T))
                    g = 5 if samp == "dup5" else 1
                    for s, d, q in it.live_q:
                        M = ev.M.get(s, 0)
                        if M == 0: continue
                        miss = int(ev.F[s].get(d, 0) == 0); u = zero_hit_u(M, DELTA)
                        if q >= u: a[0] += miss; a[1] += 1
                        if u <= q < 2 * u:
                            nr[0] += miss; nr[1] += 1; units.add((ii, s, d)); qvals.add(round(q, 6))
                        Me = max(1, M // g); ue = zero_hit_u(Me, DELTA)
                        if ue <= q < 2 * ue: ne[0] += miss; ne[1] += 1
                allp.append(tuple(a)); nearp.append(tuple(nr)); nearp_eff.append(tuple(ne))
            E5[f"T{T}_{samp}"] = dict(miss_all=boot(allp), trials_all=int(sum(b for _, b in allp)),
                                      miss_near=boot(nearp), trials_near=int(sum(b for _, b in nearp)),
                                      distinct_pairs_near=len(units), distinct_q_near=len(qvals),
                                      miss_near_Meff=boot(nearp_eff) if samp == "dup5" else None)
    R["E5"] = E5

# --------------------------------------------------------------------------- E6 verifier-query ablation
log("E6")
for name, items in corpora.items():
    rng = random.Random(66)
    pr = {m: [] for m in ("flow", "reach_only_guarded")}; qr = {m: [] for m in pr}
    for it in items:
        if not it.dead: continue
        ev, _e = it.draw(rng, 30)
        for m in pr:
            res = triage(it.f, it.rd, copy_ev(ev), ExactVerifier(it.o), DELTA, 1.0, mode=m, budget=10**6)
            pr[m].append((len({(s, d) for d, s in res.P} & it.dead), len(it.dead))); qr[m].append((res.queries, 1))
    R[name]["E6"] = {m: dict(dead_pairs_confirmed=boot(pr[m]), queries=int(sum(a for a, _ in qr[m]))) for m in pr}

# --------------------------------------------------------------------------- E7 location classes (x86 only)
if MODE != "synthetic":
    log("E7")
    cls = lambda r: "slot" if r.startswith("m") else ("flags" if r == "flags" else "register")
    for name, items in corpora.items():
        tab = {c: dict(join_pairs=0, dead_pairs=0) for c in ("slot", "register", "flags")}
        sites = {c: set() for c in tab}
        for ii, it in enumerate(items):
            for (s_, d) in it.pairs:
                c = cls(s_[1]); tab[c]["join_pairs"] += 1; sites[c].add((ii, s_))
                tab[c]["dead_pairs"] += (s_, d) in it.dead
        for c in tab: tab[c]["join_use_sites"] = len(sites[c])
        tot = sum(v["dead_pairs"] for v in tab.values())
        R[name]["E7"] = dict(by_location=tab, dead_total=tot,
                             fraction_dead_on_slots=tab["slot"]["dead_pairs"] / max(1, tot),
                             fraction_dead_visible_to_register_only=(tab["register"]["dead_pairs"] + tab["flags"]["dead_pairs"]) / max(1, tot))

OUT = os.environ.get("DYNPHI_OUT") or {"synthetic": "results/results.json", "x86": "results/results_x86.json", "x86v2": "results/results_x86v2.json"}[MODE]
json.dump(R, open(OUT, "w"), indent=1)
log("done", OUT)
