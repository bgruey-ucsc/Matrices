/* Get a row vector.  A row vector using row [row] and columns [low]
   to [high] includes low column, not high.  */

#include "matrix.h"

struct matrix *
mtx_get_row_vector (struct matrix *m, size_t low, size_t high, size_t row)
{
    size_t dim = m->cols; // dimension of vector
    struct matrix *v = mtx_new (1, dim);
    size_t i;

    for (i = low; i < high; i++)
	v->data[0][i] = m->data[row][i];

    return v;
}
