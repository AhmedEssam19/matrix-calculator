#include <string>
#include "Complex.h"
#include "helpers.h"

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

Complex::Complex(const string& number)
{
	real = 0;
	imj = 0;
	
	// Detect real part
	string tmp;
	for (int i = 0; i < number.length(); i++)
	{
		if (number[i] == '+' || number[i] == '-')
		{
			real = atof(tmp.c_str());
			tmp = "";
		}

		else if (number[i] == 'j')
		{
			if (tmp == "+" || tmp == "")
				imj = 1;
			else if (tmp == "-")
				imj = -1;
			else
			{
				imj = atof(tmp.c_str());
			}
			tmp = "";
			break;
		}

		tmp += number[i];
	}

	if (tmp != "")
		real = atof(tmp.c_str());
}

// Add operation
 Complex Complex::operator +(Complex complex)
{
	return Complex(real + complex.real, imj + complex.imj);
}

// Substract operation
Complex Complex::operator -(Complex complex)
{
	return Complex(real - complex.real, imj - complex.imj);
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
				cout << real << "+" << "j";
			else
				cout << real << "+" << imj << "j";

		else if (imj < 0)
			if (imj == -1)
				cout << real << "-j";
			else
				cout << real << imj << "j";

		else
			cout << real;
	}

	else
	{
		if (imj != 0)
			if (imj == 1)
				cout << "j";

			else if (imj == -1)
				cout << "-j";

			else
				cout << imj << "j";

		else
			cout << "0";
	}
}
