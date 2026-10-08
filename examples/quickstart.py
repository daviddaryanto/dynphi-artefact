# Copyright (c) 2026 David Daryanto
# SPDX-License-Identifier: Apache-2.0
"""Quickstart: Example A of the paper (an opaque predicate), end to end.

Run from the repository root:  python examples/quickstart.py
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))  # works without installation

from dynphi.cfg import reaching_defs, rd_of
from dynphi.core import Evidence, build, collect, triage
from dynphi.ir import Func, Ins, run
from dynphi.oracle import ExactVerifier, Oracle

I = Ins
# b0: r1 := 17; r2 := 17; if r1 == r2 goto b2   (always taken)
# b1: r0 := 0xDEAD            (dead arm, point 3)
# b2: r0 := 0xC0DE; ret r0    (live arm, point 5; the use is at point 6)
f = Func([I("mov", "r1", 17), I("mov", "r2", 17), I("br", None, "r1", "r2", "==", 5),
          I("mov", "r0", 0xDEAD), I("jmp", tgt=6), I("mov", "r0", 0xC0DE), I("ret", None, "r0")],
         inputs=("a",))

rd = reaching_defs(f)
print("static reaching definitions of r0 at the return:", sorted(rd_of(rd, 6, "r0")))

ev = Evidence()                                    # Algorithm 1: fold 30 traces into counters
for a in range(30):
    collect(f, rd, run(f, (a,))[0], ev)

nodes, cands = build(rd, ev, delta=0.05, theta=0.1)  # Algorithm 2: dyn-phi nodes and cold candidates
node = nodes[(6, "r0")]
print("tag (definition -> times observed):", node.tag, "| traces M =", node.M)
for u, site, d in cands:
    print(f"cold candidate {d} at use {site}, zero-hit bound u = {u:.3f}")

verifier = ExactVerifier(Oracle(f, 32))            # exact on the finite input domain [0, 32)
res = triage(f, rd, ev, verifier, delta=0.05, theta=0.1)   # Algorithm 3
print("points proved unreachable:", sorted(res.K), "| verifier queries:", res.queries)
