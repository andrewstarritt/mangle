# Mangle makefile
#

.PHONY: all  install  clean  uninstall

all: install

install: mangle

mangle : mangle.c Makefile
	gcc -Wall -O2 -o mangle mangle.c

clean:
	@echo ""

uninstall:
	@rm -f mangle

# end
