/*
		Matrix Library! 

// Make an identity matrix of dimension dim
struct matrix* mtx_identity(int dim);

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


// Make an identity matrix of dimension dim
// dim by dim identity matrix
struct matrix* 
mtx_identity(int dim) 
{
	struct matrix* m = mtx_new(dim, dim);

	int i;
	for ( i = 0; i < dim; i++ )
		m->data[i][i] = 1.0;

	return m;
}

