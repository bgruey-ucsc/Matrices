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
 

  *** 	Using structures, which form?

		typedef struct { // Stuff } matrix;
	or
		struct matrix { // stuff };
 
	
  ***	Use a namespace? Does anyone ever actually use a namespace? 

  ***	Pointer to a pointer in order to pass by reference? See Transpose_Matrix.

*/

#include "lib/matrix.h"


// Make a new matrix that is rows by columns
struct matrix* 
mtx_new(int rows, int columns) 
{
	struct matrix* m = (struct matrix*)calloc(1, sizeof(struct matrix));

	m->rows = rows;
	m->cols = columns;
	m->data = (double**)calloc(rows, sizeof(double*));
	int i;
	for (i = 0;  i < rows; i++ ) 
		m->data[i] = (double*)calloc(columns, sizeof(double));

	return m;
}


// Delete all the data of a matrix
// Does not delete the pointer though,
// that's your job.
void 
mtx_delete(struct matrix* m) 
{
	int i = 0;
	for ( i = 0; i < m->rows; i++) 
		free(m->data[i]); // arrays of column entries

	free(m->data); // array of rows
	free(m); // rows, cols and data
}



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



// Multiply two matrices together
// first check that the matrices have appropriate dimensions.
// Then brute force, any other way?
// returns 0 if the matrices had incompatible dimensions
struct matrix* 
mtx_multiply( struct matrix* a, struct matrix* b) 
{	
	struct matrix* m = mtx_new(a->rows, b->cols);

	if (a->cols != b->rows) {
		fprintf(stderr, "Incompatible dimensions for matrices %p and %p.\n", a, b);
		return 0;
	} // end if: checking matrix dimensions

	int row, col, add;
	for (row = 0; row < m->rows; row++ )
		for ( col = 0; col < m->rows; col++ )
			for ( add = 0; add < b->rows; add++ )
				m->data[row][col] += a->data[row][add] * b->data[add][col];

	return m;
}


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


// Matrix Print
// Print to standard out
void 
mtx_print(struct matrix* m)
{
	int row, col;
	printf("Matrix %p, %dx%d\n", m, m->rows, m->cols);

	for ( row = 0; row < m->rows; row++ )
		{
			for ( col = 0; col < m->cols; col++ )
				fprintf(stdout, "%f\t", m->data[row][col]);
			fprintf(stdout, "\n");
		} // end row loop
}


// Diagonalize Symmetric
// Assume the matrix is symmetric. That is the user's job to check.





// Get a column vector.
// a row vector using column [col] and rows [low] to [high]
// includes low row, does not include high row
// else cannot use matrix->rows as [high]
struct matrix* 
mtx_get_col_vector( struct matrix* m, int low, int high, int col) 
{
	int dim = m->rows; // dimension of vector
	struct matrix* v = mtx_new( dim, 1 );
	int i;

	for ( i = low; i < high; i++ ) 
		v->data[i][0] = m->data[i][col];

	return v;
}

// Get a row vector.
// a row vector using row [row] and columns [low] to [high]
// includes low columns, but not high column
struct matrix* 
mtx_get_row_vector( struct matrix* m, int low, int high, int row) 
{
	int dim = m->cols; // dimension of vector
	struct matrix* v = mtx_new( 1, dim );
	int i;

	for ( i = low; i < high; i++ ) 
		v->data[0][i] = m->data[row][i];

	return v;
}


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
