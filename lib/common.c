/* Definitions of internal functions.  */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Allocate some memory.  Checks that everything worked out fine, so
   you don't have to.  */
void *
_xmalloc (size_t size)
{
  void *buf = malloc (size);

  if (buf == NULL) {
    // No use in continuing on.
    fprintf (stderr, "Out of memory!\n");
    exit (EXIT_FAILURE);
  }

  return buf;
}

/* Allocate some memory and clear it.  */
void *
_xcalloc (size_t count, size_t eltsize)
{
  void *buf;
  size_t size = count * eltsize;

  buf = _xmalloc (size);

  // Assume it never fails?
  memset (buf, '\0', size);

  return buf;
}
