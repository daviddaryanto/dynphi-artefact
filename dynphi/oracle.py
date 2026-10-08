# Copyright (c) 2026 David Daryanto
# SPDX-License-Identifier: Apache-2.0
"""Exhaustive oracle over a finite input domain + verifier wrappers."""
import itertools, random
from collections import Counter
from .core import INF, UNK, FEAS
from .ir import run


class Oracle:
    """Exact reach/flow tables over all inputs in range(domain)^k (or an explicit subset)."""
    def __init__(self, func, domain, lmax=400, inputs=None):
        self.func, self.domain, self.lmax = func, domain, lmax
        self.reach_w, self.flow_w, self.edge_w = {}, {}, {}
        self.visit_inputs, self.flow_inputs = Counter(), Counter()
        self.truncated, self.n_inputs = False, 0
        it = inputs if inputs is not None else itertools.product(range(domain), repeat=len(func.inputs))
        for args in it:
            self.n_inputs += 1
            trace, done, _ = run(func, args, lmax)
            self.truncated |= not done
            lam = {r: (-1, r) for r in func.regs}
            sites, flows = set(), set()
            for i, p in enumerate(trace):
                self.reach_w.setdefault(p, args)
                if i + 1 < len(trace):
                    self.edge_w.setdefault((p, trace[i + 1]), args)
                for r in func.uses(p):
                    site, d = (p, r), lam[r]
                    sites.add(site); flows.add((d, site))
                    self.flow_w.setdefault((d, site), args)
                for r in func.defs(p):
                    lam[r] = (p, r)
            self.visit_inputs.update(sites)
            self.flow_inputs.update(flows)

    def q(self, d, site):
        """Exact probability that d reaches the use at least once, given the trace visits it."""
        v = self.visit_inputs.get(site, 0)
        return self.flow_inputs.get((d, site), 0) / v if v else 0.0


class ExactVerifier:
    """Sound (and, on the finite domain, complete) three-valued verifier."""
    def __init__(self, oracle):
        self.o, self.n_queries, self._cache = oracle, 0, {}
        self.verdicts = Counter()

    @property
    def lmax(self): return self.o.lmax

    def _ask(self, key, table, k):
        if key in self._cache:                      # repeated queries are answered from the cache
            return self._cache[key]
        self.n_queries += 1                         # n_queries counts DISTINCT queries
        w = table.get(k)
        v = FEAS(w) if w is not None else (UNK if self.o.truncated else INF)
        self._cache[key] = v
        self.verdicts[v[0]] += 1
        return v

    def reach(self, q): return self._ask(("r", q), self.o.reach_w, q)
    def flow(self, d, site): return self._ask(("f", d, site), self.o.flow_w, (d, site))
    def edge(self, p, s): return self._ask(("e", p, s), self.o.edge_w, (p, s))


class LossyVerifier:
    """Sound but incomplete: answers UNKNOWN with probability p (timeouts)."""
    def __init__(self, base, p_unknown, seed=0):
        self.b, self.p, self.rng = base, p_unknown, random.Random(seed)
    @property
    def n_queries(self): return self.b.n_queries
    @property
    def lmax(self): return self.b.lmax
    def _gate(self, f, *a):
        v = f(*a)
        return UNK if self.rng.random() < self.p and v[0] == "INFEASIBLE" else v
    def reach(self, q): return self._gate(self.b.reach, q)
    def flow(self, d, site): return self._gate(self.b.flow, d, site)


class SampledVerifier:
    """UNSOUND by design: a path-limited search that answers INFEASIBLE when it merely
    fails to find a witness among k sampled inputs (the behaviour Section IV forbids)."""
    def __init__(self, func, domain, k=16, seed=0):
        rng = random.Random(seed)
        ins = [tuple(rng.randrange(domain) for _ in func.inputs) for _ in range(k)]
        self.o, self.n_queries, self._cache = Oracle(func, domain, lmax=getattr(func, "lmax", 400), inputs=ins), 0, {}
        self.verdicts = Counter()
    lmax = ExactVerifier.lmax
    _ask = ExactVerifier._ask
    reach = ExactVerifier.reach
    flow = ExactVerifier.flow
    edge = ExactVerifier.edge
