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
struct matrix* New_Matrix(int rows, int columns);


// Delete all the data of a matrix
// Does not delete the pointer though, m still exists
void Delete_Matrix(struct matrix* m);


// Make an identity matrix of dimension dim
struct matrix* Id_Matrix(int dim);


//Copy the matrix
// Return the copy
struct matrix* Copy_Matrix(struct matrix* m);


// Multiply two matrices together
// first check that the matrices have appropriate dimensions.
// Then brute force, any other way?
struct matrix* Mult_Matrix( struct matrix* a, struct matrix* b);


// Add Matrices
// m1 = m1 + [weight] * m2
// returns 1 if dimensions are mistmatched
// zero else
int Add_Matrix(struct matrix* m1, struct matrix* m, double weight);


// Matrix Print
// Print to standard out
void Print_Matrix(struct matrix* m);


// Diagonalize Symmetric
// Assume the matrix is symmetric. That is the user's job to check.
/***
	Currently writing sub routines
*/




// Get a column vector.
// col == true -> a column vector using column [col] and rows [low] to [high]
// includes low and high rows
struct matrix* Get_Cvector(struct matrix* m, int low, int high, int col);


// Get a row vector.
// a row vector using row [row] and columns [low] to [high]
// includes low and high rows
struct matrix* Get_Rvector(struct matrix* m, int low, int high, int row);


// Norm of a vector, squared
// to not waste time computing square root if we don't need to
double Get_Norm2(struct matrix* m);


// transpose a matrix
// if the matrix is square, the values are swapped
// if the matrix is not square, a new matrix is created, copied over and original deleted
void Transpose_Matrix( struct matrix** m);

// Householder Step
// step from n to 1, assumed
struct matrix* Householder_Step(struct matrix* m, int step);













