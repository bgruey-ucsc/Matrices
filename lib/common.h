/* Common routines for internal use.  */

#ifndef _MATRIX_COMMON
#define _MATRIX_COMMON

#include <stddef.h>

void *_xmalloc (size_t size);
void *_xcalloc (size_t count, size_t eltsize);

#endif /* _MATRIX_COMMON */
