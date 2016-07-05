/* Get a column vector.  A row vector using column [col] and rows
   [low] to [high] includes low row, does not include high row else
   cannot use matrix->rows as [high] */

#include "matrix.h"

struct matrix *
mtx_get_col_vector (struct matrix *m, size_t low, size_t high, size_t col)
{
    size_t dim = m->rows; // dimension of vector
    struct matrix *v = mtx_new (dim, 1);
    size_t i;

    for (i = low; i < high; i++)
	v->data[i][0] = m->data[i][col];

    return v;
}
