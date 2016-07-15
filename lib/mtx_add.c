/* Add matrices.  m3 = m1 + [weight] * m2.  
   Returns m3, null if dimensions do not match.  */

#include "matrix.h"

struct matrix *
mtx_add (struct matrix *m1, struct matrix *m2, double weight)
{
    if (m1->rows != m2->rows || m1->cols != m2->cols) {
	fprintf (stderr, "Mistmatched Matrix Dimensions! %p, %p\n", m1, m2);
	return 0;
    }

    struct matrix *m3 = mtx_new (m1->rows, m1->cols);
    size_t i, j;
    for (i = 0; i < m1->rows; i++)
	for (j = 0; j < m1->cols; j++)
	    m3->data[i][j] = m1->data[i][j] + weight * m2->data[i][j];

    return m3;
}
