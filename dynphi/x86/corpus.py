# Copyright (c) 2026 David Daryanto
# SPDX-License-Identifier: Apache-2.0
"""Corpora C3 and C4: generated C sources, the objdump listing of their gcc output, and lifted functions.

The repository COMMITS the sources and the x86-64 listings (dynphi/x86/data), so the evaluation is
reproducible on any host, including non-x86 machines (for example ARM phones and Apple silicon),
where a local gcc would emit a different instruction set.  Only the native-execution tests and the
regeneration command need an x86-64 host with gcc and binutils:

    python -m dynphi.x86.build_corpus          # regenerates dynphi/x86/data from the generator
"""
import hashlib
import json
import os
import platform
import shutil
import subprocess
import tempfile

from .cgen import gen_c
from .lift import parse_objdump, lift, objdump

DATA = os.path.join(os.path.dirname(os.path.abspath(__file__)), "data")
SPECS = {
    "c3": dict(seed=9000, n=200, clean_frac=0.0, wide=False),
    "c4": dict(seed=12000, n=200, clean_frac=0.5, wide=True),
}
GCC_FLAGS = ["-O0", "-fno-asynchronous-unwind-tables", "-fcf-protection=none", "-fno-pie", "-fno-stack-protector"]


def host_can_build():
    """True on an x86-64 host that has gcc and objdump (needed to regenerate data or run native tests)."""
    return (platform.machine().lower() in ("x86_64", "amd64")
            and shutil.which("gcc") is not None and shutil.which("objdump") is not None)


def sources(name):
    """Ordered {function name: C source} for corpus `name`, produced by the generator."""
    s = SPECS[name]
    n_obf = s["n"] - int(round(s["n"] * s["clean_frac"]))
    return {f"f{i}": gen_c(f"f{i}", s["seed"] + i, clean=(i >= n_obf), wide=s["wide"]) for i in range(s["n"])}


def source_path(name):
    return os.path.join(DATA, f"{name}.c")


def listing_path(name):
    return os.path.join(DATA, f"{name}.objdump.txt")


def sha256_file(path):
    with open(path, "rb") as fh:
        return hashlib.sha256(fh.read()).hexdigest()


def load_corpus(name, n=None):
    """Lift the committed objdump listing of corpus `name` ('c3' or 'c4'); first `n` functions."""
    s = SPECS[name]
    n_obf = s["n"] - int(round(s["n"] * s["clean_frac"]))
    with open(listing_path(name)) as fh:
        listing = parse_objdump(fh.read())
    out = []
    for i in range(n if n is not None else s["n"]):
        fn = f"f{i}"
        f = lift(listing[fn])                 # raises Reject loudly if an instruction is outside the supported subset
        f.lmax = 4000
        f.clean = i >= n_obf
        f.name, f.asm, f.seed = fn, listing[fn], s["seed"] + i
        out.append(f)
    return out


def build(name, outdir=DATA):
    """Regenerate sources and listing for `name` (x86-64 host with gcc and objdump only)."""
    if not host_can_build():
        raise RuntimeError("regeneration needs an x86-64 host with gcc and objdump; "
                           f"this host is {platform.machine()}. The committed data can be used on any host.")
    os.makedirs(outdir, exist_ok=True)
    srcs = sources(name)
    c_path = os.path.join(outdir, f"{name}.c")
    with open(c_path, "w") as fh:
        fh.write("\n\n".join(srcs.values()) + "\n")
    with tempfile.TemporaryDirectory() as td:
        obj = os.path.join(td, f"{name}.o")
        subprocess.run(["gcc"] + GCC_FLAGS + ["-c", c_path, "-o", obj], check=True)
        with open(os.path.join(outdir, f"{name}.objdump.txt"), "w") as fh:
            fh.write(objdump(obj))
    return c_path


def write_manifest(outdir=DATA):
    gcc = subprocess.run(["gcc", "--version"], capture_output=True, text=True).stdout.splitlines()[0]
    od = subprocess.run(["objdump", "--version"], capture_output=True, text=True).stdout.splitlines()[0]
    m = {"gcc": gcc, "objdump": od, "gcc_flags": GCC_FLAGS, "specs": SPECS,
         "sha256": {f: sha256_file(os.path.join(outdir, f)) for f in sorted(os.listdir(outdir)) if f != "MANIFEST.json"}}
    with open(os.path.join(outdir, "MANIFEST.json"), "w") as fh:
        json.dump(m, fh, indent=1)
    return m
