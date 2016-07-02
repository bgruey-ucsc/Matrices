/*
		Matrix Library! 


Add Matrices
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


// reduced row echelon form of matrix m
// returns m in rref form if inv = 0
// else returns the inverse of the matrix, may or may not be valid
// if inv != 0, the m is assumed to be square.

struct matrix*
mtx_rref ( struct matrix* m_in)
{
	struct matrix* m = mtx_copy(m_in);
	struct matrix* m_inv = mtx_identity(m->rows);
	// remove lower diagonal of the matrix, ie. set to zero by row operations
	int sum_row, i, j;
	float scale = 0.0;
	for ( sum_row = 0; sum_row < m->rows - 1; sum_row++) // all but the bottom row will be added to the lower row
	{
		for ( i = sum_row + 1; i < m->rows; i++) // each of the lower rows will get added to by the sum_row row
		{
			for ( j = 0; j < m->cols; j++) // sum each element of the row, ignoring zeroes reduces roundoff error, maybe?
			{

			scale = m->data[i][sum_row] / m->data[sum_row][sum_row];

			m->data[i][j] = m->data[i][j] - scale * m->data[sum_row][j];

			m_inv->data[i][j] = m_inv->data[i][j] - scale * m_inv->data[sum_row][j];

			} // end of j
		} // end for i
	} // end for sum_row
	printf("Removed zeroes below?\n");
	mtx_print(m);
	mtx_print(m_inv);
	// remove upper portion
	for ( sum_row = m->rows-1; sum_row > 0; sum_row--) // all but the top row will be added to the upper row
	{
		for ( i = sum_row - 1; i > -1; i--) // each of the lower rows will get added to by the sum_row row
		{
			for ( j = 0; j < m->cols; j++) // sum each element of the row, need all for inverse matrix
			{

				scale = m->data[i][sum_row] / m->data[sum_row][sum_row];

				m->data[i][j] = m->data[i][j] - scale * m->data[sum_row][j];

				m_inv->data[i][j] = m_inv->data[i][j] - scale * m_inv->data[sum_row][j];

			} // end of j
		} // end for i
	} // end for sum_row
	printf("Removed zeroes above?\n");
	mtx_print(m);
	mtx_print(m_inv);

	for ( i = 0; i < m->rows; i++ )
	{
		scale = 1.0 / m->data[i][i];
		for( j = 0; j < m->cols; j++)
			m->data[i][j] *= scale;
			m_inv->data[i][j] *= scale;
	} // end for i

	printf("Identity??\n");
	mtx_print(m);
	mtx_print(m_inv);

	return m_inv;
}



















