/* Make a new matrix ROWS rows by COLUMNS columns, elements
   initialized to zero.  */

#include "matrix.h"

struct matrix *
mtx_new (int rows, int columns)
{
	struct matrix *m = (struct matrix *) calloc (1, sizeof (struct matrix));

	m->rows = rows;
	m->cols = columns;
	m->data = (double **) calloc (rows, sizeof (double *));
	int i;
	for (i = 0;  i < rows; i++ )
		m->data[i] = (double *) calloc (columns, sizeof (double));

	return m;
}
