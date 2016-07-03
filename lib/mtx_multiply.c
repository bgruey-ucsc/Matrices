/* Multiply two matrices together.  First check that the matrices have
   appropriate dimensions.  Then brutus-force, any other way?  Returns
   0 if the matrices had incompatible dimensions.  */

#include "matrix.h"

struct matrix *
mtx_multiply (struct matrix *a, struct matrix *b)
{
	struct matrix *m = mtx_new (a->rows, b->cols);

	if (a->cols != b->rows) {
		fprintf (stderr, "Incompatible dimensions for matrices %p and %p.\n", a, b);
		return 0;
	} // end if: checking matrix dimensions

	int row, col, add;
	for (row = 0; row < m->rows; row++)
		for (col = 0; col < m->rows; col++)
			for (add = 0; add < b->rows; add++)
				m->data[row][col] += a->data[row][add] * b->data[add][col];

	return m;
}
