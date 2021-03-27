#include "spaces.hpp"


static void get_pivot_cols(Matrix &rref, int pivot_cols[], int &pivot_num){
	
	for(int i = 0; i < rref.row_size; i++){

		for(int j = 0; j < rref.col_size; j++){

			if(rref[i][j] != 0){

				pivot_cols[pivot_num++] = j;

				break;

			}

		}

	}	

}

static void get_free_cols(Matrix &rref, int free_cols[], int pivot_cols[], int &pivot_num){

	int top = 0;

	int free_num = rref.col_size - pivot_num;

	for(int j = 0; j < rref.col_size && top < free_num; j++){

		bool is_free = true;

		for(int idx = 0; idx < pivot_num; idx++){

			if(pivot_cols[idx] == j){

				is_free = false;

				break;

			}

		}

		if(is_free)
			free_cols[top++] = j;

	}

}

static bool is_pivot_col(int col, int pivot_cols[], int pivot_num){

	for(int i = 0; i < pivot_num; i++)
		if(pivot_cols[i] == col)
			return true;

	return false;

}


Matrix column_space(const Matrix &M){

	Matrix rref(eliminate(M));
 
	int pivot_num = 0;

	int pivot_cols[M.col_size];

	get_pivot_cols(rref, pivot_cols, pivot_num);

	// if the input matrix is a zero matrix	
	if(pivot_num == 0){

		Matrix C(M.row_size, 1);

		// the basis is a zero vector
		for(int i = 0; i < C.row_size; i++)
			C[i][0] = 0;

		return C;

	}

	Matrix C(M.row_size, pivot_num);
	
	for(int idx = 0; idx < pivot_num; idx++)
		for(int i = 0; i < C.row_size; i++)
			C[i][idx] = M[i][pivot_cols[idx]];
	
	return C;

}

Matrix row_space(const Matrix &M){

	Matrix MT(M.transpose());

	return eliminate(column_space(MT).transpose());

}

Matrix nullspace(const Matrix &M){

	Matrix rref(eliminate(M));

	int pivot_num = 0;

	int pivot_cols[M.col_size];

	get_pivot_cols(rref, pivot_cols, pivot_num);


	int free_num = M.col_size - pivot_num;
	
	int free_cols[free_num];

	get_free_cols(rref, free_cols, pivot_cols, pivot_num);


	// if all columns in the input matrix are independent
	if(free_num == 0){

		Matrix N(M.col_size, 1);

		// the basis is a zero vector
		for(int i = 0; i < N.row_size; i++)
			N[i][0] = 0;

		 return N;

	}

	Matrix N(M.col_size, free_num);

	// determine the column of "one" in nullspace matrix
	// when encountering free column in original matrix in r.r.e.f.
	int col_of_one = 0;

	for(int i = 0; i < N.row_size; i++){

		if(is_pivot_col(i, pivot_cols, pivot_num)){
		
			int row_of_one = 0;

			for(int j = 0; j < rref.row_size; j++){
				
				if(rref[j][i] == 1){

					row_of_one = j;

					break;

				}

			}


			for(int j = 0; j < N.col_size; j++)
				N[i][j] = rref[row_of_one][free_cols[j]] * (-1);

		}else{

			for(int j = 0; j < N.col_size; j++)
				j == col_of_one ? N[i][j] = 1 : N[i][j] = 0;

			col_of_one++;

		}

	}

	return N;

}

Matrix left_nullspace(const Matrix &M){

	Matrix MT(M.transpose());
   
	return nullspace(MT);

}
