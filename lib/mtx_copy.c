/* Copy the matrix.  Return a pointer to the copy.  */

#include "matrix.h"

struct matrix *
mtx_copy (struct matrix *m)
{
	struct matrix *cpy = mtx_new (m->rows, m->cols);

	size_t i, j;
	for (i = 0; i < m->rows; i++)
		for (j = 0; j < m->cols; j++)
			cpy->data[i][j] = m->data[i][j];

	return cpy;
}
