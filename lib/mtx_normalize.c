/* Norm of a vector, squared, to not waste time computing square root
   if we don't need to.  */

#include "matrix.h"

struct matrix *
mtx_normalize (struct matrix *v)
{
    struct matrix *v_ret = mtx_copy (v);
    double inv_norm = 1.0 / sqrt (mtx_vector_norm2 (v_ret) );
    size_t i;
    // row vector
    if (v_ret->rows == 1) 
    {
	for (i = 0; i < v_ret->cols; i++)
	    v_ret->data[0][i] *= inv_norm;
	return v_ret;
    } // end row vector case

    // column vector
    else if (v_ret->cols == 1) 
    {
	for (i = 0; i < v_ret->rows; i++)
	    v_ret->data[i][0] *= inv_norm;
	return v_ret;
    } // end column vector case

    else 
    {
	fprintf (stdout, "Matrix, not a vector: %p\nHopefully you weren't dividing by that, because I returned zero.\n", v);
	return NULL;
    }
}
