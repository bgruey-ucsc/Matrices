/*
		Matrix Library! 

//Copy the matrix
// Return the copy
struct matrix* mtx_copy(struct matrix* m); 


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


//Copy the matrix
// Return a pointer to the copy
struct matrix* 
mtx_copy(struct matrix* m) 
{	
	struct matrix* cpy = mtx_new( m->rows, m->cols);

	int i, j;
	for ( i = 0;  i < m->rows; i++) 
		for ( j = 0; j < m->cols; j++)
			cpy->data[i][j] = m->data[i][j];

	return cpy;
}

