#pragma once

#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;


class Complex
{
private:

	float real, imj;

public:
	// Set initial value
	Complex();

	Complex(float real, float imj);
	
	// Set real value
	void set_real(float real);

	// Set imaginary value
	void set_imj(float imj);

	// Add operation
	Complex operator +(Complex complex);
	
	// Substract operation
	Complex operator -(Complex complex);

	// Multiply operation
	Complex operator *(Complex ccomplex);

	Complex operator *(float num);
	
	// Equality check
	bool operator ==(Complex c);

	// 1 over complex 
	Complex inverted();

	// Print to user
	void print();
};
