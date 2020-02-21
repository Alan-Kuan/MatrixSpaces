#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "fraction.hpp"
#include <cassert>
#include <iostream>

using namespace std;

struct Matrix{

	int row_size, col_size;

	Fraction **rows;

	// Constructors
	Matrix(int n);
	Matrix(int m, int n);

	// Copy Constructor
	Matrix(const Matrix &M);

	// Destructor
	~Matrix();

	// Operater Overloading
	Fraction*& operator [] (const int &i);
	Fraction* operator [] (const int &i) const; // access-only

	Matrix operator - () const;  // unary minus

	Matrix operator + (const Matrix &M);
	Matrix operator - (const Matrix &M);
	Matrix operator * (const Matrix &M);

	Matrix operator * (const int &x);  // scalar multiplication

	Matrix& operator = (const Matrix &M);

	// Tranpose
	Matrix transpose(void) const;

};

ostream& operator << (ostream &os, const Matrix &M);

#endif
