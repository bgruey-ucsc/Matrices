/*  Print a matrix to stdout.  */

#include "matrix.h"

#define OUT_STREAM stdout

void
mtx_print (struct matrix *m)
{
    size_t row, col;
    printf ("Matrix %p, %zux%zu\n", m, m->rows, m->cols);

    for (row = 0; row < m->rows; row++) {
	for (col = 0; col < m->cols; col++)
            if (m->data[row][col] < 0.0)
        	fprintf (OUT_STREAM, "%.3e\t", m->data[row][col]);
            else
        	fprintf (OUT_STREAM, "%.4e\t", m->data[row][col]);
	fprintf (OUT_STREAM, "\n\n");
    } // end row loop
}
