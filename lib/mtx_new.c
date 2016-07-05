/* Make a new matrix ROWS rows by COLUMNS columns, elements
   initialized to zero.  */

#include "common.h"
#include "matrix.h"

struct matrix *
mtx_new (size_t rows, size_t columns)
{
    size_t i;
    struct matrix *m;

    m = (struct matrix *) _xmalloc (sizeof (struct matrix));

    m->rows = rows;
    m->cols = columns;

    // C is row-major
    m->data = (double **) _xmalloc (rows * sizeof (double *));

    for (i = 0; i < rows; ++i)
      m->data[i] = (double *) _xcalloc (columns, sizeof (double));

    return m;
}
