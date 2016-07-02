/*
		Matrix Library! 

// Multiply two matrices together
// first check that the matrices have appropriate dimensions.
// Then brute force, any other way?
struct matrix* mtx_multiply( struct matrix* a, struct matrix* b);


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


*/


#include "matrix.h"



// Multiply two matrices together
// first check that the matrices have appropriate dimensions.
// Then brute force, any other way?
// returns 0 if the matrices had incompatible dimensions
struct matrix* 
mtx_multiply( struct matrix* a, struct matrix* b) 
{	
	struct matrix* m = mtx_new(a->rows, b->cols);

	if (a->cols != b->rows) {
		fprintf(stderr, "Incompatible dimensions for matrices %p and %p.\n", a, b);
		return 0;
	} // end if: checking matrix dimensions

	int row, col, add;
	for (row = 0; row < m->rows; row++ )
		for ( col = 0; col < m->rows; col++ )
			for ( add = 0; add < b->rows; add++ )
				m->data[row][col] += a->data[row][add] * b->data[add][col];

	return m;
}

