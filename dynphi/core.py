# Copyright (c) 2026 David Daryanto
# SPDX-License-Identifier: Apache-2.0
"""Dyn-Phi: Algorithm 1 (evidence), Algorithm 2 (nodes + ranking), Algorithm 3 (triage)."""
from collections import defaultdict
from dataclasses import dataclass, field
from .cfg import EMPTY, rd_of, reaching_defs
from .ir import run

INF = ("INFEASIBLE", None)
UNK = ("UNKNOWN", None)
def FEAS(w): return ("FEASIBLE", w)


class Evidence:
    """Counters F (per use site and definition), M (traces per use site), escape set X."""
    def __init__(self):
        self.F = defaultdict(lambda: defaultdict(int))
        self.M = defaultdict(int)
        self.X = set()

    def merge(self, other, times=1):
        for site, dd in other.F.items():
            for d, c in dd.items():
                self.F[site][d] += c * times
        for site, m in other.M.items():
            self.M[site] += m * times
        self.X |= other.X

    def n_F_entries(self):
        return sum(len(v) for v in self.F.values())


def collect(func, rd, trace, ev):
    """Algorithm 1: fold one trace into ev (counters only; the trace is not stored)."""
    lam = {r: (-1, r) for r in func.regs}
    seen = set()
    for p in trace:
        for r in func.uses(p):
            d = lam[r]
            rds = rd_of(rd, p, r)
            esc = d not in rds
            if esc:
                ev.X.add((p, r, d))
            if len(rds) >= 2 or esc:
                ev.F[(p, r)][d] += 1
                if (p, r) not in seen:
                    seen.add((p, r)); ev.M[(p, r)] += 1
        for r in func.defs(p):
            lam[r] = (p, r)


@dataclass
class Node:
    site: tuple
    support: frozenset
    tag: dict
    M: int
    @property
    def cold(self): return sorted(d for d in self.support if self.tag.get(d, 0) == 0)
    @property
    def split(self): return sum(1 for d in self.support if self.tag.get(d, 0) > 0) >= 2


def zero_hit_u(M, delta):
    return 1.0 - delta ** (1.0 / M)


def build(rd, ev, delta=0.05, theta=1.0, family=False):
    """Algorithm 2.  Returns (nodes, candidates) with candidates = [(u, site, d)] sorted by u.

    family=True applies a Bonferroni correction: delta is divided by the number of cold
    definitions tested in this call, so the zero-hit statements hold simultaneously."""
    nodes, cands = {}, []
    for site, m in ev.M.items():
        if m <= 0:
            continue
        p, r = site
        tag = dict(ev.F.get(site, {}))
        support = frozenset(rd_of(rd, p, r)) | frozenset(d for d, c in tag.items() if c > 0)
        nodes[site] = Node(site, support, tag, m)
    n_cold = sum(len(n.cold) for n in nodes.values())
    dl = delta / max(1, n_cold) if family else delta
    for site, n in nodes.items():
        u = zero_hit_u(n.M, dl)
        if u <= theta:
            cands.extend((u, site, d) for d in n.cold)
    cands.sort(key=lambda c: (c[0], c[1], c[2]))      # ties: address order (deterministic)
    return nodes, cands


def resolve(V, d, site, mode="flow"):
    """Ask the verifier about one cold definition.

    mode='flow'       : revised query: reach(q) then flow(d -> use)       (this paper)
    mode='reach_only' : original query -- reach(q) only                      (v1 of the paper)
    mode='reach_only_guarded': reach-only plus a resolved-set guard (terminates, but cannot
                        confirm a dead pair whose definition site is reachable)
    Returns (outcome, witness) with outcome in DEADCODE | DEADPAIR | LIVE | UNKNOWN.
    """
    q = d[0]
    if q != -1:                                   # entry pseudo-definition is trivially reachable
        v = V.reach(q)
        if v[0] == "INFEASIBLE":
            return "DEADCODE", None
        if v[0] == "UNKNOWN":
            return "UNKNOWN", None
        if mode.startswith("reach_only"):
            return "LIVE", v[1]
    v = V.flow(d, site)
    if v[0] == "INFEASIBLE":
        return "DEADPAIR", None
    if v[0] == "UNKNOWN":
        return "UNKNOWN", None
    return "LIVE", v[1]


@dataclass
class TriageResult:
    K: set = field(default_factory=set)       # program points proved unreachable
    P: set = field(default_factory=set)       # (d, site) pairs proved never to flow
    U: set = field(default_factory=set)       # unresolved
    queries: int = 0
    fed_back: int = 0                         # witnesses replayed as new traces
    no_progress: int = 0                      # feedback that left the definition cold
    log: list = field(default_factory=list)   # (cumulative queries, site, d, outcome)


def triage(func, rd, ev, V, delta=0.05, theta=1.0, budget=10**9, mode="flow", lmax=None):
    """Algorithm 3 (with the flow-sensitive verifier query).  Mutates ev.

    Witnesses are replayed with step bound ``lmax`` (default: the verifier's own bound);
    Proposition 5 assumes lmax >= the length of the verifier's witness executions."""
    if lmax is None:
        lmax = getattr(V, "lmax", 400)
    res, done = TriageResult(), set()
    q0, calls = V.n_queries, 0       # `budget` caps verifier invocations as well as distinct queries,
    nodes, cands = build(rd, ev, delta, theta)   # so a non-progressing loop cannot spin on cached answers
    i = 0
    while True:
        while i < len(cands) and (cands[i][1], cands[i][2]) in done:
            i += 1
        if i >= len(cands) or V.n_queries - q0 >= budget or calls >= budget:
            break
        u, site, d = cands[i]
        calls += 1
        out, w = resolve(V, d, site, mode)
        res.log.append((V.n_queries - q0, site, d, out))
        if out == "DEADCODE":
            res.K.add(d[0]); res.P.add((d, site)); done.add((site, d))
        elif out == "DEADPAIR":
            res.P.add((d, site)); done.add((site, d))
        elif out == "UNKNOWN":
            res.U.add((site, d)); done.add((site, d))
        else:                                          # LIVE: replay witness, add as evidence
            trace, _, _ = run(func, w, lmax)
            collect(func, rd, trace, ev)
            res.fed_back += 1
            if ev.F[site].get(d, 0) > 0 or mode in ("flow", "reach_only_guarded"):
                done.add((site, d))
            else:
                res.no_progress += 1                   # d stays cold -> would be re-queried
            nodes, cands = build(rd, ev, delta, theta)
            i = 0
            continue
        i += 1
    res.queries = V.n_queries - q0
    return res


def prune(func, K, P=()):
    """Fold branches into doomed regions and recompute RD on the pruned CFG."""
    n = len(func)
    doomed = set(K)
    changed = True
    while changed:
        changed = False
        for p in range(n):
            s = func.succ(p)
            if p not in doomed and s and all(t in doomed for t in s):
                doomed.add(p); changed = True
    succ = {p: tuple(t for t in func.succ(p) if t not in doomed) for p in range(n)}
    rd2 = reaching_defs(func, succ)
    for d, (p, r) in P:
        if p in rd2 and r in rd2[p]:
            rd2[p][r] = rd2[p][r] - {d}
    return succ, rd2, doomed
