# Reproducing the results

## Requirements

* Python 3.9 or newer, `numpy`, `matplotlib` (`python3 -m pip install -r requirements.txt`).
* No compiler is needed. gcc and objdump are used only by two optional tests and by corpus regeneration
  (x86-64 hosts only).

## One command

```bash
bash run_all.sh
```

It runs, in order:

| Step | Command | Output |
|---|---|---|
| tests | `python3 -m unittest -v tests.test_dynphi tests.test_x86` | pass or fail |
| C1, C2 | `python3 -m experiments.run_eval 200 synthetic` | `results/results.json` |
| C3 | `python3 -m experiments.run_eval 200 x86` | `results/results_x86.json` |
| C4 | `python3 -m experiments.run_eval 200 x86v2` | `results/results_x86v2.json` |
| figure, tables | `python3 -m experiments.make_figures` | `results/fig_eval.pdf`, `results/tables.tex` |
| provenance | `python3 -m experiments.record_provenance` | `results/provenance.json` |

Typical wall-clock time: about 4 minutes on an x86-64 laptop (the unit tests take about 30 s, each evaluation
40 to 60 s). A phone takes several times longer; the test suite alone took about 3 minutes on one.

## Determinism

Every random choice is seeded. Re-running on the same code and data gives byte-identical `results/*.json`
apart from the `settings.code_sha256` field if you changed any code. The x86 corpora are read from committed
listings, so the results do not depend on the host compiler or architecture. Floating-point bootstrap
percentiles come from `numpy.random.default_rng(seed)`; a different numpy major version could in principle
change the last digits.

## What maps to what in the paper

| Paper item | Source |
|---|---|
| Table "candidates at theta = 1" (E1) | `results/tables.tex` key `E1`, from the four results files |
| Table "strategies" (E2) | key `E2` |
| Table "cost relative to exhaustive" | key `COST` |
| Figure with panels (a), (b), (c) | `results/fig_eval.pdf` |
| Ordering ablation, paired differences (E3) | `results/results*.json`, `<corpus>.E3.<T>.paired_half_budget` |
| Safety table (E4) | `<corpus>.E4` |
| Zero-hit calibration (E5, C2 only) | `results/results.json`, key `E5` |
| Flow versus reach-only query (E6) | `<corpus>.E6` |
| Location classes (E7, x86 only) | `<corpus>.E7` |
| Registered outcomes | `prereg/`, `docs/EXPERIMENTS.md` |

## Platform matrix

| Host | Tests | Evaluation | Regenerate corpora |
|---|---|---|---|
| x86-64 Linux or macOS with gcc | all, including native-execution tests | yes | yes |
| x86-64 without gcc | all except 2 skipped | yes | no |
| ARM (Termux, Raspberry Pi, Apple silicon) | all except 2 skipped | yes | no |

The two tests that skip are `test_lifted_semantics_equal_native_execution` and
`test_gcc_does_not_fold_the_opaque_predicates`.

## Troubleshooting

* `Reject: sp` (or another ARM register) from the lifter: the corpus was being compiled on an ARM host, where
  gcc emits AArch64 code that the x86-64 lifter cannot read. Fixed in release 1.0.0: use the committed
  listings (the default). The lifter now also reports `unsupported architecture` when given a non-x86 listing.
* `ModuleNotFoundError: dynphi` when running a script directly: run from the repository root, or
  `python3 -m pip install -e .`.
* `results/` changes after you re-run: compare with `git diff results/`; only `settings.code_sha256` should differ
  if you edited code.

## Regenerating the corpora (x86-64 with gcc and binutils)

```bash
python3 -m dynphi.x86.build_corpus
git diff --stat dynphi/x86/data      # a different gcc may emit different instructions
python3 -m unittest tests.test_x86   # checks sources, manifest hashes and the lifter
```

`dynphi/x86/data/MANIFEST.json` records the gcc and objdump versions and flags used for the committed listings
and the SHA-256 of each data file. Results in `results/` correspond to those listings. If your gcc produces a
different listing, results can change; the committed data is the reference.

## Provenance

`results/provenance.json` lists the SHA-256 of all code, tests, committed corpora, registrations and result
files, plus the Python, gcc and objdump versions of the run. Each results file also stores
`settings.code_sha256` and the SHA-256 of the registrations. There is **no external timestamp**: see
[prereg/README.md](../prereg/README.md).
