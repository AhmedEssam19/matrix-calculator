#pragma once

#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;


class Complex
{
private:

	double real, imj;

public:
	// Set initial value
	Complex();

	Complex(double real, double imj);

	Complex(string num);
	
	// Set real value
	void set_real(double real);

	// Set imaginary value
	void set_imj(double imj);

	// Add operation
	Complex operator +(Complex complex);
	
	// Substract operation
	Complex operator -(Complex complex);

	// Multiply operation
	Complex operator *(Complex ccomplex);

	Complex operator *(double num);
	
	// Equality check
	bool operator ==(Complex c);

	// 1 over complex 
	Complex inverted();

	// Print to user
	void print();
};
