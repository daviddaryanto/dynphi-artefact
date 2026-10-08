# Copyright (c) 2026 David Daryanto
# SPDX-License-Identifier: Apache-2.0
"""Writes results/provenance.json: SHA-256 of the code, tests, committed corpora, pre-registrations and result files,
plus tool versions.  The registrations carry no external timestamp; publish these hashes (or a git commit) BEFORE
re-running if the order of events matters to you."""
import hashlib, json, os, platform, subprocess, sys

def sha(p): return hashlib.sha256(open(p, "rb").read()).hexdigest()

files = {}
for root in ("dynphi", "experiments", "tests"):
    for dp, _, fs in os.walk(root):
        for f in fs:
            if f.endswith(".py"): files[os.path.join(dp, f)] = sha(os.path.join(dp, f))
for p in ("prereg/PREREG_C3.md", "prereg/PREREG_C4.md", "prereg/PREREG_C3_as_registered.md", "run_all.sh", "README.md",
          "dynphi/x86/data/c3.c", "dynphi/x86/data/c3.objdump.txt", "dynphi/x86/data/c4.c", "dynphi/x86/data/c4.objdump.txt",
          "results/results.json", "results/results_x86.json", "results/results_x86v2.json"):
    if os.path.exists(p): files[p] = sha(p)
def ver(c):
    try:
        return subprocess.run(c, capture_output=True, text=True).stdout.splitlines()[:1]
    except FileNotFoundError:
        return ["not installed"]
json.dump({"python": sys.version.split()[0], "platform": platform.platform(), "gcc": ver(["gcc", "--version"]),
           "objdump": ver(["objdump", "--version"]), "sha256": dict(sorted(files.items()))},
          open("results/provenance.json", "w"), indent=1)
print("provenance.json written:", len(files), "files")
