.PHONY: all clean

DIR_SRC = $(ROOT)/src
DIR_BUILD = $(ROOT)/build
DIR_MODULES = $(DIR_SRC)/file

RM = rm 
RMFLAGS = -rf
RMS = $(DIR_BUILD)

all:
	@set -e; \
	for dir in $(DIR_MODULES); \
	do \
	  cd $$dir && $(MAKE); \
	done
	@echo ""
	@echo "Build completed"
	@echo ""

clean:
	@set -e; \
	for dir in $(DIR_MODULES); \
	do \
	  cd $$dir && $(MAKE) clean; \
	done
	$(RM) $(RMFLAGS) $(RMS)
	@echo ""
	@echo "Clean completed"
	@echo ""


