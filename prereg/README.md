# Pre-registration files

| File | Content |
|---|---|
| `PREREG_C3.md` | C3 hypotheses H1 to H7, with the deviation log and an audit note appended afterwards |
| `PREREG_C3_as_registered.md` | the C3 text exactly as hashed before the first C3 run |
| `PREREG_C3_snapshot.sha256` | SHA-256 of the code and registration at that time |
| `PREREG_C4.md` | C4 decision rules A1 to A9, written before C4 was first run |
| `PREREG_C4.sha256` | SHA-256 of `PREREG_C4.md` at registration time |

Check C4: `sha256sum -c PREREG_C4.sha256` (run inside this directory; it must report `OK`).

## What these files are

They fix hypotheses, decision rules, seeds and analysis choices before the corresponding evaluation was run, and
they record where the result diverged from the plan (a bug in our own edge-coverage baseline during the first C3
run, fixed and logged).

## What these files are not

They are **self-registration** by one author. There is no external timestamp, so a reader has no independent
proof of the order of events. The registrations were written after earlier corpora (C1, C2, and C3 for C4) had
been evaluated, so some predictions were informed by those results. A stronger registration would publish the
hash (or a signed git tag) in a place the author cannot edit before running. If the order of events matters to
you, record the hashes yourself before re-running.

## Paths

The registration texts were written when the files lived at the repository root and under `results/`. They now
live here; the text inside them is deliberately left unchanged. The file list in `PREREG_C3_snapshot.sha256` uses
those historical paths and cannot be checked against the current tree: it documents what was hashed, not a
reproducible check.

## Edit after registration

One phrase in the limitations paragraph of each of `PREREG_C3.md`, `PREREG_C3_as_registered.md` and
`PREREG_C4.md` was reworded after the registrations were made (no hypothesis, rule, seed or analysis choice was
touched). The SHA-256 values at registration time were:

| File | SHA-256 at registration |
|---|---|
| `PREREG_C3_as_registered.md` | `9e26adab6417bf390fa272dc99d3cb485ae71d29c16c14a9cab58c6acb0cec16` |
| `PREREG_C4.md` | `332913cfba397715eee18b976836aeed42faf1548e4e48ff0c7ac548e001d0b1` |

`PREREG_C4.sha256` was recomputed for the edited text; the `prereg_sha256` fields in `results/` still hold the
registration-time values.
