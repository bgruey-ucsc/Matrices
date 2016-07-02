/*
		Matrix Library! 

// transpose a matrix
// if the matrix is square, the values are swapped
// if the matrix is not square, a new matrix is created, copied over and original deleted
void mtx_transpose( struct matrix** m);


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




// transpose a matrix
// if the matrix is square, the values are swapped
// if the matrix is not square, a new matrix is created, copied over and original deleted
void
mtx_transpose( struct matrix** m )
{
	int i, j;
	if ((*m)->rows == (*m)->cols) { // square matrix

		double temp = 0.0;
		for ( i = 0; i < (*m)->rows; i++) 
			for ( j = 0; j < i; j++ ) 
				{
					temp = (*m)->data[i][j];
					(*m)->data[i][j] = (*m)->data[j][i];
					(*m)->data[j][i] = temp;
				}// end j: loop across columns

	}//end if: matrix was square

	else{// not a square

		struct matrix* mm = mtx_new((*m)->cols, (*m)->rows);

		for ( i = 0; i < (*m)->rows; i++) 
			for ( j = 0; j < (*m)->cols; j++) 
				mm->data[j][i] = (*m)->data[i][j];
		
		mtx_delete(*m);
		(*m) = mm; // thus needed pass by reference

	}// end else: matrix was not square
}
