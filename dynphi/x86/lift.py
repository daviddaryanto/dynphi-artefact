# Copyright (c) 2026 David Daryanto
# SPDX-License-Identifier: Apache-2.0
"""Lift gcc-generated x86-64 (AT&T, from objdump) to the Dyn-Phi IR.

One machine instruction = one IR instruction = one program point.  Constant-offset stack slots
(`disp(%rbp)`) become named locations, so values that gcc -O0 keeps in memory are tracked exactly
like registers; FLAGS is a location written by cmp/test and read by jcc.  Only the 32-bit integer
subset gcc emits at -O0 for the generated sources is accepted; any other instruction rejects the
function (never silently mis-lifts).  Correctness is checked against native execution (tests)."""
import re, subprocess
from ..ir import Ins, Func

REG = {}
for base in ("ax", "bx", "cx", "dx", "si", "di", "bp", "sp"):
    for pre, suf in (("e", ""), ("r", ""), ("", "")):
        REG[pre + base] = "r" + base
for n, lo in (("al", "ax"), ("cl", "cx"), ("dl", "dx"), ("bl", "bx")):
    REG[n] = "r" + lo
for i in range(8, 16):
    for suf in ("", "d", "w", "b"):
        REG[f"r{i}{suf}"] = f"r{i}"
BIN2 = {"add": "+", "sub": "-", "imul": "*", "and": "&", "or": "|", "xor": "^", "shl": "<<", "shr": ">>", "sal": "<<"}
JCC = {"je": "e", "jz": "e", "jne": "ne", "jnz": "ne", "ja": "a", "jnbe": "a", "jae": "ae", "jnb": "ae",
       "jb": "b", "jnae": "b", "jbe": "be", "jna": "be", "jg": "g", "jnle": "g", "jge": "ge", "jnl": "ge",
       "jl": "l", "jnge": "l", "jle": "le", "jng": "le"}
NOPS = {"push", "pop", "leave", "nop", "nopw", "nopl", "endbr64", "cs", "xchg", "data16"}


class Reject(Exception):
    pass


def operand(tok):
    tok = tok.strip()
    if tok.startswith("$"):
        return int(tok[1:], 0) & 0xFFFFFFFF
    if tok.startswith("%"):
        r = REG.get(tok[1:])
        if r is None:
            raise Reject(tok)
        return r
    m = re.fullmatch(r"(-?0x[0-9a-f]+|-?\d+)?\(%rbp\)", tok)
    if m:
        off = int(m.group(1), 0) if m.group(1) else 0
        return f"m{off}"
    raise Reject(tok)


def split_ops(s):
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch == "(": depth += 1
        if ch == ")": depth -= 1
        if ch == "," and depth == 0:
            out.append(cur); cur = ""
        else:
            cur += ch
    return out + ([cur] if cur.strip() else [])


def parse_objdump(text):
    """-> {name: [(addr, mnemonic, operand-string)]}"""
    funcs, cur = {}, None
    m = re.search(r"file format (\S+)", text)
    if m and "x86-64" not in m.group(1):
        raise Reject(f"unsupported architecture {m.group(1)}: the lifter handles x86-64 listings only "
                     "(use the committed listings in dynphi/x86/data on non-x86 hosts)")
    for ln in text.splitlines():
        m = re.match(r"^[0-9a-f]+ <(\w+)>:", ln)
        if m:
            cur = funcs.setdefault(m.group(1), []); continue
        m = re.match(r"^\s*([0-9a-f]+):\s+(\S+)\s*(.*)$", ln)
        if m and cur is not None:
            ops = re.sub(r"\s*<.*>$", "", m.group(3)).split("#")[0].strip()
            cur.append((int(m.group(1), 16), m.group(2), ops))
    for k, v in funcs.items():                       # drop alignment padding after the final ret
        last = max((i for i, x in enumerate(v) if x[1] == "ret"), default=len(v) - 1)
        funcs[k] = v[:last + 1]
    return funcs


def lift(insns, inputs=("rdi", "rsi")):
    addr2pc = {a: i for i, (a, _, _) in enumerate(insns)}
    code = []
    for a, mn, ops in insns:
        base = re.sub(r"[bwlq]$", "", mn) if mn not in ("sal", "shl", "shr", "sub", "imul", "add", "and", "or", "xor") else mn
        if mn in NOPS or (mn == "mov" and ops == "%rsp,%rbp"):
            code.append(Ins("nop")); continue
        if mn == "ret":
            code.append(Ins("ret", None, "rax")); continue
        if mn in ("jmp",) or mn in JCC:
            tgt = int(ops.split()[0], 16)
            if tgt not in addr2pc: raise Reject(f"external jump {ops}")
            code.append(Ins("jmp", tgt=addr2pc[tgt]) if mn == "jmp" else Ins("jcc", f=JCC[mn], tgt=addr2pc[tgt]))
            continue
        o = split_ops(ops)
        core = mn
        if core.startswith(("mov", "cmp", "test", "add", "sub", "and", "or", "xor", "imul", "shl", "shr", "sal", "not", "neg")) and core[-1] in "lq" and core not in ("movl_",):
            # AT&T size suffix on immediate/memory forms (movl, cmpl, addl ...)
            core = core[:-1] if core[:-1] in ("mov", "cmp", "test", "add", "sub", "and", "or", "xor", "imul", "shl", "shr", "sal", "not", "neg") else core
        if core == "mov":
            code.append(Ins("mov", operand(o[1]), operand(o[0])))
        elif core in BIN2 and len(o) == 2:
            dst = operand(o[1])
            code.append(Ins("bin", dst, dst, operand(o[0]), BIN2[core]))
        elif core == "imul" and len(o) == 3:
            code.append(Ins("bin", operand(o[2]), operand(o[1]), operand(o[0]), "*"))
        elif core in BIN2 and len(o) == 1:           # shift by one: `shl %eax`
            dst = operand(o[0]); code.append(Ins("bin", dst, dst, 1, BIN2[core]))
        elif core == "not" and len(o) == 1:
            dst = operand(o[0]); code.append(Ins("bin", dst, dst, 0xFFFFFFFF, "^"))
        elif core == "neg" and len(o) == 1:
            dst = operand(o[0]); code.append(Ins("bin", dst, 0, dst, "-"))
        elif core == "cmp":
            code.append(Ins("cmp", None, operand(o[1]), operand(o[0])))
        elif core == "test":
            code.append(Ins("cmp", None, operand(o[1]), operand(o[0]), "test"))
        else:
            raise Reject(f"{mn} {ops}")
    return Func(code, inputs=inputs)


def objdump(obj_path):
    return subprocess.run(["objdump", "-d", "--no-show-raw-insn", "-M", "att", obj_path],
                          capture_output=True, text=True, check=True).stdout
