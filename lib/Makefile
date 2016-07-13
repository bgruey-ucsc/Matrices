# Make the Matrix Library!

CC=/usr/bin/gcc
CFLAGS=-shared -fPIC
LD=/usr/bin/ld
LDFLAGS=-shared -fPIC -lm

srcfiles = $(wildcard *.c)
objfiles = $(srcfiles:.c=.o)

default: libmatrix.so

libmatrix.so: $(objfiles)
	$(LD) $(LDFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm $(objfiles) libmatrix.so
