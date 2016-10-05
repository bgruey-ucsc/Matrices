/*  Print a matrix to out.  */

#include "matrix.h"


void
mtx_print (FILE* out, struct matrix *m)
{
    size_t row, col;

    for (row = 0; row < m->rows; row++) {
	for (col = 0; col < m->cols; col++)
	    fprintf (out, "%.3f\t", m->data[row][col]);
	fprintf (out, "\n");
    } // end row loop
}
