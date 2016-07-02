/*
		Matrix Library! 

CURRENTLY BROKEN

// Householder Step
// step from n to 1, assumed
struct matrix* mtx_householder_step(struct matrix* m, int step);

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


// Householder Step
// assuming step goes from m->rows to 1 in Householder Loop
struct matrix* 
mtx_householder_step( struct matrix* m, int step)
{
	// vector for outer product
	struct matrix* u = mtx_get_col_vector( m, step, m->rows, step);
	double u_norm = mtx_vector_norm2(u);
	//updating to proper definition
	u->data[step][0] = u->data[step][0] - sqrt(u_norm);
	mtx_print(u);
	u_norm = mtx_vector_norm2(u); 
	// This is one the u we wanted for page 595 of Thijssen

	struct matrix* u_T = mtx_copy(u); // make a copy of u vector
	mtx_transpose(&u_T);
	struct matrix* uu_T = mtx_multiply(u, u_T);
	struct matrix* hhst = mtx_identity(uu_T->rows);
	mtx_add(hhst, uu_T, -2.0 / u_norm);
	
	return hhst;
}
