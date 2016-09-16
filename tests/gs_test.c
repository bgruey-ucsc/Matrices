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

    printf("Graham-Schmidt Test.\n");
    struct matrix *e = mtx_gs_col (a);
    mtx_print (e);
    return 0;
}
