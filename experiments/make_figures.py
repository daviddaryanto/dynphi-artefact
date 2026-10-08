# Copyright (c) 2026 David Daryanto
# SPDX-License-Identifier: Apache-2.0
"""Figure and LaTeX tables generated directly from the results/*.json files."""
import json
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
S = json.load(open("results/results.json"))
C1, C2 = S["C1_basic"], S["C2_rich"]
C3 = json.load(open("results/results_x86.json"))["C3_x86"]
C4 = json.load(open("results/results_x86v2.json"))["C4_x86v2"]
CORP = [("C1", C1), ("C2", C2), ("C3", C3), ("C4", C4)]
plt.rcParams.update({"font.size": 7.5, "font.family": "serif", "axes.linewidth": 0.6})
fig, ax = plt.subplots(1, 3, figsize=(7.2, 2.25))
T = sorted(int(k) for k in C1["E1"])
for (lab, C), st in zip(CORP, ("o-", "s--", "^:", "D-.")):
    e = [C["E1"][str(t)]["precision"] for t in T]
    ax[0].errorbar(T, [x[0] for x in e], yerr=[[x[0] - x[1] for x in e], [x[2] - x[0] for x in e]], fmt=st, color="k", ms=3, lw=1, capsize=2, label=lab)
ax[0].set_xscale("log"); ax[0].set_xlabel("traces $|T|$"); ax[0].set_ylabel("candidate precision"); ax[0].legend(frameon=False, fontsize=6.5)
ax[0].set_title("(a) precision, $\\theta=1$", fontsize=8)
B = C4["E3"]["30"]["budget_fraction"]
for k, st, lab in (("u", "k-", "$u$ order"), ("address", "k--", "address order"), ("random", "k:", "random order")):
    ax[1].plot(B, C4["E3"]["30"]["curve"][k], st, lw=1.1, label=lab)
ax[1].set_xlabel("fraction of cold-list queries"); ax[1].set_ylabel("dead pairs found"); ax[1].legend(frameon=False, fontsize=6.5)
ax[1].set_title("(b) ordering, C4, $|T|=30$", fontsize=8)
cs = [1, 10, 100]
for k, st, lab in (("cold_filter", "ko-", "cold filter"), ("edge+cold", "ks--", "edge, cold"), ("static+cold", "k^:", "static, cold"), ("static+edge+cold", "kD-.", "static, edge, cold")):
    e = C4["E2"][k]["cost_ratio"]
    ax[2].errorbar(cs, [e[str(c)][0] for c in cs], yerr=[[e[str(c)][0] - e[str(c)][1] for c in cs], [e[str(c)][2] - e[str(c)][0] for c in cs]], fmt=st, ms=3, lw=1, capsize=2, label=lab)
ax[2].axhline(1.0, color="0.5", lw=0.6)
ax[2].set_xscale("log"); ax[2].set_xlabel("infeasible-query cost $c$"); ax[2].set_ylabel("cost / exhaustive")
ax[2].set_ylim(0, 1.05); ax[2].legend(frameon=False, fontsize=6, loc="lower right"); ax[2].set_title("(c) asymmetric query cost, C4", fontsize=8)
for a in ax: a.grid(alpha=0.25, lw=0.4)
fig.tight_layout(); fig.savefig("results/fig_eval.pdf")

ci = lambda x, d=3: f"{x[0]:.{d}f} ({x[1]:.{d}f}--{x[2]:.{d}f})"
pm = lambda x, d=2: f"${x[0]:.{d}f}{{\\pm}}{max(x[0]-x[1], x[2]-x[0]):.{d}f}$"
out = []
rows = []
for t in T:
    cells = [pm(C["E1"][str(t)]["precision"]) for _, C in CORP]
    cells += [f"{C4['E1'][str(t)]['recall_all'][0]:.2f}", f"{C4['E1'][str(t)]['cand_per_fn']:.1f}"]
    rows.append(f"{t} & " + " & ".join(cells) + "\\\\")
out.append(("E1", "\n".join(rows)))
rows = []
names = [("cold_filter", "Cold filter"), ("dynphi", "Dyn-Phi (ranked, feedback)"), ("edge", "Edge control"), ("edge+cold", "Edge, then cold"),
         ("static", "Static path-sensitive (0 queries)"), ("static+cold", "Static, then cold"), ("static+edge+cold", "Static, edge, then cold")]
for k, lab in names:
    cells = []
    for _, C in CORP:
        e = C["E2"][k]; q = e["query_ratio_vs_exhaustive"]
        cells += ["0" if q[0] == 0 else pm(q), f"{e['recall'][0]:.3f}"]
    rows.append(f"{lab} & " + " & ".join(cells) + "\\\\")
out.append(("E2", "\n".join(rows)))
rows = []
for k, lab in names[:1] + names[3:]:
    pass
rows = ["Exhaustive & 1.00 & 1.00 & 1.00\\\\"]
for k, lab in (("cold_filter", "Cold filter"), ("edge+cold", "Edge, then cold"), ("static+cold", "Static, then cold"), ("static+edge+cold", "Static, edge, then cold")):
    e = C4["E2"][k]["cost_ratio"]
    rows.append(f"{lab} & " + " & ".join(pm(e[str(c)]) for c in cs) + "\\\\")
out.append(("COST", "\n".join(rows)))
rows = []
for k, lab in (("exact", "exact"), ("lossy30", "lossy (30\\% \\textsc{Unknown})"), ("sampled8", "path-limited (8 inputs)")):
    cells = []
    for _, C in CORP:
        a = C["E4"][k]; cells.append(f"{a['K_wrong']}/{a['P_wrong']} of {a['K']}/{a['P']}")
    rows.append(f"{lab} & " + " & ".join(cells) + "\\\\")
out.append(("E4", "\n".join(rows)))
rows = []
for key, e in S["E5"].items():
    T_, samp = key[1:].split("_")
    sl = {"iid": "i.i.d.", "dup5": "5 copies", "seeded": "seed-based"}[samp]
    mm = ci(e["miss_near_Meff"], 2) if e["miss_near_Meff"] else "n/a"
    rows.append(f"{T_} & {sl} & {e['distinct_pairs_near']} & {e['distinct_q_near']} & {ci(e['miss_near'],2)} & {mm}\\\\")
out.append(("E5", "\n".join(rows)))
open("results/tables.tex", "w").write("\n".join(f"%%{k}\n{v}\n%%END" for k, v in out))
print("ok")
