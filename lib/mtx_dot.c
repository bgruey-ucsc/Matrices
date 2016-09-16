/* Norm of a vector, squared, to not waste time computing square root
   if we don't need to.  */

#include "matrix.h"

float
mtx_dot (struct matrix *v1, struct matrix *v2)
{
    float dot = 0.0;
    size_t i;
    if ((v1->rows != v2->rows) || (v1->cols != v2->cols))
    {
        fprintf (stderr, "mtx_dot:\nVector dimensions do not match. Returning zero.\n");
        return 0.0;
    }
    // row vector
    if (v1->rows == 1) 
    {
	for (i = 0; i < v1->cols; i++)
	    dot += v1->data[0][i] * v2->data[0][i];
	return dot;
    } // end row vector case

    // column vector
    else if (v1->cols == 1) 
    {
	for (i = 0; i < v1->rows; i++)
	    dot += v1->data[i][0] * v2->data[i][0];
	return dot;
    } // end column vector case

    else 
    {
	fprintf (stdout, "Matrices, not a vector: %p, %p\nHopefully you weren't dividing by that, because I returned zero.\n", v1, v2);
	return 0.0;
    }
}
