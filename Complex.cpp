#include <string>
#include "Complex.h"

using namespace std;


Complex::Complex() 
{
    this->real = 0;
    this->imj = 0;
}

Complex::Complex(double real, double imj)
{
	this->real = real;
	this-> imj = imj;
}

Complex::Complex(const string& num)
{
	real = 0;
	imj = 0;

	// Detect real part
	string tmp;
	for (int i = 0; i < num.length(); i++)
	{
		if (num[i] == '+' || num[i] == '-')
		{
			real = atof(tmp.c_str());
			tmp = "";
		}

		else if (num[i] == 'i')
		{
			if (tmp == "")
				imj = 1;
			else
			{
				imj = atof(tmp.c_str());
			}
			tmp = "";
			break;
		}

		tmp += num[i];
	}

	if (tmp != "")
		real = atof(tmp.c_str());
}

// Set real value
void Complex::set_real(double real)
{
	this->real = real;
}

// Set imaginary value
void Complex::set_imj(double imj)
{
	this->imj  = imj;
}

// Add operation
 Complex Complex::operator +(Complex complex)
{
	return Complex(real + complex.real, imj + complex.imj);
}

// Substract operation
Complex Complex::operator -(Complex complex)
{
	return Complex(real - complex.real, imj - complex.real);
}

// Multiply operation
Complex Complex::operator *(Complex complex)
{
	return Complex(real * complex.real - imj * complex.imj, real * complex.imj + imj * complex.real);
}

Complex Complex::operator *(double num)
{
	return Complex(real * num, imj * num);
}

// Equality check
bool Complex::operator ==(Complex c)
{
	if (real == c.real && imj == c.imj)
		return true;
	else
		return false;
}

// 1 over complex 
Complex Complex::inverted()
{
	double mag = real * real + imj * imj;
	return Complex(real / mag, -1 * imj / mag);
}

// Print to user
void Complex::print()
{
	if (real != 0)
	{
		if (imj > 0)
			if (imj == 1)
				cout << real << "+" << "i";
			else
				cout << real << "+" << imj << "i";

		else if (imj < 0)
			if (imj == -1)
				cout << real << "-i";
			else
				cout << real << imj << "i";

		else
			cout << real;
	}

	else
	{
		if (imj != 0)
			if (imj == 1)
				cout << "i";

			else if (imj == -1)
				cout << "-i";

			else
				cout << imj << "i";

		else
			cout << "0";
	}
}
