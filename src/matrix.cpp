#include "matrix.hpp"

// Constructor
Matrix::Matrix(int m, int n){

	row_size = m;

	col_size = n;

	// Memory Allocation
	rows = new Fraction* [m]();
	
	for(int i = 0; i < m; i++)
		rows[i] = new Fraction [n]();


	// Initialization
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
 			rows[i][j] = 0;

}

Matrix::Matrix(int n): Matrix(n, n){}

// Copy Constructor
Matrix::Matrix(const Matrix &M){

	row_size = M.row_size;

	col_size = M.col_size;

	// Memory Allocation
	rows = new Fraction* [row_size]();

	for(int i = 0; i < row_size; i++)
		rows[i] = new Fraction [col_size]();

	// Coping data
	for(int i = 0; i < row_size; i++)
		for(int j = 0; j < col_size; j++)
			(*this)[i][j] = M[i][j];

}

// Destructor
Matrix::~Matrix(){

	for(int i = 0; i < row_size; i++)
		delete[] rows[i];

	delete[] rows;

}

// Overloading Subscript Operator
Fraction*& Matrix::operator [] (const int &i){

	return rows[i];

}

// Overloading Subscript Operator (access-only)
Fraction* Matrix::operator [] (const int &i) const{

	return rows[i];

}

// Overloading Unary Minus Operator
Matrix Matrix::operator - () const{

	Matrix tmp(row_size, col_size);

	tmp = *this;

	for(int i = 0; i < row_size; i++)
		for(int j = 0; j < col_size; j++)
			tmp[i][j] *= -1;

	return tmp;

}

// Overloading Binary Plus Operator
Matrix Matrix::operator + (const Matrix &M){

	assert("Inconsistent dimension when getting sum!" && row_size == M.row_size && col_size == M.col_size);

	Matrix res(row_size, col_size);
		
	for(int i = 0; i < col_size; i++)
		for(int j = 0; j < row_size; j++)
			res[i][j] = (*this)[i][j] + M[i][j];
	
	return res;

}

// Overloading Binary Minus Operator
Matrix Matrix::operator - (const Matrix &M){

	return *this + (-M);

}

// Overloading Multiply Operator
Matrix Matrix::operator * (const Matrix &M){

	assert("Incompatible matrices when getting product!" && col_size == M.row_size);

	Matrix res(row_size, M.col_size);

	for(int i = 0; i < row_size; i++){

		for(int j = 0; j < M.col_size; j++){

			Fraction sum = 0;

			for(int k = 0; k < col_size; k++)
				sum += (*this)[i][k] * M[k][j];

			res[i][j] = sum;

		}

	}

	return res;

}


// Overloading Multiply Operator (Scalar Multiplication)
Matrix Matrix::operator * (const int &x){

	Matrix res(row_size, col_size);

	for(int i = 0; i < row_size; i++)
		for(int j = 0; j < col_size; j++)
			res[i][j] *= x;

	return res;

}


// Overloading Assignment Operator
Matrix& Matrix::operator = (const Matrix &M){

	assert("Inconsistent dimension when assigning!" && row_size == M.row_size && col_size == M.col_size);

	// if assigning a matrix to itself
	if(this == &M)
		return *this;

	for(int i = 0; i < row_size; i++)
		for(int j = 0; j < col_size; j++)
			(*this)[i][j] = M[i][j];

	return *this;

}


// Transpose
Matrix Matrix::transpose(void) const{

	Matrix MT(col_size, row_size);

	for(int i = 0; i < MT.row_size; i++){

		for(int j = 0; j < MT.col_size; j++){

			MT[i][j] = (*this)[j][i];

		}

	}

	return MT;

}


// Overloading Output Operator
ostream& operator << (ostream &os, const Matrix &M){

	for(int i = 0; i < M.row_size; i++){

		os << "| ";

		for(int j = 0; j < M.col_size; j++)
			os << M[i][j] << " ";

		os << "|" << endl;

	
	}

	os << endl;

	return os;

}
