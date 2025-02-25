# Mangle makefile
#

.PHONY: all  install  clean  uninstall

OPTIONS += -Wall -Werror -Wpedantic
TARGET  = mangle
INSTALL = /usr/local/bin/mangle

all: $(TARGET)  Makefile

install: $(INSTALL)  Makefile

$(INSTALL) : $(TARGET)  Makefile
	@echo "Installing $(TARGET) to $(INSTALL)"  && \
	sudo cp -f $(TARGET) $(INSTALL)
	@echo ""

$(TARGET) : mangle.c  Makefile
	gcc $(OPTIONS) -O2 -o mangle mangle.c

clean:
	@rm -f *.o

uninstall:
	@rm -f $(TARGET)

# end
