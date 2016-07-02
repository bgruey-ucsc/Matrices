/*
		Matrix Library! 

// Norm of a vector, squared
// to not waste time computing square root if we don't need to
double mtx_vector_norm2(struct matrix* m);


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



// Norm of a vector, squared
// to not waste time computing square root if we don't need to
double 
mtx_vector_norm2( struct matrix* m) 
{
	double norm = 0.0;
	int i;
	// row vector
	if (m->rows == 1) {
		for (i = 0; i < m->cols; i++ ) 
			norm += pow( m->data[0][i], 2.0);
		return norm;
	} // end row vector case

	// column vector
	else if (m->cols == 1) {
		for ( i = 0; i < m->rows; i++) 
			norm += pow( m->data[i][0], 2.0);
		return norm;
	}// end column vector case

	else {
		fprintf(stdout, "Matrix, not a vector: %p\nHopefully you weren't dividing by that, because I returned zero.\n", m);
		return 0.0;
	}
	
}

