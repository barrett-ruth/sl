PREFIX ?= ${HOME}/.local
CC ?= cc
LDFLAGS = -lX11
output: dwmb.c config.h
	${CC}  dwmb.c $(LDFLAGS) -o dwmb -D$(shell cat /etc/hostname) -DSCRIPT'(s)="\"$(shell pwd)/scripts/\""s'
clean:
	rm -f *.o *.gch dwmb
install: output
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	install -m 0755 dwmb $(DESTDIR)$(PREFIX)/bin/dwmb
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/dwmb
