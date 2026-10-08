# Copyright (c) 2026 David Daryanto
# SPDX-License-Identifier: Apache-2.0
"""Trace-free, path-sensitive STATIC baseline: reaching definitions with per-definition branch facts.

Every reaching definition d carries the facts that hold on the paths along which d is live: for an
operand pair (a, b) the set of orderings (<, =, >) still possible after the branches taken since d
was created (d inherits the facts valid at its definition point).  A branch on the same pair, with
neither operand redefined, is decided per definition; a definition is propagated along an edge only
if the edge is feasible under ITS facts.  So a correlated pair of branches (contextual predicate)
removes the definition that cannot survive the second test, with no trace and no verifier.
It has no arithmetic reasoning: it cannot prove ((x*(x+1))&1)==0.

Soundness: the result over-approximates the concrete flows (checked against the oracle in tests)."""
from .cfg import EMPTY

U = {"e": {"="}, "ne": {"<", ">"}, "a": {">"}, "ae": {">", "="}, "b": {"<"}, "be": {"<", "="}}
S = {"g": {">"}, "ge": {">", "="}, "l": {"<"}, "le": {"<", "="}}
TOY = {"==": "e", "!=": "ne", ">": "a", ">=": "ae", "<": "b", "<=": "be"}
ALL = frozenset("<=>")


def _truth(cond):
    return frozenset(U[cond] if cond in U else S[cond])


def _lat(cond):
    return "s" if cond in S else "u"


def _pair_and_cond(func, p):
    i = func.code[p]
    if i.op == "br":
        return (i.a, i.b), TOY[i.f]
    if i.op == "jcc" and p > 0 and func.code[p - 1].op == "cmp" and func.code[p - 1].f != "test":
        c = func.code[p - 1]
        return (c.a, c.b), i.f                      # adjacent cmp: operands cannot be redefined in between
    return None, (i.f if i.op == "jcc" else None)


def _poss(facts, pr, cond):
    if isinstance(pr[0], int) and isinstance(pr[1], int):
        a, b = pr
        return frozenset("<" if a < b else "=" if a == b else ">")
    return facts.get((pr[0], pr[1], _lat(cond)), ALL)


def _narrow(facts, pr, cond, taken):
    T = _truth(cond)
    f = dict(facts)
    P = _poss(facts, pr, cond)
    f[(pr[0], pr[1], _lat(cond))] = frozenset(P & T if taken else P - T)
    return f


def _feasible(facts, pr, cond, taken):
    if pr is None:
        return True
    P = _poss(facts, pr, cond); T = _truth(cond)
    return bool(P & T) if taken else bool(P - T)


def _kill(facts, names):
    return {k: v for k, v in facts.items() if k[0] not in names and k[1] not in names}


def _merge_facts(x, y):
    return {k: x[k] | y[k] for k in x.keys() & y.keys()}


def _val(func, D, x):
    """Constant value of operand x if a single definition of it reaches this node and is `mov r, imm`."""
    if isinstance(x, int):
        return x
    ds = [d for d in D if d[1] == x]
    if len(ds) == 1 and ds[0][0] >= 0:
        i = func.code[ds[0][0]]
        if i.op == "mov" and isinstance(i.a, int):
            return i.a
    return None


def static_analysis(func):
    """-> (rd, live_edges).  rd[p][r] = definitions of r reaching p along at least one path feasible under
    their own facts; live_edges = CFG edges along which anything propagates (others are statically dead)."""
    live = set()
    IN = {0: ({}, {(-1, r): {} for r in func.regs})}       # node -> (global facts G, {def: facts})
    work = [0]

    def push(s, G, D, frm=None):
        if frm is not None:
            live.add((frm, s))
        if s not in IN:
            IN[s] = (G, D); work.append(s); return
        G0, D0 = IN[s]
        G1 = _merge_facts(G0, G)
        D1 = dict(D0)
        for d, f in D.items():
            D1[d] = _merge_facts(D0[d], f) if d in D0 else f
        if G1 != G0 or D1 != D0:
            IN[s] = (G1, D1); work.append(s)

    while work:
        p = work.pop()
        G, D = IN[p]
        i = func.code[p]
        if i.op in ("br", "jcc"):
            pr, cond = _pair_and_cond(func, p)
            if pr is not None:                                   # constant propagation of single-def operands
                v = [_val(func, D, x) for x in pr]
                if all(x is not None for x in v):
                    pr = tuple(v)
            for s, taken in ((i.tgt, True), (p + 1, False)):
                if s == p + 1 and i.tgt == p + 1 and not taken:
                    continue
                if not _feasible(G, pr, cond, taken) and pr is not None:
                    continue
                G2 = _narrow(G, pr, cond, taken) if pr is not None else G
                D2 = {d: (_narrow(f, pr, cond, taken) if pr is not None else f)
                      for d, f in D.items() if _feasible(f, pr, cond, taken)}
                push(s, G2, D2, p)
            continue
        if i.op == "ret":
            continue
        defs = func.defs(p)
        G2 = _kill(G, defs)
        D2 = {d: _kill(f, defs) for d, f in D.items() if d[1] not in defs}
        for r in defs:
            D2[(p, r)] = dict(G2)                          # a new definition inherits the facts valid here
        push(i.tgt if i.op == "jmp" else p + 1, G2, D2, p)
    rd = {}
    for p, (G, D) in IN.items():
        m = {}
        for (q, r) in D:
            m.setdefault(r, set()).add((q, r))
        rd[p] = {r: frozenset(ds) for r, ds in m.items()}
    return rd, live


def static_rd(func):
    return static_analysis(func)[0]


def eliminated_pairs(rd_static, rd_ps, pairs):
    """Pairs (site, d) that the path-sensitive analysis removes from the static reaching sets."""
    return {(s, d) for s, d in pairs if d not in rd_ps.get(s[0], {}).get(s[1], EMPTY)}
