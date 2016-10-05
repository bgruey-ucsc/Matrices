/* Defines the matrix struct and associated functions.  */

#ifndef _MATRIX_BRUTUS_
#define _MATRIX_BRUTUS_

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

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
// m3 = m1 + [weight] * m2
// returns 0 if dimensions are mistmatched
// pointer to m3 if not
struct matrix *mtx_add (struct matrix *m1, struct matrix *m, double weight);

/*  Increment Matrix
    m1 = m1 + weight * m2
    return 0 if dimensions of m1 and m2 did not match
    returns 1 else */
int mtx_increment (struct matrix *m1, struct matrix *m2, double weight);

// Matrix Print
// Print to standard out
void mtx_print (struct matrix *m);

/*
 *  print matrix to out
 */
void mtx_print_o (FILE* out, struct matrix *m);


/*  Load Matrix from File
    Reads a matrix from a tab or comma separated list in ascii characters
    returns the matrix, or exits program if
    file could not be opened or extra white space was found at end of file. */
struct matrix *mtx_load_from_file (const char* file_name);

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
struct matrix * mtx_transpose (struct matrix *m);


// Householder Step
// step from n to 1, assumed
struct matrix *mtx_householder_step (struct matrix *m, int step);


// reduces a square matrix to the identity matrix
// returns the same row operation on an identiy matrix, could be inverse
// currently does not check for non-intertibility.
struct matrix *mtx_rref (struct matrix *m_in);


/*
 * Graham Schmidt Orthonormalization of Matrix
 * returns a matrix whose columns are the orthonormal
 * basis of the argument matrix column vectors.
 *
 * Does not check for Uniqueness.
 */
struct matrix *mtx_gs_col (struct matrix* m);


/**********************************************************
 *  Vector Functions
 *
 *  These functions expect row or column vector matrices
 *  and return zero/ NULL if this is not the case.
 **********************************************************/ 

/*
 *  Dot product
 *  returns the dot product of two row vectors or two column vectors
 */
float mtx_dot (struct matrix *v1, struct matrix *v2);

/*
 * Normalize Vector
 * returns a normalized version of the supplied vector.
 * vector v can be rows or columns.
 */
struct matrix *mtx_normalize (struct matrix *v);



#endif /* _MATRIX_BRUTUS */
