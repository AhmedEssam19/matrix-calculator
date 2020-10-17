#include <string>
#include <cstdlib>
#include <cmath>

#include <iostream>
using namespace std;



class Complex
{
	float real, imj;

public:
	// set initial value
	Complex()
	{
		real = 0;
		imj = 0;
	}

	Complex(float a, float b)
	{
		real = a;
		imj = b;
	}

	// pass real value
	void setreal(float r)
	{
		real = r;
	}

	// pass imaginary value
	void setimj(float i)
	{
		imj = i;
	}

	// get real value
	float getreal()
	{
		return real;
	}

	// get imj value 
	float getimj()
	{
		return imj;
	}
	
	// Add operation
	Complex operator +(Complex c)
	{
		return Complex(real + c.real, imj + c.imj);
	}

	// Substract operation
	Complex operator -(Complex c)
	{
		return Complex(real - c.getreal(), imj - c.getimj());
	}

	// Multiply operation
	Complex operator *(Complex c)
	{
		return Complex(real * c.getreal() - imj * c.getimj(), real * c.getimj() + imj * c.getreal());
	}

	Complex operator *(float n)
	{
		return Complex(real * n, imj * n);
	}

	// Equality check
	bool operator ==(Complex c)
	{
		if (real == c.getreal() && imj == c.getimj())
			return true;
		else
			return false;
	}

	Complex inverted()
	{
		float mag = real * real + imj * imj;
		return Complex(real / mag, -1 * imj / mag);
	}

	// Print to user
	void print()
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
};

// check correctness of matrix
bool checkMatrix(string Matrix, Complex matrix[][100], int& row, int& col)
{
	int L = Matrix.length();
	int shift, colcheck = 0;

	// check user enter matrix correctly
	if (Matrix[0] != '[' || Matrix[L - 1] != ']')
	{
		cout << "CHECK SQUARE BRACKETS\n";
		return 1;
	}
	for (int i = 1; i < L - 1; i++)
	{
		if (!(Matrix[i] == ';' || Matrix[i] == '.' || Matrix[i] == ' ' || (Matrix[i] >= '0' && Matrix[i] <= '9') || Matrix[i] == '-' || Matrix[i] == '+' || Matrix[i] == 'i'))
		{
			cout << "SYNTAX ERROR\n";
			return 1;
		}
	}

	bool flag = false;
	for (int i = 1; i < L; i += shift)
	{
		string temp;
		for (int j = i; Matrix[j] != ']'; j++)
		{
			// convert real part from string to double
			if (Matrix[j] == ' ' || Matrix[j] == '+' || (Matrix[j] == '-' && isdigit(Matrix[j - 1]) != 0))
			{
				matrix[row - 1][col - 1].setreal(atof(temp.c_str()));
				if (Matrix[j] == ' ')
					col++;
				else if (Matrix[j] == '-')
					flag = true;
				break;
			}

			// convert imaginary part from string to double
			else if (Matrix[j] == 'i')
			{
				if (temp.length() == 0)
					if (flag)
					{
						matrix[row - 1][col - 1].setimj(-1);
						flag = false;
					}
					else
						matrix[row - 1][col - 1].setimj(1);

				else
					if (flag)
					{
						matrix[row - 1][col - 1].setimj(-1 * atof(temp.c_str()));
						flag = false;
					}

					else
						matrix[row - 1][col - 1].setimj(atof(temp.c_str()));

				temp += "i";

				if (Matrix[j + 1] == ';')
				{
					// setting coloumn check for first raw
					if (row == 1)
						colcheck = col;

					// check any missing element
					if (col != colcheck)
					{
						cout << "MISSING ELEMENT\n";
						return 1;
					}

					row++;
					col = 1;
				}

				else if (Matrix[j + 1] == ' ')
					col++;

				break;
			}

			// convert last element in row from string to double
			else if (Matrix[j] == ';')
			{
				// setting coloumn check for first raw
				if (row == 1)
					colcheck = col;

				// check any missing element
				if (col != colcheck)
				{
					cout << "MISSING ELEMENT\n";
					return 1;
				}
				matrix[row - 1][col - 1].setreal(atof(temp.c_str()));

				row++;
				col = 1;
				break;
			}

			// detect elements
			else
			{
				temp += Matrix[j];
				if (Matrix[j + 1] == ']')
				{
					// check any missing element
					if (col != colcheck && row != 1)
					{
						cout << "MISSING ELEMENT\n";
						return 1;
					}
					matrix[row - 1][col - 1].setreal(atof(temp.c_str()));
				}
			}
		}

		// string shift cursor
		shift = temp.length() + 1;
	}

	// success
	return 0;
}

// function print the matrix
void showMat(Complex matrix[][100], int row, int col)
{
	cout << "RESULT: [";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j].print();

			if (j != col - 1)
				cout << ' ';
		}
		if (i != row - 1)
			cout << ';';
	}
	cout << "]\n";
}

// make suppMatrix
void suppMat(Complex matrix[][100], int rownum, int colnum, int n, Complex temp[][100])
{
	int r = 1, c = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != rownum && j != colnum)
			{
				// fill elements
				temp[r - 1][c - 1] = matrix[i][j];
				c++;

				// move to next row
				if (c == n)
				{
					r++;
					c = 1;
				}
			}
		}
	}
}

Complex det(Complex matrix[][100], int row)
{
	// base case
	if (row == 1)
		return matrix[0][0];

	// recursive case
	else
	{
		Complex determinant;
		Complex temp[100][100];
		int sign = 1;
		for (int k = 0; k < row; k++)
		{
			suppMat(matrix, 0, k, row, temp);
			determinant = determinant + (matrix[0][k] * det(temp, row - 1) * sign);
			sign *= -1;
		}

		return determinant;
	}

}

void copyMat(Complex matrix1[][100], Complex matrix2[][100], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			matrix1[i][j] = matrix2[i][j];
	}
}