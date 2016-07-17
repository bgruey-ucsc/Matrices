/* Transpose a matrix.  If the matrix is square, the values are
   swapped.  If the matrix is not square, a new matrix is created,
   copied over and original deleted.  */

#include "matrix.h"

void
mtx_transpose (struct matrix **m)
{
    size_t i, j;
    if ((*m)->rows == (*m)->cols) // square matrix
    {
	double temp = 0.0;
	for (i = 0; i < (*m)->rows; i++)
	    for (j = 0; j < i; j++) 
	    {
		temp = (*m)->data[i][j];
		(*m)->data[i][j] = (*m)->data[j][i];
		(*m)->data[j][i] = temp;
	    } // end j: loop across columns
    } //end if: matrix was square

    else // not a square
    {
	struct matrix *mm = mtx_new ((*m)->cols, (*m)->rows);

	for (i = 0; i < (*m)->rows; i++)
	    for (j = 0; j < (*m)->cols; j++)
		mm->data[j][i] = (*m)->data[i][j];

	mtx_delete (*m);
	*m = mm; // thus needed pass by reference
    } // end else: matrix was not square
}
