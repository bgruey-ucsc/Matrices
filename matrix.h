/*
		Matrix Library! 

	Started as a C library to solve a generalized eigenvalue problem,
	numerical approximations to quantum systems:

		[H] * [C] = E * [S] * [C]

	where brackets indicate matrices:
		H is the Mamiltonian
		C is the basis function coefficient matrix
		S is the generalized "______" matrix for non-orthogonal basis functions
			it would be the identity matrix if they were orthogonal
			this matrix should be symmetric

	The work started with the infinite square well approximation defined
	on page 29 of Jos Thijssen's second edition of Computational Physics


*/

/*
 		Coding Design Considerations
 
	***
 	Using structures, which form?

		typedef struct { // Stuff } matrix;
	or
		struct matrix { // stuff };
 
	***
	Use a namespace? Does anyone ever actually use a namespace? 

	
*/


/*
	Data
*/

// Matrix Struct

struct matrix {
	int rows, cols;

	double** data;
};


/*
	Functions
*/

// New Matrix
// Make a new matrix, 

struct matrix* New_Matrix(int rows, int columns) {

	struct matrix* m = (struct matrix*)calloc(1, sizeof(struct matrix));

	m->rows = rows;
	m->cols = columns;
	m->data = (double**)calloc(rows, sizeof(double*));
	int i = 0;
	int j = 0;
	while( i < rows) {
		m->data[i] = (double*)calloc(columns, sizeof(double));
		i++;
	}

	return m;
}


// Multiply two matrices together
// first check that the matrices have appropriate dimensions.
// Then brute force, any other way?

struct matrix* Mult_Matrix( struct matrix* a, struct matrix* b) {
	
	struct matrix* m = New_Matrix(a->rows, b->cols);

	if (a->cols != b->rows) {
		fprintf(stdout, "Incompatible dimensions for matrices %p and %p.\n", a, b);
		return 0;
	} // end if: checking matrix dimensions

	else{
		int row = 0;
		int col = 0;
		int add = 0;
		while( row < m->rows) {
			col = 0; 
			while (col < m->rows) {
				add = 0;
				while( add < b->rows) {
					m->data[row][col] += a->data[row][add] * b->data[add][col];
					add++;
				}// end add: sum for [row][col] position in mult.
			col++;
			}// end col: loop over mult columns
		row++;
		}// end row: loop over mult rows
		
	return m;
	}// end else: should be multiplied now
}

// Matrix Print
// Print to standard out
void Print_Matrix(struct matrix* m) {
	int row = 0;
	int col = 0;
	printf("Matrix %p, %dx%d\n", m, m->rows, m->cols);
	while (row < m->rows) { 
		col = 0;
		while (col < m->cols) {
		fprintf(stdout, "%f\t", m->data[row][col]);
		col++;
	} // end of col loop
		fprintf(stdout, "\n");
		row++;
	} // end double loop
}


// Diagonalize Symmetric
// Assume the matrix is symmetric. That is the user's job to check.


