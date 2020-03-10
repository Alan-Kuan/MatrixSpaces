#include "fraction.hpp"

static int gcd(int a, int b){

	int tmp;

	while(a != 0){

		tmp = b%a;

		b = a;

		a = tmp;

	}

	// avoid getting negative gcd and thus causing negative denominator
	return b < 0 ? -b : b;

}


Fraction Fraction::operator + (const Fraction &F){
	
	Fraction res;
	
	res.numerator = numerator * F.denominator + F.numerator * denominator;

	res.denominator = denominator * F.denominator;

	int GCD = gcd(res.numerator, res.denominator);

	res.numerator /= GCD;

	res.denominator /= GCD;
	
	return res;
	
}

Fraction Fraction::operator - (const Fraction &F){
	
	Fraction tmp = F;
	
	tmp.numerator *= -1;
	
	return *this + tmp;
	
}

Fraction Fraction::operator * (const Fraction &F){
	
	Fraction res;
	
	res.numerator = numerator * F.numerator;
	
	res.denominator = denominator * F.denominator;
	
	int GCD = gcd(res.numerator, res.denominator);
	
	res.numerator /= GCD;
	
	res.denominator /= GCD;
	
	return res;
	
}

Fraction Fraction::operator / (const Fraction &F){
	
	assert("A fraction should not be devided by zero!" && F.numerator != 0);
	
	Fraction res;
	
	res.numerator = numerator * F.denominator;
	
	res.denominator = denominator * F.numerator;
	
	int GCD = gcd(res.numerator, res.denominator);
	
	res.numerator /= GCD;
	
	res.denominator /= GCD;
	
	return res;
	
}

Fraction& Fraction::operator = (const Fraction &F){

	// if assigning a fraction to itself
	if(this == &F)
		return *this;

	numerator = F.numerator;
	
	denominator = F.denominator;
	
	return *this;
	
}


Fraction& Fraction::operator += (const Fraction &F){
	
	*this = *this + F;
	
	return *this;
	
}

Fraction& Fraction::operator -= (const Fraction &F){
	
	*this = *this - F;
	
	return *this;
	
}

Fraction& Fraction::operator *= (const Fraction &F){
	
	*this = *this * F;
	
	return *this;
	
}

Fraction& Fraction::operator /= (const Fraction &F){
	
	*this = *this / F;
	
	return *this;
	
}


bool Fraction::operator == (const Fraction &F){

	return numerator == F.numerator && denominator == F.denominator;

}

bool Fraction::operator != (const Fraction &F){

	return numerator != F.numerator || denominator != F.denominator;

}


Fraction Fraction::operator + (const int &n){
	
	Fraction tmp(n);
	
	return *this + tmp;
	
}

Fraction Fraction::operator - (const int &n){
	
	Fraction tmp(-n);
	
	return *this + tmp;
	
}

Fraction Fraction::operator * (const int &n){
	
	Fraction tmp(n);
	
	return *this * tmp;
	
}

Fraction Fraction::operator / (const int &n){
	
	assert("A fraction should not be devided by zero!" && n != 0);
	
	Fraction tmp(1, n);
	
	return *this * tmp;
	
}

Fraction& Fraction::operator = (const int &n){
	
	numerator = n;
	
	denominator = 1;
	
	return *this;
	
}


Fraction& Fraction::operator += (const int &n){
	
	Fraction tmp(n);
	
	*this = *this + tmp;
	
	return *this;
	
}

Fraction& Fraction::operator -= (const int &n){
	
	Fraction tmp(n);
	
	*this = *this - tmp;
	
	return *this;
	
}

Fraction& Fraction::operator *= (const int &n){
	
	Fraction tmp(n);
	
	*this = *this * tmp;
	
	return *this;
	
}

Fraction& Fraction::operator /= (const int &n){
	
	Fraction tmp(n);
	
	*this = *this / tmp;
	
	return *this;
	
}


bool Fraction::operator == (const int &n){

	return numerator == n && denominator == 1;

}

bool Fraction::operator != (const int &n){

	return numerator != n || denominator != 1;

}


ostream& operator << (ostream &os, const Fraction &F){

	if(F.denominator == 1)
		os << F.numerator;
	else
		os << F.numerator << "/" << F.denominator;

	return os;

}
