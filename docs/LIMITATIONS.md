# Limitations

Read these before relying on any number in this repository.

1. **No real obfuscator output.** The corpora are generated. C3 and C4 are real gcc `-O0` x86-64 machine code,
   but the opaque predicates are placed at the C source level. No OLLVM, Tigress, VMProtect or Themida sample
   is analyzed. At `-O1` gcc removes the opaque arms itself, so `-O0` is the only setting in which the
   constructed problem exists.
2. **The verifier is an oracle.** It enumerates 1024 inputs. It is exact for these corpora only because every
   predicate is algebraically constant and every trigger is inside the domain. It is not a symbolic engine, its
   per-query cost is a unit, and nothing here says how expensive the flow query is on a real engine.
3. **No third-party baselines.** There is no comparison with BB-DSE, angr, Triton, Ghidra or any published
   detector. The edge-coverage control and the static baseline are our own implementations.
4. **Author-designed corpora.** The generators were written with knowledge of the algorithm. C2 was designed
   after C1 results were known, and the C3 and C4 registrations were partly informed by earlier results.
   Prevalence of dead pairs (15 to 26%) and the rate of rare triggers (1/32, 1/1024) are chosen, not measured.
5. **Lifter scope.** A 32-bit integer subset of x86-64 as emitted by gcc `-O0` for the generated sources: no
   division, sign extension, calls, indirect addressing, aliasing or SIMD. Constant-offset stack slots and FLAGS
   are tracked as locations; anything else is rejected, never guessed.
6. **Intra-procedural.** Flattening, virtualization and inter-procedural flow are out of scope.
7. **Evidence acquisition is not solved.** The experiments draw inputs from the same finite domain on which ground
   truth is computed. Real use needs entry states, harnesses and environment handling that are not implemented.
8. **Self-registration.** The files in `prereg/` carry no external timestamp (see `prereg/README.md`).
9. **Correlated test errors.** Tests and code were written together. The concrete-execution
   cross-checks, the Def/Use faithfulness test and the native-execution test of the lifter reduce this risk but
   do not remove it.
10. **Statistics cover sampling of functions, not generator misspecification.**
