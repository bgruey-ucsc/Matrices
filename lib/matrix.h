/* Defines the matrix struct and associated functions.  */

#ifndef _MATRIX_BRUTUS_
#define _MATRIX_BRUTUS_

#include "math.h"
#include "stdio.h"
#include "stdlib.h"

/* Struct.  */

struct matrix {
	size_t rows, cols;
	double **data;
};


/* Functions.  */

// New Matrix
// Make a new matrix, elements initialized to zero
struct matrix *mtx_new (size_t rows, size_t columns);


// Delete all the data of a matrix
// Does not delete the pointer though, m still exists
void mtx_delete (struct matrix *m);


// Make an identity matrix of dimension dim
struct matrix *mtx_identity (size_t dim);


//Copy the matrix
// Return the copy
struct matrix *mtx_copy (struct matrix *m);


// Multiply two matrices together
// first check that the matrices have appropriate dimensions.
// Then brute force, any other way?
struct matrix *mtx_multiply (struct matrix *a, struct matrix *b);


// Add Matrices
// m1 = m1 + [weight] * m2
// returns 1 if dimensions are mistmatched
// zero else
int mtx_add (struct matrix *m1, struct matrix *m, double weight);


// Matrix Print
// Print to standard out
void mtx_print (struct matrix *m);


// Diagonalize Symmetric
// Assume the matrix is symmetric. That is the user's job to check.
/***
	Currently writing sub routines
*/


// Get a column vector.
// col == true -> a column vector using column [col] and rows [low] to [high]
// includes low row, not  high
struct matrix *mtx_get_col_vector (struct matrix *m, size_t low, size_t high, size_t col);


// Get a row vector.
// a row vector using row [row] and columns [low] to [high]
// includes low column, not high
struct matrix *mtx_get_row_vector (struct matrix *m, size_t low, size_t high, size_t row);


// Norm of a vector, squared
// to not waste time computing square root if we don't need to
double mtx_vector_norm2 (struct matrix *m);


// transpose a matrix
// if the matrix is square, the values are swapped
// if the matrix is not square, a new matrix is created, copied over and original deleted
void mtx_transpose (struct matrix **m);


// Householder Step
// step from n to 1, assumed
struct matrix *mtx_householder_step (struct matrix *m, int step);


// reduces a square matrix to the identity matrix
// returns the same row operation on an identiy matrix, could be inverse
// currently does not check for non-intertibility.
struct matrix *mtx_rref (struct matrix *m_in);


#endif /* _MATRIX_BRUTUS */
