# Copyright (c) 2026 David Daryanto
# SPDX-License-Identifier: Apache-2.0
"""Static reaching definitions (iterative worklist) over the CFG of a Func."""
EMPTY = frozenset()


def entry_def(r):
    return (-1, r)           # entry pseudo-definition d_0^r (site -1)


def reaching_defs(func, succ=None):
    """rd[p][r] = frozenset of definitions of r that reach the *entry* of p.

    ``succ`` optionally overrides the CFG edges (pruned or deliberately incomplete CFGs).
    Points unreachable from the entry get no entry in ``rd``.
    """
    n = len(func)
    succ = succ if succ is not None else {p: func.succ(p) for p in range(n)}
    IN = {0: {r: {entry_def(r)} for r in func.regs}}
    work = [0]
    while work:
        p = work.pop()
        out = {r: set(ds) for r, ds in IN[p].items()}
        for r in func.defs(p):
            out[r] = {(p, r)}
        for s in succ[p]:
            first = s not in IN
            tgt = IN.setdefault(s, {})
            changed = first
            for r, ds in out.items():
                cur = tgt.setdefault(r, set())
                if not ds <= cur:
                    cur |= ds
                    changed = True
            if changed:
                work.append(s)
    return {p: {r: frozenset(ds) for r, ds in m.items()} for p, m in IN.items()}


def rd_of(rd, p, r):
    return rd.get(p, {}).get(r, EMPTY)
