# Copyright (c) 2026 David Daryanto
# SPDX-License-Identifier: Apache-2.0
"""Tests of the x86-64 lifter and corpora.

Most tests run on ANY host: they use the committed objdump listings (dynphi/x86/data).  Tests marked
NATIVE additionally build the committed C sources with the local gcc and call them through ctypes, so
they run only on an x86-64 host with gcc and objdump (they are skipped elsewhere, for example on ARM).
Set DYNPHI_SKIP_NATIVE=1 to force-skip them."""
import ctypes
import itertools
import os
import random
import subprocess
import tempfile
import unittest

from dynphi.cfg import reaching_defs, rd_of
from dynphi.ir import run
from dynphi.oracle import Oracle, ExactVerifier
from dynphi.static_corr import static_rd
from dynphi.x86 import corpus
from dynphi.x86.cgen import OPAQUE, OPAQUE_V2
from dynphi.x86.corpus import load_corpus, host_can_build, GCC_FLAGS, SPECS, sources, source_path, listing_path, sha256_file
from dynphi.x86.lift import parse_objdump, lift, objdump, Reject
from tests.test_dynphi import check_defuse_faithful

D = 32
NATIVE = host_can_build() and os.environ.get("DYNPHI_SKIP_NATIVE") != "1"
needs_native = unittest.skipUnless(NATIVE, "needs an x86-64 host with gcc and objdump")


class TestCommittedCorpus(unittest.TestCase):
    def test_manifest_hashes_match_files(self):
        import json
        with open(os.path.join(corpus.DATA, "MANIFEST.json")) as fh:
            m = json.load(fh)
        for fn, h in m["sha256"].items():
            self.assertEqual(sha256_file(os.path.join(corpus.DATA, fn)), h, fn)

    def test_committed_sources_equal_generator_output(self):
        for name in SPECS:
            with open(source_path(name)) as fh:
                text = fh.read()
            self.assertEqual(text, "\n\n".join(sources(name).values()) + "\n", name)

    def test_every_function_lifts(self):
        for name in SPECS:
            self.assertEqual(len(load_corpus(name)), SPECS[name]["n"])


class TestLifter(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.n = 40
        cls.funcs = load_corpus("c3", cls.n)
        cls.lib = None
        if NATIVE:
            cls.wd = tempfile.mkdtemp(prefix="dynphi_t_")
            so = os.path.join(cls.wd, "c3.so")
            subprocess.run(["gcc", "-O0", "-shared", "-fPIC", source_path("c3"), "-o", so], check=True)
            cls.lib = ctypes.CDLL(so)

    @needs_native
    def test_lifted_semantics_equal_native_execution(self):
        checked = 0
        for f in self.funcs:
            nat = getattr(self.lib, f.name)
            nat.restype = ctypes.c_uint32
            nat.argtypes = [ctypes.c_uint32] * 2
            for a, b in itertools.product(range(D), range(D)):               # the WHOLE 32x32 domain
                tr, done, ret = run(f, (a, b), 4000)
                self.assertTrue(done)
                self.assertEqual(ret & 0xFFFFFFFF, nat(a, b), f"{f.name} ({a},{b})")
                checked += 1
        self.assertEqual(checked, self.n * D * D)

    def test_lifted_defuse_equals_interpreter_reads_and_writes(self):
        rng = random.Random(3)
        for f in self.funcs:
            for _ in range(3):
                check_defuse_faithful(self, f, (rng.randrange(D), rng.randrange(D)))

    def test_edge_baseline_queries_machine_code_branches(self):
        # regression: the first C3 run used an edge control that only recognised the toy-IR opcode `br`
        from dynphi.baselines import edge_coverage
        asked = 0
        for f in self.funcs[:10]:
            rd, o = reaching_defs(f), Oracle(f, D, lmax=4000)
            tr = run(f, (3, 4), 4000)[0]
            _, nq, _ = edge_coverage(f, rd, set(zip(tr, tr[1:])), ExactVerifier(o))
            asked += nq
        self.assertGreater(asked, 10)

    def test_static_path_sensitive_rd_is_sound_on_machine_code(self):
        removed = 0
        for f in self.funcs[:25]:
            rd, o = reaching_defs(f), Oracle(f, D, lmax=4000)
            ps = static_rd(f)
            for (d, (p, r)), n in o.flow_inputs.items():
                self.assertIn(d, ps[p][r], f.name)
            removed += sum(len(rd[p][r]) - len(ps[p].get(r, ())) for p in rd for r in rd[p])
        self.assertGreater(removed, 0)

    def test_plain_functions_have_few_dead_pairs(self):
        # "plain" = no injected opaque/contextual piece.  Nested guards can still make an arm
        # accidentally infeasible, so this is a measured property, not a construction guarantee.
        fs = [f for f in load_corpus("c4") if f.clean][:20]
        zero = 0
        for f in fs:
            rd, o = reaching_defs(f), Oracle(f, D, lmax=4000)
            dead = sum(1 for p in rd for r in f.uses(p) if len(rd_of(rd, p, r)) >= 2
                       for d in rd_of(rd, p, r) if o.flow_inputs.get((d, (p, r)), 0) == 0)
            zero += dead == 0
        self.assertEqual(len(fs), 20)
        self.assertGreater(zero / len(fs), 0.2)

    def test_stack_slots_and_flags_are_tracked_locations(self):
        f = self.funcs[0]
        self.assertTrue(any(r.startswith("m-") for r in f.regs) and "flags" in f.regs)

    def test_static_rd_contains_concrete_flows(self):
        for f in self.funcs[:15]:
            rd, o = reaching_defs(f), Oracle(f, D, lmax=4000)
            self.assertFalse(o.truncated)
            for (d, (p, r)), n in o.flow_inputs.items():
                self.assertIn(d, rd_of(rd, p, r), f.name)

    def test_unsupported_instruction_is_rejected_not_mislifted(self):
        with self.assertRaises(Reject):
            lift([(0, "cltq", ""), (1, "ret", "")])

    def test_non_x86_listing_is_rejected(self):
        # an AArch64 listing (what gcc emits on ARM hosts) must fail loudly instead of mis-lifting
        with self.assertRaises(Reject):
            lift([(0, "sub", "sp, sp, #16"), (1, "ret", "")])
        with self.assertRaises(Reject):
            parse_objdump("a.o:     file format elf64-littleaarch64\n\n0000000000000000 <f0>:\n   0:\tsub sp, sp, #16\n")

    @needs_native
    def test_gcc_does_not_fold_the_opaque_predicates(self):
        # compile each predicate in isolation and check a conditional branch survives -O0
        for p in OPAQUE + OPAQUE_V2:
            src = "unsigned f(unsigned a, unsigned b){ unsigned r; if (%s) r = 5u; else r = 7u; return r; }" % p.replace("X", "a").replace("Y", "b")
            c = os.path.join(self.wd, "p.c")
            o = os.path.join(self.wd, "p.o")
            with open(c, "w") as fh:
                fh.write(src)
            subprocess.run(["gcc"] + GCC_FLAGS + ["-c", c, "-o", o], check=True)
            ins = parse_objdump(objdump(o))["f"]
            self.assertTrue(any(m.startswith("j") and m != "jmp" for _, m, _ in ins), p)


if __name__ == "__main__":
    unittest.main(verbosity=2)
