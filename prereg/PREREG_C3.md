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

## Deviation log (added after the first run; the registered hypotheses and decision rules above are unchanged)
1. First run of `run_eval 200 x86`: the edge-coverage control recognised only the opcode `br` of the toy IR, so it
   asked 0 queries on lifted code (`jcc`) and reported recall 0.000. This is a defect of OUR BASELINE, and it
   favoured Dyn-Phi. It was found by inspecting the output before any hypothesis was evaluated, fixed
   (`dynphi/baselines.py`: `op in ("br", "jcc")`), covered by `test_edge_baseline_queries_machine_code_branches`, and the
   evaluation was re-run once with identical seeds. The first output is kept in
   `results/results_x86_first_run_buggy_edge_baseline.json`; its other numbers (E1, E3, E4, E6, E7) are unchanged by the fix.
2. `dynphi/baselines.py` therefore differs from the snapshot in `results/prereg_snapshot.sha256`; all other hashed
   files and this section's registered parts are unchanged.

3. Audit note (added later). An external review pointed out that this file claimed `settings.code_sha256` and
   `settings.prereg_sha256` were recorded in `results_x86.json` when the first run did not record them.
   That claim was wrong at the time. From the re-run described in the paper onward, `run_eval.py` writes both into
   every results file, and `experiments/record_provenance.py` writes `results/provenance.json`; both hash the CURRENT
   code, not the pre-run snapshot, so the only evidence about the pre-run state is `results/prereg_snapshot.sha256`
   and the as-registered text, neither of which has an external timestamp.
