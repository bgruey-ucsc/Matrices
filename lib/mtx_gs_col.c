/*
 *  Graham-Schmidt Orthonomalization of the Coumns Vectors
 *
 *  Does not test for uniqueness.
 *
 *  Likely this should be applied to an array of vectors
 *  rather than a amtrix.
 *
 *  Also, the naming scheme in here is _aweful_
 *          happy reading!
 *
 */

#include "matrix.h"

struct matrix *
mtx_gs_col (struct matrix *m)
{
    struct matrix *ptr = NULL;

    size_t col;
    struct matrix **vecs = (struct matrix**) calloc (m->cols, sizeof(struct matrix*));

    for (col = 0; col < m->cols; col++)
        vecs[col] = mtx_get_col_vector (m, 0, m->rows, col);

    int vec, row;

    ptr = mtx_normalize (vecs[0]);
    mtx_delete (vecs[0]);
    vecs[0] = ptr;
    ptr = NULL;
  
  
    int vec_it; 
    struct matrix *v1 = NULL;
    struct matrix *v2 = NULL;
    for (vec = 1; vec < (int)m->cols; vec++) /* GS each vector */
    {
        v1 = mtx_copy (vecs[vec]);
        for (vec_it = vec-1; vec_it >-1; vec_it -= 1)
        {
            v2 = mtx_add (v1, vecs[vec_it], -mtx_dot (vecs[vec], vecs[vec_it]));
            mtx_delete (v1);
            v1 = v2;
        }/*end for vec_it */

        mtx_delete (vecs[vec]);
        vecs[vec] = mtx_normalize (v2);
        v2 = NULL;

    }/* end for vec */

    struct matrix *ret = mtx_new (m->rows, m->cols);
    
    for (vec = 0; vec < m->cols; vec++)
        for (row = 0; row < m->rows; row++)
            ret->data[row][vec] = vecs[vec]->data[row][0];

    return ret;

}/*end mtx_gs_col*/
