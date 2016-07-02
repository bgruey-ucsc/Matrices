# makefile for matrix library


all: libmatrix.a

libmatrix.a:	*.o
	ar -cvq libmatrix.a *.o

*.o:	*.c
	gcc -c *.c
