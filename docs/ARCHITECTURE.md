# Architecture

## Data flow

```
function (IR)  --reaching_defs-->  static RD(p, r)
traces (interpreter runs) --collect (Alg. 1)--> counters F, M, escapes X
RD + counters --build (Alg. 2)--> dyn-phi nodes + cold candidates (sorted by u)
candidates + verifier --triage (Alg. 3)--> dead points K, dead pairs P, unresolved U
```

## Modules

| Module | Role |
|---|---|
| `dynphi/ir.py` | IR (`Ins`, `Func`), concrete interpreter `run` with an optional per-step hook |
| `dynphi/cfg.py` | static reaching definitions (worklist); entry pseudo-definitions have site `-1` |
| `dynphi/core.py` | `Evidence`, `collect` (Alg. 1), `build` (Alg. 2), `resolve` and `triage` (Alg. 3), `prune` |
| `dynphi/oracle.py` | `Oracle` (exhaustive tables of reach, flow and edge witnesses), `ExactVerifier`, `LossyVerifier`, `SampledVerifier` (unsound on purpose) |
| `dynphi/baselines.py` | cold filter (no ranking, no feedback), edge-coverage control |
| `dynphi/static_corr.py` | trace-free path-sensitive static baseline |
| `dynphi/gen.py` | toy-IR function generator (corpora C1, C2) |
| `dynphi/x86/cgen.py` | C source generator (corpora C3, C4) |
| `dynphi/x86/lift.py` | objdump (AT&T x86-64) to IR lifter |
| `dynphi/x86/corpus.py` | committed corpora loader, regeneration (`build`), manifest |

## The IR

Program points are instruction indices. A location is a string: a register, a stack slot named `m<offset>`
(for `disp(%rbp)` in lifted code) or `flags`. An integer operand is an immediate. All values are 32-bit unsigned.

| Op | Effect | Def | Use |
|---|---|---|---|
| `mov dst, a` | `dst = a` | dst | a |
| `bin dst, a, b, f` | `dst = a f b` (`+ - * & \| ^ << >>`) | dst | a, b |
| `br a, b, f, tgt` | jump to `tgt` if `a f b` (`== != < <= > >=`) | none | a, b |
| `cmp a, b` | `flags = (a, b)`; with `f="test"`, `flags = (a & b, 0)` | flags | a, b |
| `jcc f, tgt` | jump on x86 condition `f` (`e ne a ae b be g ge l le`) over `flags` | none | flags |
| `jmp tgt`, `ret a`, `nop` | control flow | none | a (ret) |
| `havoc` | unmodeled instruction | all | all |

`havoc` implements Assumption 1 of the paper: an instruction with unmodeled effects defines and uses everything.
The test `TestDefUseFaithfulness` checks that the registers the interpreter actually reads and writes at every
step equal `Use(p)` and `Def(p)`.

## From the paper to the code

| Paper | Code |
|---|---|
| Static reaching definitions, join use site | `cfg.reaching_defs`, `rd_of` |
| Algorithm 1 (evidence collection) | `core.collect` |
| Dyn-phi node, cold definition, split node | `core.Node`, `core.build` |
| Zero-hit score `u = 1 - delta^(1/M)` | `core.zero_hit_u` |
| Algorithm 2 | `core.build` (`family=True` applies a Bonferroni correction) |
| Algorithm 3 and the flow query | `core.triage`, `core.resolve` (`mode="flow"`) |
| Reach-only query (first draft), with and without guard | `mode="reach_only"`, `"reach_only_guarded"` |
| Branch folding after triage | `core.prune` |
| Propositions 1 to 7 | `tests/test_dynphi.py`, test names `test_P1_...` to `test_P7_...` |

## Verifier interface

A verifier is any object with:

* `reach(q)`: can program point `q` be reached from the entry on some input?
* `flow(d, site)`: is there an input on which definition `d` is the last definition of `site`'s register when the
  execution reaches `site`'s point?
* `edge(p, s)`: is the CFG edge `p -> s` taken by some input? (used by the edge control only)
* `n_queries` (distinct queries answered), `verdicts` (a `Counter` over verdict kinds), `lmax` (step bound used to
  replay witnesses).

Each query returns `("INFEASIBLE", None)`, `("FEASIBLE", witness_inputs)` or `("UNKNOWN", None)`.
Soundness requirement: answer `INFEASIBLE` only if no input exists. A search that stops at a bound must answer
`UNKNOWN`. `SampledVerifier` violates this on purpose, so that the tests can show a violation being detected.

## The lifter

`dynphi/x86/lift.py` accepts the 32-bit integer subset that gcc emits at `-O0` for the generated C:
`mov`, `add sub imul and or xor shl shr`, `not neg`, `cmp test`, `jcc`, `jmp`, `ret`, and prologue and epilogue
instructions (lifted to `nop`). Registers are canonicalized (`eax`, `rax` and `ax` are one location). Anything
else, including a listing for another architecture, raises `Reject`; the lifter never guesses.
