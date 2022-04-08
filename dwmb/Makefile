PREFIX  := ${HOME}/.local
CC      := cc
CFLAGS  := -pedantic -Wall -Wno-deprecated-declarations -Os
LDFLAGS := -lX11

all: options dwmb

options:
	@echo dwmb build options:
	@echo "CFLAGS  = ${CFLAGS}"
	@echo "LDFLAGS = ${LDFLAGS}"
	@echo "CC      = ${CC}"

dwmb: dwmb.c config.h
	${CC} -o dwmb dwmb.c ${CFLAGS} ${LDFLAGS} -DSCRIPT'(s)="\"$(shell pwd)/scripts/\""s'

clean:
	rm -f *.o *.gch dwmb

install: dwmb
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f dwmb ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/dwmb

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/dwmb

.PHONY: all options clean install uninstall
