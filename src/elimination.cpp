#include "../include/elimination.hpp"

// Row Operation of sum
static void row_sum(Matrix &M, Fraction scalar, int from, int to){

	for(int i = 0; i < M.col_size; i++)
		M[to][i] += M[from][i] * scalar;

}

// Row Operation of scalar multiplication
static void row_prod(Matrix &M, Fraction scalar, int row){

	for(int i = 0; i < M.col_size; i++)
		M[row][i] *= scalar;

}

// Gauss-Jordan Elimination (without permutation)
Matrix eliminate(const Matrix &M){

	Matrix tmp(M);
   	
	for(int i = 0; i < tmp.row_size; i++){

		// whether encounter the first non-zero number on that column
		bool encounter = false;

		for(int j = 0; j < tmp.col_size && !encounter; j++){

			if(tmp[i][j] == 0)
				continue;
			
			// j is first non-zero column in row i
			encounter = true;

			// make pivot be 1
			Fraction scalar = Fraction(1) / tmp[i][j];

			row_prod(tmp, scalar, i);

			// start to eliminate
			for(int k = 0; k < tmp.row_size; k++){

				// If it's exactly current pivot row or the number on the same column on this row is zero, skip it.
				if(k == i || tmp[k][j] == 0)
					continue;

				Fraction scalar = tmp[k][j] / tmp[i][j] * (-1);

				row_sum(tmp, scalar, i, k);

			}

		}

	}

	return tmp;

}
