# Pre-registration of the C4 evaluation (written BEFORE C4 was run)

Hashes of this file and of the code are written by `experiments/record_provenance.py` into
`results/provenance.json` (and printed by `run_all.sh`).  There is no external timestamp: the
registration is only as strong as the reader's trust in the order of events (see "Limits" below).

## Corpus C4 (fixed)
200 C functions, seeds 12000..12199, system gcc `-O0`, lifted as for C3 (`dynphi/x86`, `wide=True`):
* functions 0..99: "injected" (opaque, contextual, rare, genuine, loop pieces; guards; four-plus-two always-true
  predicate families; half of the contextual pieces use `x <= c-1` as the second test, i.e. the same truth value
  with a different constant);
* functions 100..199: "plain" (no injected opaque or contextual piece; nested guards can still make an arm
  accidentally infeasible - measured, not assumed).
Same protocol as C3: 32x32 oracle domain, |T| = 30 for strategy comparisons, three draws per function, 2000
bootstrap resamples over functions, delta = 0.05.  E2 now includes EVERY function.

## Strategies (all with the same exact verifier, unit cost unless stated)
exhaustive; cold filter; Dyn-Phi (ranked + feedback); edge-coverage control; edge then cold;
**static** (trace-free path-sensitive reaching definitions with per-definition branch facts and constant
propagation, 0 queries); static then cold; static then edge then cold.

## Decision rules (all fixed now; estimates are paired differences over functions unless stated)
* **A1.** Cold-filter queries / exhaustive over ALL functions: upper 95% CI bound <= 0.35.
* **A2.** On the plain half, the cold filter still issues >= 0.05 of the exhaustive queries (lower CI bound):
  the filter is not free on code without injected predicates.
* **A3 (cost asymmetry).** Let an INFEASIBLE query cost c times a FEASIBLE one.  Cold-filter cost / exhaustive
  cost over all functions is >= 0.45 at c = 10 and >= 0.80 at c = 100 (point estimates).  Refuted if
  the ratio stays below 0.45 at c = 100.
* **A4.** The static baseline eliminates between 0.20 and 0.85 of the dead pairs of the injected half
  (point estimate), with 0 queries.  Refuted if >= 0.90 (static analysis alone would suffice) or < 0.20.
* **A5.** static -> edge -> cold eliminates all dead pairs at visited joins (recall >= 0.99) and issues
  no more queries than the cold filter (paired difference of query ratios, upper 95% CI bound <= 0).
* **A6 (equivalence, TOST at the 90% level).** Dyn-Phi versus cold filter: paired difference of query ratio within
  +-0.02 and of recall within +-0.01.  Not equivalent => reported as a difference.
* **A7.** u-order versus address order at half of the cold-list budget (|T| = 30): upper 95% CI bound of the paired
  difference (u - address) is < +0.02, i.e. u does not help.  The paper reports the interval, not "overlap".
* **A8.** edge-then-cold exceeds edge alone in recall by >= 0.10 on the injected half (paired 95% CI excludes 0).
* **A9.** Safety: exact and lossy verifiers produce 0 wrong K and 0 wrong P with a draw shared by all three
  verifiers; the path-limited verifier produces > 0.
Exploratory, no decision rule: theta sweep, location classes, per-function query counts on the plain half.

## What would falsify the reading ("Dyn-Phi = second stage after edge-level triage; ranking/feedback add nothing")
A4 >= 0.90, or A5 failing because static -> edge -> cold needs MORE queries than the cold filter, or A7 with u-order
significantly better, or A6 equivalence failing in favour of full Dyn-Phi.

## Limits of this registration
Same author, same generator family as C1-C3; written after C1-C3 results were known, so predictions
A3, A6, A7 are partly informed by them.  No external timestamp.  Opaque predicates are source-level gcc -O0 output,
not OLLVM/Tigress.  The static baseline is our own implementation, not an off-the-shelf analyzer.
