#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <cassert>
#include <iostream>

using namespace std;

struct Fraction{
	
	int numerator;
	
	int denominator;
	
	// Constructor
	Fraction(void): numerator(0), denominator(1){}
	Fraction(int n): numerator(n), denominator(1){}
	Fraction(int n, int d): numerator(n), denominator(d){ assert(d != 0 && "A denominator should not be zero!"); }
	
	// Operator Overloading
	Fraction operator + (const Fraction &F);
	Fraction operator - (const Fraction &F);
	Fraction operator * (const Fraction &F);
	Fraction operator / (const Fraction &F);
	Fraction& operator = (const Fraction &F);

	Fraction& operator += (const Fraction &F);
	Fraction& operator -= (const Fraction &F);
	Fraction& operator *= (const Fraction &F);
	Fraction& operator /= (const Fraction &F);
	
	bool operator == (const Fraction &F);
	bool operator != (const Fraction &F);


	Fraction operator + (const int &n);
	Fraction operator - (const int &n);
	Fraction operator * (const int &n);
	Fraction operator / (const int &n);
	Fraction& operator = (const int &n);
	
	Fraction& operator += (const int &n);
	Fraction& operator -= (const int &n);
	Fraction& operator *= (const int &n);
	Fraction& operator /= (const int &n);

	bool operator == (const int &n);
	bool operator != (const int &n);

};

ostream& operator << (ostream &os, const Fraction &F);

#endif
