/* Delete all the data of a matrix.  Does not delete the pointer
   though, that's your job.  */

#include "matrix.h"

void
mtx_delete (struct matrix *m)
{
	size_t i = 0;
	for (i = 0; i < m->rows; i++)
		free (m->data[i]); // arrays of column entries

	free (m->data); // array of rows
	free (m); // rows, cols and data
}
