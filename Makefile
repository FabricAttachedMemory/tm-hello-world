CFLAGS=-O0 -g
SRCS=hello-world.c
HDRS=hello-world.h
LIBS=-lfam_atomic -lpmem -lpthread
PROG=tm-hello-world
MANPAGE=tm-hello-world.1
BIN=/usr/bin
MAN=/usr/share/man/man1
BINDIR=$(DESTDIR)$(BIN)
MANDIR=$(DESTDIR)$(MAN)

all: $(PROG)

install: $(PROG)
	install -d $(BINDIR)
	install $(PROG) $(BINDIR)
	install -d $(MANDIR)
	install $(MANPAGE) $(MANDIR)

clean:
	rm -f $(PROG)

$(PROG): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) -o $@ $(SRCS) $(LIBS)
