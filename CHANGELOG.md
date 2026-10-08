# Changelog

## Unreleased

* Added Zenodo DOIs for the artifact and the manuscript.
* License changed: the artifact is now Apache License 2.0 (was CC BY 4.0). The manuscript is licensed separately under CC BY 4.0. Added `NOTICE` and SPDX headers to Python files.

## 1.0.0 (2026-10-08)

First public release.

* Algorithms 1 to 3, the flow-sensitive verifier query, an exhaustive oracle, three verifiers.
* Controls: cold filter, edge-coverage control, trace-free path-sensitive static baseline.
* Corpora C1 and C2 (toy IR) and C3 and C4 (gcc `-O0` x86-64, lifted). The x86-64 corpora are committed as C
  sources and objdump listings, so the evaluation no longer depends on the host compiler or architecture. This
  fixes a failure on ARM hosts (for example Termux), where the previous version compiled the corpus locally and
  the lifter received AArch64 assembly (`Reject: sp`).
* Native-execution tests are skipped on hosts that are not x86-64 with gcc.
* 35 tests, including differential tests, a Def/Use faithfulness test and a lifter test against native execution
  on the whole input domain.
* Pre-registration files for C3 and C4, with a deviation log.
* GitHub Actions workflow, `pyproject.toml`, `CITATION.cff`, documentation.
* License: Creative Commons Attribution 4.0 International (CC BY 4.0), the same as the manuscript.
