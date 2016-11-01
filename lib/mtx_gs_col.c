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

    int col;
    int m_cols = (int)m->cols;
    int m_rows = (int)m->rows;

    struct matrix **vecs = (struct matrix**) calloc (m->cols, sizeof(struct matrix*));

    for (col = 0; col < (int)m->cols; col++)
        vecs[col] = mtx_get_col_vector (m, 0, m->rows, col);

    int vec, row;

    ptr = mtx_normalize (vecs[0]);
    mtx_delete (&vecs[0]);
    vecs[0] = ptr;
    ptr = NULL;
  
  
    int vec_it; 
    struct matrix *v1 = NULL;
    struct matrix *v2 = NULL;
    for (vec = 1; vec < m_cols; vec++) /* GS each vector */
    {
        v1 = mtx_copy (vecs[vec]);
        for (vec_it = vec-1; vec_it >-1; vec_it -= 1)
        {
            v2 = mtx_add (v1, vecs[vec_it], -mtx_dot (vecs[vec], vecs[vec_it]));
            mtx_delete (&v1);
            v1 = v2;
        }/*end for vec_it */

        mtx_delete (&vecs[vec]);
        vecs[vec] = mtx_normalize (v2);
        v2 = NULL;

    }/* end for vec */

    struct matrix *ret = mtx_new (m->rows, m->cols);
    
    for (vec = 0; vec < m_cols; vec++)
        for (row = 0; row < m_rows; row++)
            ret->data[row][vec] = vecs[vec]->data[row][0];
/*
    for (vec = 0; vec < m_cols; vec++)
    {
        for(vec_it = 0; vec_it < m_cols; vec_it++)
        {
            printf ("Dot prod of (%d, %d): %1.5e\n", vec, vec_it, mtx_dot (vecs[vec], vecs[vec_it]));
        }
    }
*/
    return ret;

}/*end mtx_gs_col*/
