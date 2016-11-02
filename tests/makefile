####################
#
#	Makefile for testing the matrix library
#
#
#
#################################

CC = gcc

MATRIX_FLAGS = -Wall 

MATRIX_LIBRARY = -I../lib/ -L../lib/ -lmatrix -lm

.PHONY: run, basic, read, gs

basic:
	$(CC) $(MATRIX_FLAGS) basic_test.c $(MATRIX_LIBRARY) -o test_basic.x
	./test_basic.x

gs:
	$(CC) $(MATRIX_FLAGS) gs_test.c $(MATRIX_LIBRARY) -o test_gs.x
	./test_gs.x | less
