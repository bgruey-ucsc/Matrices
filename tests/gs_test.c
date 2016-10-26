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

    printf("Graham-Schmidt Test\n");
    printf("Orthogonal basis vectors:\n");
    struct matrix *e = mtx_gs_col (a);
    mtx_print (e);

    printf ("Unitary? This should be the Identity Matrix.\n");
    printf ("Currently the best is the Identity with off-diagonal elements of e-7\n");
    printf ("That's not good enough, nope.\n\n");
    struct matrix *eT = mtx_transpose (e);
    struct matrix *id = mtx_multiply (e, eT);
    mtx_print (id);

    struct matrix *r = mtx_multiply(eT, a);
    printf("A_1, diagonal-ish.\n");
    mtx_print (r);
    return 0;
}
