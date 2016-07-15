/*  Read a matrix from a text file.
    Returns a pointer to the matrix. */


#include "matrix.h"
#include <string.h>

#define DELIMS "\t ,"

struct matrix *
mtx_load_from_file (const char* file_name)
{
    /* Open file, check success. */
    FILE *in_m = fopen(file_name, "r");
    if (in_m == NULL)
    {
        fprintf(stderr, "Unable to open file:\n%s\n", file_name);
        exit(1);
    }

    /* Read number of lines (rows) in file. */
    char *line = NULL;
    size_t rows = 0;
    size_t len = 0;
    while (getline (&line, &len, in_m) != -1)
        rows++;

    /* Check the last line of the file contains data. */
    size_t cols = 0;
    if (strtok (line, DELIMS) != NULL)
        cols++;
    else
    {
        fprintf (stderr, "Last line did not contain data. Extra whitespace in file?\n%s\n"
            , file_name);
        exit(1); /* Or return NULL? */
    }

    /* Read last line to get number of columns. */
    while (strtok (NULL, DELIMS) != NULL)
        cols++;

    fclose (in_m);
    free (line);
    line = NULL;

    in_m = fopen (file_name, "r");

    char **row_array = (char**)calloc (cols, sizeof(char*));
    struct matrix *m = mtx_new (rows, cols);
    int i,j;
    for (i = 0; getline(&line, &len, in_m) != -1; i++)
    {
        m->data[i][0] = atof (strtok(line, DELIMS));
        for (j = 1; (row_array[j] = strtok(NULL, DELIMS)) != NULL; j++)
            m->data[i][j] = atof (row_array[j]);
    }

    return m;
}















