/*
		Matrix Library! 


// New Matrix
// Make a new matrix, elements initialized to zero
struct matrix* mtx_new(int rows, int columns);

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


// Make a new matrix that is rows by columns
struct matrix* 
mtx_new(int rows, int columns) 
{
	struct matrix* m = (struct matrix*)calloc(1, sizeof(struct matrix));

	m->rows = rows;
	m->cols = columns;
	m->data = (double**)calloc(rows, sizeof(double*));
	int i;
	for (i = 0;  i < rows; i++ ) 
		m->data[i] = (double*)calloc(columns, sizeof(double));

	return m;
}

