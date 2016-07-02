# makefile for matrix library


all: libmatrix.a
	make clean
libmatrix.a:	*.o
	ar -cvq libmatrix.a *.o

*.o:	*.c
	gcc -c *.c

clean:
	rm *.o
