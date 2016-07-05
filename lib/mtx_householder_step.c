/* Householder Step.  Assuming step goes from m->rows to 1 in Householder Loop.  */

/* CURRENTLY BROKEN. */

#include "matrix.h"

struct matrix *
mtx_householder_step (struct matrix *m, int step)
{
    // vector for outer product
    struct matrix *u = mtx_get_col_vector (m, step, m->rows, step);
    double u_norm = mtx_vector_norm2 (u);
    //updating to proper definition
    u->data[step][0] = u->data[step][0] - sqrt (u_norm);
    mtx_print (u);
    u_norm = mtx_vector_norm2 (u);
    // This is one the u we wanted for page 595 of Thijssen

    struct matrix *u_T = mtx_copy (u); // make a copy of u vector
    mtx_transpose (&u_T);
    struct matrix *uu_T = mtx_multiply (u, u_T);
    struct matrix *hhst = mtx_identity (uu_T->rows);
    mtx_add (hhst, uu_T, -2.0 / u_norm);

    return hhst;
}
