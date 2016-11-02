/*

	Test program for Brutus' Matrix library.

	Likely there isn't a daemon somewhere in here that replaces your hard rive with zeros.

	Benjamin "Brutus" Gruey
		July 2, 2016


*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../lib/matrix.h"

int main( int argc, char** argv) {
    struct matrix *a = mtx_load_from_file ("matrix1.dat");

    printf ("Graham-Schmidt Test on Matrix:\n");
    mtx_print (a);
    printf ("Orthonormal basis vectors are columns:\n");
    struct matrix *e = mtx_gs_col (a);
    mtx_print (e); /* print orthonormal basis vectors, columns */


    printf ("This is e * eT, \nwhere e is above and eT is it's transpose.\n");
    printf ("This should be the identity matrix...\n");
    struct matrix *eT = mtx_transpose (e);
    struct matrix *id = mtx_multiply (e, eT);
    mtx_print (id);

/*
    struct matrix *r = mtx_multiply(eT, a);
    printf("A_1, diagonal-ish.\n");
    mtx_print (r);
    
    printf ("Step 1, Inverted!\n");

    struct matrix *A_p = mtx_multiply (r, e);

    printf ("A'\n");
    mtx_print (A_p);

    printf ("Identity????\n");
    struct matrix *idd = mtx_multiply (a, A_p);
    mtx_print (idd);
*/
    return 0;
}
