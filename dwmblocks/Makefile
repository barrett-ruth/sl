PREFIX  := ${HOME}/.local
CC      := cc
CFLAGS  := -pedantic -Wall -Wno-deprecated-declarations -Os
LDFLAGS := -lX11

all: options dwmblocks

options:
	@echo dwmblocks build options:
	@echo "CFLAGS  = ${CFLAGS}"
	@echo "LDFLAGS = ${LDFLAGS}"
	@echo "CC      = ${CC}"

dwmblocks: dwmb.c config.h
	${CC} -o dwmblocks dwmb.c ${CFLAGS} ${LDFLAGS} -DSCRIPT'(s)="\"$(shell pwd)/scripts/\""s'

clean:
	rm -f *.o *.gch dwmb

install: dwmblocks
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f dwmblocks ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/dwmblocks

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/dwmblocks

.PHONY: all options clean install uninstall
