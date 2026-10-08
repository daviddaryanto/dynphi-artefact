# Copyright (c) 2026 David Daryanto
# SPDX-License-Identifier: Apache-2.0
"""Tiny register IR (extended with nop, cmp/jcc through a FLAGS location, shifts) and concrete interpreter used by the Dyn-Phi reference implementation.

Program points are instruction indices.  Registers are strings.  An instruction whose
effects are not modelled is ``havoc`` and gets Def = Use = R (Assumption 1 of the paper).
"""
from dataclasses import dataclass
from typing import Optional, Union

MASK = 0xFFFFFFFF
CMP = {"==": lambda x, y: x == y, "!=": lambda x, y: x != y,
       "<": lambda x, y: x < y, "<=": lambda x, y: x <= y,
       ">": lambda x, y: x > y, ">=": lambda x, y: x >= y}
BIN = {"+": lambda x, y: (x + y) & MASK, "-": lambda x, y: (x - y) & MASK,
       "*": lambda x, y: (x * y) & MASK, "&": lambda x, y: x & y,
       "|": lambda x, y: x | y, "^": lambda x, y: x ^ y,
       "<<": lambda x, y: (x << (y & 31)) & MASK, ">>": lambda x, y: x >> (y & 31)}


def _s32(x):
    return x - (1 << 32) if x & 0x80000000 else x


# conditions of x86 jcc on flags = (lhs, rhs) as set by `cmp rhs, lhs` (AT&T: cmp src,dst => dst ? src)
JCC = {"e": lambda a, b: a == b, "ne": lambda a, b: a != b,
       "a": lambda a, b: a > b, "ae": lambda a, b: a >= b, "b": lambda a, b: a < b, "be": lambda a, b: a <= b,
       "g": lambda a, b: _s32(a) > _s32(b), "ge": lambda a, b: _s32(a) >= _s32(b),
       "l": lambda a, b: _s32(a) < _s32(b), "le": lambda a, b: _s32(a) <= _s32(b)}
Operand = Union[str, int]


@dataclass(frozen=True)
class Ins:
    op: str                       # mov | bin | br | jmp | ret | havoc | nop | cmp | jcc
    dst: Optional[str] = None
    a: Optional[Operand] = None
    b: Optional[Operand] = None
    f: Optional[str] = None       # operator for bin / br
    tgt: Optional[int] = None     # branch / jump target


class Func:
    def __init__(self, code, inputs=("a", "b")):
        self.code = list(code)
        self.inputs = tuple(inputs)
        regs = set(inputs)
        if any(i.op in ("cmp", "jcc") for i in self.code):
            regs.add("flags")
        for i in self.code:
            for x in (i.dst, i.a, i.b):
                if isinstance(x, str):
                    regs.add(x)
        self.regs = tuple(sorted(regs))
        allr = frozenset(self.regs)
        self._defs, self._uses, self._succ = [], [], []
        n = len(self.code)
        for p, i in enumerate(self.code):
            if i.op == "havoc":
                self._defs.append(allr); self._uses.append(allr)
            elif i.op == "cmp":
                self._defs.append(frozenset(["flags"]))
                self._uses.append(frozenset(x for x in (i.a, i.b) if isinstance(x, str)))
            elif i.op == "jcc":
                self._defs.append(frozenset()); self._uses.append(frozenset(["flags"]))
            else:
                self._defs.append(frozenset([i.dst]) if i.op in ("mov", "bin") else frozenset())
                self._uses.append(frozenset(x for x in (i.a, i.b) if isinstance(x, str)))
            if i.op in ("br", "jcc"):
                s = (i.tgt,) if i.tgt == p + 1 else (i.tgt, p + 1)
            elif i.op == "jmp":
                s = (i.tgt,)
            elif i.op == "ret":
                s = ()
            else:
                s = (p + 1,)
            assert all(0 <= t < n for t in s), f"bad successor at {p}"
            self._succ.append(s)

    def __len__(self):
        return len(self.code)

    def defs(self, p): return self._defs[p]
    def uses(self, p): return self._uses[p]
    def succ(self, p): return self._succ[p]


def run(func, args, lmax=400, step=None, regs=None):
    """Concrete execution. Returns (trace of program points, completed?, return value)."""
    regs = regs if regs is not None else {}
    regs.update({r: 0 for r in func.regs})
    regs.update(zip(func.inputs, args))
    val = lambda x: regs[x] if isinstance(x, str) else x
    p, trace = 0, []
    while len(trace) < lmax:
        if step is not None:
            step(p, regs)
        trace.append(p)
        i = func.code[p]
        if i.op == "mov":
            regs[i.dst] = val(i.a); p += 1
        elif i.op == "bin":
            regs[i.dst] = BIN[i.f](val(i.a), val(i.b)); p += 1
        elif i.op == "br":
            p = i.tgt if CMP[i.f](val(i.a), val(i.b)) else p + 1
        elif i.op == "cmp":
            a, b = val(i.a), val(i.b)
            regs["flags"] = (a & b, 0) if i.f == "test" else (a, b)
            p += 1
        elif i.op == "jcc":
            p = i.tgt if JCC[i.f](*regs["flags"]) else p + 1
        elif i.op == "nop":
            p += 1
        elif i.op == "jmp":
            p = i.tgt
        elif i.op == "ret":
            return trace, True, val(i.a)
        elif i.op == "havoc":
            for r in regs:
                regs[r] = (regs[r] * 0x9E3779B1 + 12345) & MASK
            p += 1
        else:
            raise ValueError(i.op)
    return trace, False, None
