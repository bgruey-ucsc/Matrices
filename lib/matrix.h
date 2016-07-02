#ifndef _MATRIX_BRUTUS_
#define _MATRIX_BRUTUS_

/*
		Matrix Library! 

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

/*
		Current design considerations:

			Make all matrix operations behave the same way? All return a pointer to a matrix that is the result
				includes: multiply, add, transpose, etc.
				this way the user knows exactly how to expect every function to work.
				I think that's a good idea


*/


/*
 		Coding Design Considerations
 
	***
 	Using structures, which form?

		typedef struct { // Stuff } matrix;
	or
		struct matrix { // stuff };
 
	***
	Use a namespace? Does anyone ever actually use a namespace? 

	
*/

#include "math.h"
#include "stdio.h"
#include "stdlib.h"
/*
	Matrix struct and associated functions for manipulations.

	Matrix of doubles, initizialized to zero.
*/

// Matrix Struct

struct matrix {
	int rows, cols;

	double** data;
};


/*
	Functions
*/

// New Matrix
// Make a new matrix, elements initialized to zero
struct matrix* mtx_new(int rows, int columns);


// Delete all the data of a matrix
// Does not delete the pointer though, m still exists
void mtx_delete(struct matrix* m);


// Make an identity matrix of dimension dim
struct matrix* mtx_identity(int dim);


//Copy the matrix
// Return the copy
struct matrix* mtx_copy(struct matrix* m);


// Multiply two matrices together
// first check that the matrices have appropriate dimensions.
// Then brute force, any other way?
struct matrix* mtx_multiply( struct matrix* a, struct matrix* b);


// Add Matrices
// m1 = m1 + [weight] * m2
// returns 1 if dimensions are mistmatched
// zero else
int mtx_add(struct matrix* m1, struct matrix* m, double weight);


// Matrix Print
// Print to standard out
void mtx_print(struct matrix* m);


// Diagonalize Symmetric
// Assume the matrix is symmetric. That is the user's job to check.
/***
	Currently writing sub routines
*/




// Get a column vector.
// col == true -> a column vector using column [col] and rows [low] to [high]
// includes low row, not  high
struct matrix* mtx_get_col_vector(struct matrix* m, int low, int high, int col);


// Get a row vector.
// a row vector using row [row] and columns [low] to [high]
// includes low column, not high
struct matrix* mtx_get_row_vector(struct matrix* m, int low, int high, int row);


// Norm of a vector, squared
// to not waste time computing square root if we don't need to
double mtx_vector_norm2(struct matrix* m);


// transpose a matrix
// if the matrix is square, the values are swapped
// if the matrix is not square, a new matrix is created, copied over and original deleted
void mtx_transpose( struct matrix** m);

// Householder Step
// step from n to 1, assumed
struct matrix* mtx_householder_step(struct matrix* m, int step);










// reduced row echelon form of matrix m
// returns m in rref form if inv = 0
// else returns the inverse of the matrix, may or may not be valid
// if inv != 0, the m is assumed to be square.
struct matrix* rref ( struct matrix* m, int inv);


#endif
