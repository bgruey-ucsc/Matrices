/*  Print a matrix to stdout.  */

#include "matrix.h"

#define OUT_STREAM stdout

void
mtx_print(struct matrix* m)
{
	int row, col;
	printf("Matrix %p, %dx%d\n", m, m->rows, m->cols);

	for ( row = 0; row < m->rows; row++ )
		{
			for ( col = 0; col < m->cols; col++ )
				fprintf(OUT_STREAM, "%.3f\t", m->data[row][col]);
			fprintf(OUT_STREAM, "\n\n");
		} // end row loop
}
