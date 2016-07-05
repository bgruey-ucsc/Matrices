/* Reduces a square matrix to the identity matrix.  Returns the same
   row operation on an identiy matrix, could be inverse.  Currently
   does not check for non-intertibility.  */

/* CONFUSION IN CODE

   When the line

   scale = m->data[i][sum_row] / m->data[sum_row][sum_row];

   was inside the j loop, the algorithm did not produce the correct
   inverse matrix, though it did turn m_in into the idienty matrix.

   Why did this occur? No idea.  */

#include "matrix.h"

struct matrix *
mtx_rref (struct matrix *m_in)
{
    struct matrix *m = mtx_copy (m_in);
    struct matrix *m_inv = mtx_identity (m->rows);
    // remove lower diagonal of the matrix, ie. set to zero by row operations
    size_t sum_row, i, j;
    float scale = 0.0;
    for (sum_row = 0; sum_row < m->rows - 1; sum_row++) { // all but the bottom row will be added to the lower row
	for (i = sum_row + 1; i < m->rows; i++) { // each of the lower rows will get added to by the sum_row row
	    scale = m->data[i][sum_row] / m->data[sum_row][sum_row];

	    for (j = 0; j < m->cols; j++) { // sum each element of the row, ignoring zeroes reduces roundoff error, maybe?
		m->data[i][j] = m->data[i][j] - scale * m->data[sum_row][j];

		m_inv->data[i][j] = m_inv->data[i][j] - scale * m_inv->data[sum_row][j];
	    } // end of j
	} // end for i
    } // end for sum_row
    printf ("Removed zeroes below?\n");
    mtx_print (m);
    mtx_print (m_inv);
    // remove upper portion
    for (sum_row = m->rows-1; sum_row > 0; sum_row--) { // all but the top row will be added to the upper row
	for (i = sum_row - 1; i > -1; i--) { // each of the lower rows will get added to by the sum_row row
	    scale = m->data[i][sum_row] / m->data[sum_row][sum_row];

	    for (j = 0; j < m->cols; j++) { // sum each element of the row, need all for inverse matrix
		m->data[i][j] = m->data[i][j] - scale * m->data[sum_row][j];

		m_inv->data[i][j] = m_inv->data[i][j] - scale * m_inv->data[sum_row][j];
	    } // end of j
	} // end for i
    } // end for sum_row
    printf ("Removed zeroes above?\n");
    mtx_print (m);
    mtx_print (m_inv);

    for (i = 0; i < m->rows; i++) {
	scale = 1.0 / m->data[i][i];
	for (j = 0; j < m->cols; j++) {
	    m->data[i][j] *= scale;
	    m_inv->data[i][j] *= scale;
	}
    } // end for i

    printf ("Identity??\n");
    mtx_print (m);
    mtx_print (m_inv);

    return m_inv;
}
