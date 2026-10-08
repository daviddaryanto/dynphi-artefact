# Copyright (c) 2026 David Daryanto
# SPDX-License-Identifier: Apache-2.0
"""python -m dynphi.x86.build_corpus : regenerate the committed C3/C4 data on an x86-64 host."""
from .corpus import SPECS, build, write_manifest

if __name__ == "__main__":
    for name in SPECS:
        print("building", name, build(name))
    print("manifest:", list(write_manifest()["sha256"]))
