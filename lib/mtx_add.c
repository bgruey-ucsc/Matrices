/*
		Matrix Library! 

	mtx_add.c
		The add function.// Add Matrices
m1 = m1 + [weight] * m2
returns 1 if dimensions are mistmatched
zero else




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


// Add Matrices
// m1 = m1 + [weight] * m2
// returns 1 if dimensions are mistmatched
// zero else
int 
mtx_add(struct matrix* m1, struct matrix* m2, double weight) 
{
	if ( m1->rows != m2->rows || m1->cols != m2->cols ) {
		fprintf(stderr, "Mistmatched Matrix Dimensions! %p, %p\n", m1, m2);
		return 1;
	}

	int i, j;
	for ( i = 0; i < m1->rows; i++) 
		for ( j = 0; j < m1->cols; j++)
			m1->data[i][j] = m1->data[i][j] + weight * m2->data[i][j];

	return 0;
}
