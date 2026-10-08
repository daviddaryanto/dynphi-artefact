#!/usr/bin/env bash
# Reproduces every number and figure of the paper.
#
# Needs Python >= 3.9, numpy and matplotlib.  gcc and objdump are NOT required: the x86-64 corpora
# (C3, C4) are read from the committed listings in dynphi/x86/data.  On an x86-64 host with gcc the
# test suite additionally runs the native-execution tests; elsewhere (for example ARM phones or Apple
# silicon) those tests are skipped automatically.
set -euo pipefail
cd "$(dirname "$0")"
python3 -m unittest -v tests.test_dynphi tests.test_x86
python3 -m experiments.run_eval 200 synthetic     # C1, C2 -> results/results.json
python3 -m experiments.run_eval 200 x86           # C3     -> results/results_x86.json   (prereg/PREREG_C3.md)
python3 -m experiments.run_eval 200 x86v2         # C4     -> results/results_x86v2.json (prereg/PREREG_C4.md)
python3 -m experiments.make_figures               # results/fig_eval.pdf, results/tables.tex
python3 -m experiments.record_provenance          # results/provenance.json
