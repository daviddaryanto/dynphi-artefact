# dynphi-artefact

[![ci](https://github.com/daviddaryanto/dynphi-artefact/actions/workflows/ci.yml/badge.svg)](https://github.com/daviddaryanto/dynphi-artefact/actions/workflows/ci.yml)
[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.23249925.svg)](https://doi.org/10.5281/zenodo.23249925)
[![license: Apache 2.0](https://img.shields.io/badge/license-Apache%202.0-blue.svg)](LICENSE)

Reference implementation, tests, committed corpora and experiment scripts for the manuscript

> **Dyn-Phi: A Trace-Informed Join Node for Triaging Opaque Predicates and Dead Branches in Binary Code**
> David Daryanto, ECLS Ltd.

Repository: <https://github.com/daviddaryanto/dynphi-artefact>

## What this is

At every use of a register (or stack slot, or FLAGS) where several definitions may arrive, Dyn-Phi annotates
the static reaching-definition set with how often each definition was observed to arrive in execution traces.
A statically possible but never-observed definition is a *cold* candidate for dead code. Candidates are handed
to a three-valued verifier (`FEASIBLE(witness)`, `INFEASIBLE`, `UNKNOWN`); witnesses are replayed as new evidence;
code is declared dead only on an `INFEASIBLE` verdict.

This repository contains:

* the algorithms (evidence collection, node construction, triage loop) in a few hundred lines of plain Python,
* a small IR with an interpreter, and an x86-64 (AT&T, gcc `-O0`) lifter with stack slots and FLAGS as locations,
* an exhaustive-enumeration oracle and verifiers (exact, lossy, deliberately unsound),
* the controls the paper reports: a cold-definition filter, an edge-coverage control and a trace-free
  path-sensitive static baseline,
* four evaluation corpora (C1 to C4), the experiments E1 to E7 and the pre-registration files,
* 35 tests, including differential tests and a test of the lifter against native execution.

## What this is not

This artifact does **not** evaluate real obfuscator output (OLLVM, Tigress, VMProtect, Themida), does **not**
use a real symbolic execution engine as verifier (the verifier is an exact enumerator over a finite input
domain), and compares against **no** third-party tool. See [docs/LIMITATIONS.md](docs/LIMITATIONS.md). The
results below must be read with that in mind.

## Results in brief

On corpus C4 (200 gcc `-O0` x86-64 functions lifted to the IR, half with injected opaque predicates, half plain;
every function counted), `|T| = 30` traces, 95% cluster-bootstrap intervals:

| Question | Result |
|---|---|
| Queries needed by the cold filter, relative to exhaustive querying | 0.17 (0.15 to 0.18) |
| Same, if an INFEASIBLE query costs 10x / 100x a FEASIBLE one | 0.52 / 0.91 |
| Dead pairs eliminated by the trace-free path-sensitive static baseline (injected half) | 0.32 (0.28 to 0.38), with 0 queries |
| Cheapest configuration with full recall | static analysis, then the cold filter (0.125) |
| Edge-coverage control, recall | 0.48 (0.44 to 0.53) |
| Ordering candidates by the score `u`, versus address order (paired, half budget) | 6.3 points worse (3.5 to 9.4) |
| Recall gained by replaying witnesses (feedback), paired | +0.0036 (0.0006 to 0.0075) |

Most of the findings are negative; the paper reports them as such. Full tables: `results/` and
[docs/EXPERIMENTS.md](docs/EXPERIMENTS.md).

## Quick start

```bash
git clone https://github.com/daviddaryanto/dynphi-artefact.git
cd dynphi-artefact
python3 -m pip install -r requirements.txt     # numpy, matplotlib
python3 examples/quickstart.py                 # Example A of the paper, end to end
python3 -m unittest -v tests.test_dynphi tests.test_x86
```

Reproduce every number and figure (about 4 minutes on an x86-64 laptop, longer on phones):

```bash
bash run_all.sh
```

Optional editable install (`pip install -e .`) makes `import dynphi` available anywhere.

### Minimal API example

```python
from dynphi.ir import Func, Ins, run
from dynphi.cfg import reaching_defs
from dynphi.core import Evidence, collect, build, triage
from dynphi.oracle import Oracle, ExactVerifier

f = Func([...], inputs=("a",))                    # build a function in the IR (see examples/quickstart.py)
rd = reaching_defs(f)                             # static reaching definitions
ev = Evidence()
for args in inputs:                               # Algorithm 1: fold traces into counters
    collect(f, rd, run(f, args)[0], ev)
nodes, cands = build(rd, ev, delta=0.05, theta=1.0)               # Algorithm 2
res = triage(f, rd, ev, ExactVerifier(Oracle(f, 32)), 0.05, 1.0)  # Algorithm 3
print(res.K, res.P, res.U)                        # dead points, dead pairs, unresolved
```

To use your own verifier, implement `reach(q)`, `flow(d, site)` and `edge(p, s)` returning `("INFEASIBLE", None)`,
`("FEASIBLE", witness_inputs)` or `("UNKNOWN", None)`, plus `n_queries`, `verdicts` and `lmax`. It must answer
`INFEASIBLE` only when it is sound; a search that stops at a bound must answer `UNKNOWN`
(see [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md)).

## Platform notes

* Linux, macOS, WSL and Termux are supported. Python 3.9 or newer.
* **gcc and objdump are not needed.** The x86-64 corpora are committed as C sources plus objdump listings in
  `dynphi/x86/data`, so the evaluation is identical on every host, including ARM phones and Apple silicon.
* On an x86-64 host with gcc, two extra tests run: one builds the committed C sources and checks the lifted
  code against native execution on all `40 x 1024` inputs, the other checks that gcc does not fold the
  predicates. On other hosts they are reported as skipped. Set `DYNPHI_SKIP_NATIVE=1` to skip them anywhere.
* `python3 -m dynphi.x86.build_corpus` regenerates the committed data (x86-64 host with gcc and binutils only).
  A listing produced on ARM cannot be lifted and is rejected with an explicit error.

## Repository layout

```
dynphi/            library: ir, cfg, core (Algorithms 1 to 3), oracle, baselines, static_corr, gen
dynphi/x86/        lifter, C generator, corpus loader, committed data (C sources + objdump listings)
experiments/       run_eval (E1 to E7), make_figures, record_provenance
tests/             test_dynphi (algorithms, propositions, baselines), test_x86 (lifter, corpora)
examples/          quickstart.py
prereg/            pre-registration files of C3 and C4 and their hashes
results/           results JSON, figure, LaTeX tables, provenance.json, archive/
docs/              architecture, reproduction, experiments, limitations
```

## Documentation

* [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md): modules, IR, mapping from paper algorithms to code, verifier interface.
* [docs/REPRODUCING.md](docs/REPRODUCING.md): step-by-step reproduction, expected outputs, determinism, troubleshooting.
* [docs/EXPERIMENTS.md](docs/EXPERIMENTS.md): corpora, strategies, experiments E1 to E7, statistics, result file schema.
* [docs/LIMITATIONS.md](docs/LIMITATIONS.md): what the artifact does and does not show.
* [prereg/README.md](prereg/README.md): what the pre-registrations are, and what they are not.
* [CONTRIBUTING.md](CONTRIBUTING.md), [CHANGELOG.md](CHANGELOG.md).

## Citing

See [CITATION.cff](CITATION.cff). GitHub renders a "Cite this repository" entry from it.

* Artifact (this repository): <https://doi.org/10.5281/zenodo.23249925>
* Manuscript: <https://doi.org/10.5281/zenodo.23199026>

## License

Copyright (c) 2026 David Daryanto.

This repository (code, committed data, results and documentation) is licensed under the
[Apache License, Version 2.0](https://www.apache.org/licenses/LICENSE-2.0). The full text is in
[LICENSE](LICENSE) and attribution notices are in [NOTICE](NOTICE).

The accompanying manuscript is **not** covered by this license. It is licensed separately under the
[Creative Commons Attribution 4.0 International License (CC BY 4.0)](https://creativecommons.org/licenses/by/4.0/).

Contact: hub@ecls.ltd.
