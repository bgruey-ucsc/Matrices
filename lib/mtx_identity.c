/* Make an identity matrix of dimension DIM.  */

#include "matrix.h"

struct matrix *
mtx_identity (size_t dim)
{
    struct matrix *m = mtx_new (dim, dim);

    size_t i;
    for (i = 0; i < dim; i++)
	m->data[i][i] = 1.0;

    return m;
}
