# Experiments

## Corpora

| Corpus | Source | Functions | Join pairs | Dead pairs | Notes |
|---|---|---|---|---|---|
| C1 | toy-IR generator, profile `basic` (`dynphi/gen.py`, seeds 1000..1199) | 200 | 2858 | 687 (24.0%) | opaque diamonds, rare arms, loops, flow-dead definitions, `havoc` |
| C2 | toy-IR generator, profile `rich` (seeds 5000..5199) | 200 | 4726 | 1226 (25.9%) | adds contextual (correlated-branch) pieces and guards; designed after C1 results were known |
| C3 | gcc 13.3 `-O0` x86-64, seeds 9000..9199, lifted | 200 | 3869 | 876 (22.6%) | every function has a dead pair |
| C4 | gcc 13.3 `-O0` x86-64, seeds 12000..12199, lifted, wider predicates | 200 | 3833 | 562 (14.7%) | 100 injected and 100 plain functions; plain ones still contain 119 accidental dead pairs |

Ground truth is exact: each function has two inputs in `[0, 32)`, and the oracle enumerates all 1024 executions
(none truncated). Opaque predicates are always true or always false over all unsigned inputs, and every rare
trigger lies inside the domain, so the finite domain agrees with the semantic notion of dead.

## Strategies compared (all with the same exact verifier, distinct queries counted)

| Name | Description |
|---|---|
| exhaustive | query every statically possible join definition, in address order |
| cold filter | query only cold definitions, address order, no score, no feedback |
| Dyn-Phi | Algorithm 3: ranking by `u`, feedback by replaying witnesses |
| edge control | query unobserved conditional edges of visited branches, delete infeasible ones, recompute RD |
| static | trace-free path-sensitive reaching definitions (per-definition branch facts, constant propagation), 0 queries |
| edge+cold, static+cold, static+edge+cold | combinations; the cold stage only sees definitions the earlier stages did not remove |

## Experiments

| Id | Question | Where |
|---|---|---|
| E1 | candidate precision and recall versus `\|T\|`, and a theta sweep | `E1` |
| E2 | queries and recall per strategy, cost-weighted ratios, subsets (with and without dead pairs, injected and plain), paired differences | `E2` |
| E3 | does ordering candidates by `u` find dead pairs faster than address or random order? (paired) | `E3` |
| E4 | safety with exact, lossy (30% UNKNOWN) and unsound (8 sampled inputs) verifiers, one shared trace draw | `E4` |
| E5 | calibration of the zero-hit bound in the near-boundary stratum, i.i.d. versus correlated sampling (C2 only) | `E5` |
| E6 | flow query versus reach-only query with a resolved-set guard | `E6` |
| E7 | location classes of join pairs (slot, register, flags) on the x86 corpora | `E7` |

## Statistics

* Unit of resampling: the function. Draws within a function are summed, never treated as independent.
* Intervals: 2000 bootstrap resamples, percentile, 95%. Ratios are ratios of sums.
* Comparisons between strategies are **paired** differences on the same trace draws (`boot_diff`). Equivalence
  is judged with the 90% interval against a margin written down in advance (TOST); overlapping intervals are
  never read as "no difference".
* Cost model: an INFEASIBLE query costs `c` times a FEASIBLE one (`c` in 1, 10, 100); `cost_ratio` in `E2`.

## Results file schema (`results/results*.json`)

```
settings                      mode, seeds, code_sha256, prereg_sha256
<corpus>                      counts (join_pairs, dead_join_pairs, ...), static_recall_all
<corpus>.E1[T]                precision, recall_visited, recall_all, cand_per_fn, theta[...]
<corpus>.E2                   per strategy: query_ratio_vs_exhaustive, recall, queries_per_function,
                              cost_ratio{1,10,100}; paired{...}; by_subset{with_dead,no_dead,injected,plain}
<corpus>.E3[T]                curves, paired_half_budget{u_minus_address,u_minus_random}
<corpus>.E4[verifier]         K, P, unknown, K_wrong, P_wrong
<corpus>.E6[mode]             dead_pairs_confirmed, queries
<corpus>.E7                   by_location, fraction_dead_on_slots
```

Interval cells are `[estimate, low95, high95]`; paired differences are `[estimate, low95, high95, low90, high90]`.

## Registered outcomes

C3 hypotheses H1 to H7 and C4 decision rules A1 to A9 are in `prereg/`. All C4 rules were met, with the
exception that rule A5 (static, edge, cold needs no more queries than the cold filter) held overall and on the
injected half but not on plain functions. The registrations were written by the same author after C1 and C2
were known and carry no external timestamp.
