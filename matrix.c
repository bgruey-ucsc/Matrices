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
 

  *** 	Using structures, which form?

		typedef struct { // Stuff } matrix;
	or
		struct matrix { // stuff };
 
	
  ***	Use a namespace? Does anyone ever actually use a namespace? 

  ***	Pointer to a pointer in order to pass by reference? See Transpose_Matrix.

*/

#include "matrix.h"


// New Matrix
// Make a new matrix, 
// m->data[row][col]
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


// Delete all the data of a matrix
// Does not delete the pointer though, m still exists
void Delete_Matrix(struct matrix* m) {
	int i = 0;
	while ( i < m->rows) {
		free(m->data[i]); // arrays of colum entries
		i++;
	}
	free(m->data); // array of rows
	free(m); // rows, cols and data
}



// Make an identity matrix of dimension dim
struct matrix* Id_Matrix(int dim) {

	struct matrix* m = New_Matrix(dim, dim);
	int i = 0;
	while ( i < dim) {
		m->data[i][i] = 1.0;
		i++;
	}

	return m;
}


//Copy the matrix
// Return the copy
struct matrix* Copy_Matrix(struct matrix* m) {
	
	struct matrix* cpy = New_Matrix( m->rows, m->cols);

	int i = 0;
	int j = 0;
	while( i < m->rows) {
		j = 0;
		while (j < m->cols) {
			cpy->data[i][j] = m->data[i][j];
			j++;
		}//end j: over columns
		i++;
	}//end i: down rows

	return cpy;
}



// Multiply two matrices together
// first check that the matrices have appropriate dimensions.
// Then brute force, any other way?

struct matrix* Mult_Matrix( struct matrix* a, struct matrix* b) {
	
	struct matrix* m = New_Matrix(a->rows, b->cols);

	if (a->cols != b->rows) {
		fprintf(stderr, "Incompatible dimensions for matrices %p and %p.\n", a, b);
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


// Add Matrices
// m1 = m1 + [weight] * m2
// returns 1 if dimensions are mistmatched
// zero else
int Add_Matrix(struct matrix* m1, struct matrix* m2, double weight) {
	if(m1->rows != m2->rows || m1->cols != m2->cols) {
		fprintf(stderr, "Mistmatched Matrix Dimensions! %p, %p\n", m1, m2);
		return 1;
	}
	int i = 0;
	int j = 0;
	printf("Sizes ok.\n");
	while( i < m1->rows) {
		j = 0;
		while( j < m1->cols) {
			m1->data[i][j] = m1->data[i][j] + weight * m2->data[i][j];
			j++;
		}//end j: over cols
		i++;
	}//end i: down rows
	return 0;
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





// Get a column vector.
// a row vector using column [col] and rowss [low] to [high]
// includes low and high rows, non-included rows are zero.
struct matrix* Get_Cvector(struct matrix* m, int low, int high, int col) {
	int dim = m->rows; // dimension of vector
	struct matrix* v = New_Matrix( dim, 1);
	int i = low;
	high++; // to include high in the loop

	while ( i < high) {
		v->data[i][0] = m->data[i][col];
		i++;
	}

	return v;
}
// Get a row vector.
// a row vector using row [row] and columns [low] to [high]
// includes low and high columns, non-included columns are zero.
struct matrix* Get_Rvector(struct matrix* m, int low, int high, int row) {
	int dim = m->cols; // dimension of vector
	struct matrix* v = New_Matrix( 1, dim);
	int i = low;
	high++; // to include high in the loop

	while ( i < high) {
		v->data[0][i] = m->data[row][i];
		i++;
	}

	return v;
}


// Norm of a vector, squared
// to not waste time computing square root if we don't need to
double Get_Norm2(struct matrix* m) {
	double norm = 0;
	int i = 0;
	// row vector
	if (m->rows == 1) {
		while( i < m->cols) {
			norm += pow( m->data[0][i], 2.0);
			i++;
		}
		return norm;
	} // end row vector case

	// column vector
	else if (m->cols == 1) {
		while (i < m->rows) {
			norm += pow( m->data[i][0], 2.0);
			i++;
		}
		return norm;
	}// end column vector case

	else {
		fprintf(stdout, "Matrix, not a vector: %p\nHopefully you weren't dividing by that.\n", m);
		return 0.0;
	}
	
}


void Transpose_Matrix(struct matrix** m){

	int i = 0;
	int j = 0;
	if ((*m)->rows == (*m)->cols) { // square matrix
		double temp = 0;
		while ( i < (*m)->rows) {
			j = 0;
			while( j < i) {
				temp = (*m)->data[i][j];
				(*m)->data[i][j] = (*m)->data[j][i];
				(*m)->data[j][i] = temp;
				j++;
			}// end j: loop across columns
			i++;
		}// end i: loop down the rows of the matrix
	}//end if: matrix was square
	else{// not a square
		struct matrix* mm = New_Matrix((*m)->cols, (*m)->rows);
		while ( i < (*m)->rows) {
			j = 0;
			while ( j < (*m)->cols) {
				mm->data[j][i] = (*m)->data[i][j];
				j++;
			}//end j: across columns
			i++;
		}//end i: down rows
		
		Delete_Matrix(*m);
		(*m) = mm; // thus needed pass by reference

	}// end else: matrix was not square
}

// Householder Step
// assuming step goes from m->rows to 1 in Householder Loop
struct matrix* Householder_Step_Matrix(struct matrix* m, int step) {
	// vector for outer product
	struct matrix* u = Get_Cvector(m, step, m->rows, step);
	Print_Matrix(u);
	double u_norm = Get_Norm2(u);
	//updating to proper definition
	u->data[step][0] = u->data[step][0] * sqrt(u_norm);
	u_norm = Get_Norm2(u); 
	// This is onw the u we wanted for page 595 of Thijssen

	struct matrix* u_T = Copy_Matrix(u); // make a copy of u vector
	Transpose_Matrix(&u_T);
	struct matrix* uu_T = Mult_Matrix(u, u_T);
	struct matrix* hhst = Id_Matrix(uu_T->rows);
	Add_Matrix(hhst, uu_T, -2.0 / u_norm);

	return hhst;
}
