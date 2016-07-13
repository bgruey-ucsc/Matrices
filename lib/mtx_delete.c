/* Delete a matrix, freeing the memory originally allocated to it.  */

#include "matrix.h"

void
mtx_delete (struct matrix *m)
{
	size_t i;

	// arrays of column entries
	for (i = 0; i < m->rows; i++)
		free (m->data[i]);
	free (m->data); // array of rows
	free (m); // rows, cols and data
	m = NULL;
}
