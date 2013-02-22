LATEXMK ?= latexmk

LATEXMKOPTS += -pdf -shell-escape

JOBNAME ?= proposal

.PHONY: all clean

all:
	$(LATEXMK) $(LATEXMKOPTS) $(JOBNAME)


clean:
	$(LATEXMK) $(LATEXMKOPTS) -C $(JOBNAME)
