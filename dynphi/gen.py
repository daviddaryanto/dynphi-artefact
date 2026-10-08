# Copyright (c) 2026 David Daryanto
# SPDX-License-Identifier: Apache-2.0
"""Random function generator with by-construction annotations.

Pieces: genuine diamond, opaque-predicate diamond (dead arm known by construction),
rare-trigger diamond (live but rare), counted loop, 'flowdead' (definition reachable but
unable to reach its use) and unmodelled ``havoc`` instructions.
"""
import random
from .ir import Ins, Func

KINDS = ["assign", "genuine", "opaque", "rare", "loop", "flowdead", "havoc", "contextual"]
WEIGHTS = [0.10, 0.22, 0.28, 0.15, 0.10, 0.10, 0.05, 0.0]       # profile "basic" (original corpus)
WEIGHTS_RICH = [0.08, 0.18, 0.20, 0.12, 0.08, 0.08, 0.04, 0.22]  # profile "rich"
P_GUARD_RICH = 0.4          # probability that a piece is skipped by a data-dependent guard (varies M)


def _assemble(items):
    labels, code, tags = {}, [], []
    for it in items:
        if it[0] == "label":
            labels[it[1]] = len(code)
        else:
            code.append(it[1]); tags.append(it[2])
    out = []
    for i in code:
        out.append(Ins(i.op, i.dst, i.a, i.b, i.f, labels[i.tgt] if isinstance(i.tgt, str) else i.tgt))
    return out, tags


def gen_function(seed, n_pieces=None, profile="basic"):
    """profile 'basic': original corpus.  profile 'rich': adds contextual (correlated-branch)
    pieces, in which every CFG edge is exercised yet one definition can never reach its use,
    and guards that make join sites visited by only a fraction of executions (M varies)."""
    weights = WEIGHTS_RICH if profile == "rich" else WEIGHTS
    rng = random.Random(seed)
    items, nl = [], [0]
    emit = lambda i, tag="": items.append(("ins", i, tag))
    label = lambda n: items.append(("label", n))
    def L():
        nl[0] += 1; return f"L{nl[0]}"
    D = 32
    regs = ["r0", "r1", "r2", "r3"]
    emit(Ins("mov", "s", 0))
    for _ in range(n_pieces or rng.randint(4, 9)):
        kind = rng.choices(KINDS, weights)[0]
        rk, x = rng.choice(regs), rng.choice(["a", "b"])
        acc = lambda: emit(Ins("bin", "s", "s", rk, "+"))
        lskip = None
        if profile == "rich" and rng.random() < P_GUARD_RICH:
            lskip = L()
            emit(Ins("br", None, rng.choice(["a", "b"]), rng.randrange(4, 28), ">=", lskip))
        if kind == "assign":
            emit(Ins("mov", rk, rng.randrange(1, 100))); acc()
        elif kind == "genuine":
            lt, le = L(), L()
            emit(Ins("br", None, x, rng.randrange(6, D - 6), "<", lt))
            emit(Ins("mov", rk, rng.randrange(1, 100))); emit(Ins("jmp", tgt=le))
            label(lt); emit(Ins("mov", rk, rng.randrange(100, 200)))
            label(le); acc()
        elif kind == "opaque":
            v = rng.choice(["eq_self", "even_prod", "or1", "self_sub"])
            if v == "eq_self":
                f, a, b = "==", x, x
            elif v == "even_prod":
                emit(Ins("bin", "t", x, 1, "+")); emit(Ins("bin", "t", "t", x, "*")); emit(Ins("bin", "t", "t", 1, "&"))
                f, a, b = "==", "t", 0
            elif v == "or1":
                emit(Ins("bin", "t", x, 1, "|")); emit(Ins("bin", "t", "t", 1, "&"))
                f, a, b = "==", "t", 1
            else:
                emit(Ins("bin", "t", x, x, "-")); f, a, b = "==", "t", 0
            invert = rng.random() < 0.5                  # '!=' makes the THEN arm dead
            if invert:
                f = {"==": "!="}[f]
            lt, le = L(), L()
            emit(Ins("br", None, a, b, f, lt))
            tag_else = "dead" if not invert else ""
            tag_then = "dead" if invert else ""
            emit(Ins("mov", "t2", rng.randrange(1, 9)), tag_else)
            emit(Ins("mov", rk, rng.randrange(1, 100)), tag_else); emit(Ins("jmp", tgt=le), tag_else)
            label(lt)
            emit(Ins("mov", "t2", rng.randrange(1, 9)), tag_then)
            emit(Ins("mov", rk, rng.randrange(100, 200)), tag_then)
            label(le); acc()
        elif kind == "rare":
            lt, le = L(), L()
            emit(Ins("br", None, "a", rng.randrange(D), "!=", le))
            if rng.random() < 0.5:
                emit(Ins("br", None, "b", rng.randrange(D), "!=", le))
            emit(Ins("mov", rk, rng.randrange(100, 200))); emit(Ins("jmp", tgt=lt))
            label(le); emit(Ins("mov", rk, rng.randrange(1, 100)))
            label(lt); acc()
        elif kind == "loop":
            lh = L()
            emit(Ins("mov", "i", 0))
            label(lh); emit(Ins("bin", "i", "i", 1, "+")); emit(Ins("bin", "s", "s", "i", "+"))
            emit(Ins("br", None, "i", rng.randrange(2, 7), "<", lh))
        elif kind == "flowdead":
            lq, lo, lu, lj = L(), L(), L(), L()
            emit(Ins("mov", rk, 1))
            emit(Ins("br", None, "a", rng.randrange(8, 24), "<", lq))
            emit(Ins("jmp", tgt=lu))
            label(lq); emit(Ins("mov", rk, 2)); emit(Ins("mov", "t", 0))
            emit(Ins("br", None, "t", 0, "==", lo))
            emit(Ins("jmp", tgt=lu), "dead")
            label(lo); emit(Ins("mov", rk, 9))
            label(lu); acc()
        elif kind == "contextual":
            # same predicate tested twice: r:=2 executes iff x<c, and then r:=9 overwrites it.
            # Every edge is taken by some input, but the definition r:=2 never reaches the use.
            c, l1, l2, l3, l4 = rng.randrange(8, 24), L(), L(), L(), L()
            emit(Ins("mov", rk, 1))
            emit(Ins("br", None, x, c, "<", l1)); emit(Ins("jmp", tgt=l2))
            label(l1); emit(Ins("mov", rk, 2))
            label(l2); emit(Ins("br", None, x, c, "<", l3)); emit(Ins("jmp", tgt=l4))
            label(l3); emit(Ins("mov", rk, 9))
            label(l4); acc()
        else:
            emit(Ins("havoc"))
        if lskip:
            label(lskip)
    emit(Ins("ret", None, "s"))
    code, tags = _assemble(items)
    f = Func(code)
    f.construction_dead = {p for p, t in enumerate(tags) if t == "dead"}
    f.seed = seed
    return f
