# Copyright (c) 2026 David Daryanto
# SPDX-License-Identifier: Apache-2.0
"""Baselines used in the evaluation (all use the same verifier and the same query accounting)."""
from .cfg import reaching_defs, rd_of
from .core import build, resolve


def cold_filter(rd, ev, delta=0.05):
    """Cold definitions in ADDRESS order: no score, no feedback (the 'filter-only' control)."""
    _, cands = build(rd, ev, delta, 1.0)
    return sorted(((s, d) for _, s, d in cands))


def resolve_list(V, order):
    """Query ``order`` one by one.  Returns (log [(cum_queries, (site,d), found?)], found set)."""
    q0, log, found = V.n_queries, [], set()
    for s, d in order:
        out, _ = resolve(V, d, s)
        hit = out in ("DEADCODE", "DEADPAIR")
        if hit:
            found.add((s, d))
        log.append((V.n_queries - q0, (s, d), hit))
    return log, found


def edge_coverage(func, rd, observed_edges, V, base_succ=None):
    """Edge-coverage control: a conditional edge out of a visited branch that no trace took is
    queried for feasibility; infeasible edges are deleted and RD is recomputed on the pruned CFG.
    Needs no definition counters, no nodes and no score.  Returns (rd_pruned, #cold edges, #dead edges)."""
    visited = {p for p, _ in observed_edges}
    succ = base_succ or {p: func.succ(p) for p in range(len(func))}
    q0 = V.n_queries
    dead_edges, n_cold = set(), 0
    for p in sorted(visited):
        if func.code[p].op not in ("br", "jcc"):
            continue
        for s in succ[p]:
            if (p, s) in observed_edges:
                continue
            n_cold += 1
            if V.edge(p, s)[0] == "INFEASIBLE":
                dead_edges.add((p, s))
    succ2 = {p: tuple(s for s in ss if (p, s) not in dead_edges) for p, ss in succ.items()}
    return reaching_defs(func, succ2), V.n_queries - q0, len(dead_edges)


def eliminated(dead_pairs, rd_pruned):
    """Dead pairs that no longer appear in the pruned reaching sets."""
    return {(s, d) for s, d in dead_pairs if d not in rd_of(rd_pruned, s[0], s[1])}
