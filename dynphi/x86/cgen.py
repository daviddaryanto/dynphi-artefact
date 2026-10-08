# Copyright (c) 2026 David Daryanto
# SPDX-License-Identifier: Apache-2.0
"""Generator of C functions `unsigned f(unsigned a, unsigned b)` with opaque predicates,
rare-trigger branches, loops, correlated (contextual) branches and guards.  Predicates are chosen
so that gcc -O0 does not constant-fold them (verified in the tests); ground truth always comes
from the oracle on the lifted machine code, not from the source."""
import random

# always-true predicates over unsigned a, b (x = a or b)
OPAQUE = [
    "((X * (X + 1u)) & 1u) == 0u",         # product of consecutive integers is even
    "((X * X) & 3u) != 2u",                # squares mod 4 are 0 or 1
    "((X | Y) >= X)",
    "((X & Y) <= Y)",
]
# extra families used by corpus C4 (kept only if gcc -O0 does not fold them: see tests)
OPAQUE_V2 = [
    "((X * X * X - X) & 1u) == 0u",        # (x-1)x(x+1) is even
    "((((X | Y) ^ Y) & Y) == 0u)",
]


def gen_c(name, seed, n_pieces=None, guard_p=0.4, clean=False, wide=False):
    """clean=True: no opaque / contextual pieces (a function with no dead pair by construction).
    wide=True: more predicate families and a second, syntactically different correlated test."""
    rng = random.Random(seed)
    L = ["unsigned %s(unsigned a, unsigned b) {" % name, "  unsigned s = 0u, r0 = 0u, r1 = 0u, r2 = 0u, r3 = 0u, i = 0u;"]
    kinds = ["assign", "genuine", "opaque", "rare", "loop", "contextual"]
    w = [0.08, 0.18, 0.30, 0.14, 0.08, 0.22]
    if clean:
        w = [0.15, 0.40, 0.0, 0.25, 0.20, 0.0]
    opq = OPAQUE + (OPAQUE_V2 if wide else [])
    for _ in range(n_pieces or rng.randint(4, 8)):
        k = rng.choices(kinds, w)[0]
        x = rng.choice("ab"); y = "b" if x == "a" else "a"; r = rng.choice(["r0", "r1", "r2", "r3"])
        pad = "  "
        guard = rng.random() < guard_p
        if guard:
            L.append(f"  if ({rng.choice('ab')} < {rng.randrange(4, 28)}u) {{")
        if k == "assign":
            L.append(f"  {r} = {rng.randrange(1, 100)}u;")
        elif k == "genuine":
            L.append(f"  if ({x} < {rng.randrange(6, 26)}u) {r} = {rng.randrange(1, 100)}u; else {r} = {rng.randrange(100, 200)}u;")
        elif k == "opaque":
            p = rng.choice(opq).replace("X", x).replace("Y", y)
            if rng.random() < 0.5:
                L.append(f"  if ({p}) {r} = {rng.randrange(100, 200)}u; else {r} = {rng.randrange(1, 100)}u;")
            else:
                L.append(f"  if (!({p})) {r} = {rng.randrange(1, 100)}u; else {r} = {rng.randrange(100, 200)}u;")
        elif k == "rare":
            c = f"a == {rng.randrange(32)}u" + (f" && b == {rng.randrange(32)}u" if rng.random() < 0.5 else "")
            L.append(f"  if ({c}) {r} = {rng.randrange(100, 200)}u; else {r} = {rng.randrange(1, 100)}u;")
        elif k == "loop":
            L.append(f"  i = 0u; do {{ i = i + 1u; s = s + i; }} while (i < {rng.randrange(2, 7)}u);")
        else:
            c = rng.randrange(8, 24)
            c2 = f"{x} <= {c - 1}u" if (wide and rng.random() < 0.5) else f"{x} < {c}u"   # same truth value, different constant
            L.append(f"  {r} = 1u; if ({x} < {c}u) {r} = 2u; if ({c2}) {r} = 9u;")
        if k != "loop":
            L.append(f"  s += {r};")
        if guard:
            L.append("  }")
    L += ["  return s;", "}"]
    return "\n".join(L)
