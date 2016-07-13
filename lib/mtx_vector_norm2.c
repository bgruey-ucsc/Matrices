/* Norm of a vector, squared, to not waste time computing square root
   if we don't need to.  */

#include "matrix.h"

double
mtx_vector_norm2 (struct matrix *m)
{
	double norm = 0.0;
	size_t i;
	// row vector
	if (m->rows == 1) {
		for (i = 0; i < m->cols; i++)
			norm += pow (m->data[0][i], 2.0);
		return norm;
	} // end row vector case

	// column vector
	else if (m->cols == 1) {
		for (i = 0; i < m->rows; i++)
			norm += pow (m->data[i][0], 2.0);
		return norm;
	} // end column vector case

	else {
		fprintf (stdout, "Matrix, not a vector: %p\nHopefully you weren't dividing by that, because I returned zero.\n", m);
		return 0.0;
	}
}
