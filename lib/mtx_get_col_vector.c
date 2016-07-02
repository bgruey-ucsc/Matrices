/*
		Matrix Library! 

// Get a column vector.
// col == true -> a column vector using column [col] and rows [low] to [high]
// includes low row, not  high
struct matrix* mtx_get_col_vector(struct matrix* m, int low, int high, int col);


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


// Get a column vector.
// a row vector using column [col] and rows [low] to [high]
// includes low row, does not include high row
// else cannot use matrix->rows as [high]
struct matrix* 
mtx_get_col_vector( struct matrix* m, int low, int high, int col) 
{
	int dim = m->rows; // dimension of vector
	struct matrix* v = mtx_new( dim, 1 );
	int i;

	for ( i = low; i < high; i++ ) 
		v->data[i][0] = m->data[i][col];

	return v;
}
