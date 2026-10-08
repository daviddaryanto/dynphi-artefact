# Pre-registration of the C3 (real gcc -O0 x86-64) evaluation

Written BEFORE `python -m experiments.run_eval 200 x86` was run for the first time.
The SHA-256 of the code snapshot is recorded in `results/results_x86.json` (`settings.code_sha256`)
and of this file in `settings.prereg_sha256`; both are computed by the script at run time and must
match the values printed below by `sha256sum` if the files were not edited afterwards.

## Corpus and protocol (fixed)
* 200 C functions from `dynphi/x86/cgen.py`, seeds 9000..9199, compiled once with the system gcc
  (`-O0 -fno-pie -fno-stack-protector -fcf-protection=none`), lifted by `dynphi/x86/lift.py`
  (validated against native execution in `tests/test_x86.py`).
* Ground truth: exhaustive oracle over 32 x 32 values of (edi, esi); no execution may be truncated.
* Same procedures, seeds, draws and bootstrap as C1/C2 (`experiments/run_eval.py`).  No parameter
  is tuned after seeing C3 results.  Each hypothesis is evaluated once and reported whatever the outcome.

## Hypotheses (decision rules fixed in advance)
* **H1 (filter).** With |T|=30, querying only cold definitions needs <= 0.35 of the exhaustive queries
  (upper CI bound) and recall over *visited* joins is 1.00 (Proposition 2).
* **H2 (edge control is incomplete).** Edge-coverage-then-cold-filter beats edge coverage alone in recall
  by >= 0.10, with the 95% CIs not overlapping.  Refuted if the CIs overlap.
* **H3 (ranking is useless).** At half of the cold-list budget, the CI of the dead pairs found by u-order
  overlaps that of address order and of random order (null result as in C2).  If u-order is better with
  non-overlapping CIs we report it as a ranking benefit.
* **H4 (precision).** Candidate precision at |T|=30, theta=1 is >= 0.75 (point estimate).
* **H5 (memory matters).** >= 90% of the dead join pairs are on stack slots, i.e. a register-only analysis
  would see <= 10% of them.
* **H6 (safety).** Exact and lossy verifiers produce zero wrong K and wrong P; the path-limited verifier
  produces > 0.
* **H7 (Dyn-Phi vs cold filter).** Full Dyn-Phi (ranking + feedback) and the cold filter have overlapping
  recall and query-ratio CIs (null result as in C1/C2).

## What would falsify the paper's reading
Reading: "Dyn-Phi is a second stage after edge-level triage; ranking and feedback add nothing".
It is falsified on C3 if H2 fails (edge alone already complete), or H3 fails with u-order significantly
better (ranking then has signal), or H7 fails in favour of full Dyn-Phi.

## Declared limitations of this registration
Same author and same generator family as C1/C2 (no third party);
the registration is only verifiable if this file is published or hashed externally BEFORE a reader
re-runs it.  Opaque predicates are source-level (gcc -O0), not OLLVM/Tigress output.
