/* Transpose a matrix. 
 *
 * Returns the transposed matrix.
 */ 

#include "matrix.h"

struct matrix*
mtx_transpose (struct matrix *m)
{
    struct matrix *ret = mtx_new (m->cols, m->rows);

    size_t i, j;

    for (i = 0; i < m->rows; i++)
        for (j = 0; j < m->cols; j++)
	    ret->data[j][i] = m->data[i][j];

    return ret;
}
