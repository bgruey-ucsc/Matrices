/*
		Matrix Library! 


// Get a row vector.
// a row vector using row [row] and columns [low] to [high]
// includes low column, not high
struct matrix* mtx_get_row_vector(struct matrix* m, int low, int high, int row);


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


// Get a row vector.
// a row vector using row [row] and columns [low] to [high]
// includes low columns, but not high column
struct matrix* 
mtx_get_row_vector( struct matrix* m, int low, int high, int row) 
{
	int dim = m->cols; // dimension of vector
	struct matrix* v = mtx_new( 1, dim );
	int i;

	for ( i = low; i < high; i++ ) 
		v->data[0][i] = m->data[row][i];

	return v;
}

