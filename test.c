/*

	Test program for Brutus' Matrix library.

	Likely there isn't a daemon somewhere in here that replaces your hard rive with zeros.

	Benjamin "Brutus" Gruey
		July 2, 2016


*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "./lib/matrix.h"

int main( int argc, char** argv) {

	struct matrix* a = mtx_new(2, 3);
	printf("Made First Matrix!\n");
	struct matrix* b = mtx_new(3, 2);
	printf("Made Second matrix!\n");
	a->data[0][0] = 1;
	a->data[0][1] = 1;
	a->data[0][2] = 2;
	a->data[1][0] = 0;
	a->data[1][1] = 0;
	a->data[1][2] = 1;
	b->data[0][0] = 1;
	b->data[0][1] = 2;
	b->data[1][1] = -1;
	b->data[1][0] = -1;
	b->data[2][1] = 1;
	b->data[2][0] = -1;
	printf("Fille dMatrices!\n");

	printf("Matrix a:\n");
	mtx_print(a);
	printf("Matrix b:\n");
	mtx_print(b);

	struct matrix* c = mtx_multiply(a, b);
	printf("Matrix c = a * b:\n");
	mtx_print(c);
	mtx_transpose(&a);
	printf("Transposed Matrix a:\n");
	mtx_print(a);

// 
// Testing Square Matrix Transpose
	struct matrix* sqr = mtx_new(2, 2);
	sqr->data[0][0] = 3.0;
	sqr->data[0][1] = 2.0;
	sqr->data[1][0] = 6.0;
	sqr->data[1][1] = 8.0;
	mtx_print(sqr);
	mtx_transpose(&sqr);
	mtx_print(sqr);

	struct matrix* sym = mtx_new(3, 3);
	sym->data[0][0] = 25.0;
	sym->data[0][1] = 5.0;
	sym->data[0][2] = 1.0;
	sym->data[1][0] = 1.0;
	sym->data[1][1] = -1.0;
	sym->data[1][2] = 1.0;
	sym->data[2][0] = 4.0;
	sym->data[2][1] = 2.0;
	sym->data[2][2] = 1.0;

	struct matrix* ys = mtx_new(3, 1);
	ys = mtx_multiply(sym, ys);
	ys->data[0][0] = 3.0;
	ys->data[1][0] = 2.0;
	ys->data[2][0] = 0.0;
	mtx_print(ys);
	printf(" = \n");
	mtx_print(sym);
	printf("[Coefficients: ax^2 + yx + c]\n");


	struct matrix* inv = mtx_rref(sym);
	printf("This is the inversion matrix for sym\n");
	mtx_print(inv);
	
	printf("This is the identity matrix?\n");
	struct matrix* idd = mtx_multiply(inv, sym);
	mtx_print( idd );

	struct matrix* coeffs = mtx_new(3, 1);
	coeffs = mtx_multiply(inv, ys);

	printf("Coefficient solution is\n");
	mtx_print(coeffs);

	return 0;
}
