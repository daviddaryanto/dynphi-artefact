# Contributing

Issues and pull requests are welcome, in particular: additional baselines, a real verifier adapter, support for
more x86-64 instructions in the lifter, and corpora built from real obfuscators.

## Ground rules

* Run `python3 -m unittest tests.test_dynphi tests.test_x86` before opening a pull request. If you touch the
  evaluation, run `bash run_all.sh` and explain every change in `results/`.
* Keep the claims policy: negative and null results stay in. A new baseline that beats the method is a result,
  not a regression.
* New corpora or hypotheses that are meant to test a claim should be registered (hashed and published) before
  the first run, as in `prereg/`.
* By contributing you agree that your contribution is licensed under the Apache License 2.0, like the rest of the repository (Section 5 of the license).
* Use ASCII only in source, documentation and data files, so that listings and diffs behave the same everywhere.
* A verifier adapter must return `INFEASIBLE` only when it is sound and `UNKNOWN` at any bound (see
  `docs/ARCHITECTURE.md`).
