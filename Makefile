RUBBER ?= rubber

RUBBEROPTS += --pdf --warn=all

JOBNAME ?= proposal

.PHONY: all clean

all:
	$(RUBBER) $(RUBBEROPTS) $(JOBNAME)

clean:
	$(RUBBER) $(RUBBEROPTS) --clean $(JOBNAME)
