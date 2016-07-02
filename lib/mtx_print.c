/*
		Matrix Library! 

// Matrix Print
// Print to standard out
void mtx_print(struct matrix* m);


	Started as a C library to solve a generalized eigenvalue problem,
	numerical approximations to quantum systems:

		[H] * [C] = E * [S] * [C]

	where brackets indicate matrices:
		H is the Mamiltonian
		C is the basis function coefficient matrix
		S is the generalized "______" matrix for non-orthogonal basis functions
			it would be the identity matrix if they were orthogonal
			this matrix should be symmetric

	The work started with the infinite square well approximation defined
	on page 29 of Jos Thijssen's second edition of Computational Physics

   This code will likely not erase your harddrive,
   but I make no guarantees.

      Benjamin "Brutus" Gruey
         July 2, 2016

*/


#include "matrix.h"
#define OUT_STREAM stdout

// Matrix Print
// Print to standard out
void 
mtx_print(struct matrix* m)
{
	int row, col;
	printf("Matrix %p, %dx%d\n", m, m->rows, m->cols);

	for ( row = 0; row < m->rows; row++ )
		{
			for ( col = 0; col < m->cols; col++ )
				fprintf(OUT_STREAM, "%.3f\t", m->data[row][col]);
			fprintf(OUT_STREAM, "\n\n");
		} // end row loop
}

