PY ?= python3

.PHONY: test test-portable eval figures all provenance clean

test:            ## all tests (native-execution tests run on x86-64 hosts with gcc, otherwise they are skipped)
	$(PY) -m unittest -v tests.test_dynphi tests.test_x86

test-portable:   ## all tests, forcing the host-independent subset
	DYNPHI_SKIP_NATIVE=1 $(PY) -m unittest -v tests.test_dynphi tests.test_x86

eval:            ## experiments E1-E7 on corpora C1-C4 (about 4 minutes on an x86-64 laptop)
	$(PY) -m experiments.run_eval 200 synthetic
	$(PY) -m experiments.run_eval 200 x86
	$(PY) -m experiments.run_eval 200 x86v2

figures:         ## results/fig_eval.pdf and results/tables.tex from the results/*.json files
	$(PY) -m experiments.make_figures

provenance:      ## results/provenance.json (SHA-256 of code, corpora, registrations, results)
	$(PY) -m experiments.record_provenance

all: test eval figures provenance

clean:
	find . -name __pycache__ -prune -exec rm -rf {} +
