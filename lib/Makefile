# makefile for matrix library
#
#	Likely one shouldn't call make clean at the end of all, but I don't know better yet.
#
#   This code will likely not erase your harddrive,
#   but I make no guarantees.
#
#      Benjamin "Brutus" Gruey
#         July 2, 2016

all: libmatrix.a
	make clean
libmatrix.a:	*.o
	ar -cvq libmatrix.a *.o

*.o:	*.c
	gcc -c *.c

clean:
	rm *.o
