CFLAGS=-O0 -g
SRCS=hello-world.c
HDRS=hello-world.h
LIBS=-lpthread
PROG=tm-hello-world
BIN=/usr/bin
DEST=$(DESTDIR)$(BIN)

all: $(PROG)

install: $(PROG)
	install -d $(DEST)
	install $(PROG) $(DEST)

clean:
	rm -f $(PROG)

$(PROG): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) -o $@ $(SRCS) $(LIBS)
