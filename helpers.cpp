#include "helpers.h"
#include <iostream>
using namespace std;

// split string on a specific character to a vector of strings 
vector<string>* split(string txt, char split_char)
{
	vector<string>* vec = new vector<string>;
	string tmp;
	for (char character : txt)
	{
		if (character == split_char && !strip(tmp).empty())
		{
			vec->push_back(strip(tmp));
			tmp = "";
		}

		else
			tmp += character;	
	}

	if (!strip(tmp).empty())
		vec->push_back(strip(tmp));

	return vec;	
}

// Eliminate spaces in the begining and at the end of string
string strip(string txt)
{
	size_t start = 0;
	for (size_t i = 0; i < txt.length(); i++)
	{
		if (txt[i] == ' ')
			start++;
		
		else
			break;
	}

	size_t length = txt.length() - start;
	for (size_t i = txt.length() - 1; i >= 0; i--)
	{
		if (length <= 0 || txt[i] != ' ')
			break;

		else
			length--;
	}
	
	return txt.substr(start, length);	
}


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
				matrix[row - 1][col - 1].set_real(atof(temp.c_str()));
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
						matrix[row - 1][col - 1].set_imj(-1);
						flag = false;
					}
					else
						matrix[row - 1][col - 1].set_imj(1);

				else
					if (flag)
					{
						matrix[row - 1][col - 1].set_imj(-1 * atof(temp.c_str()));
						flag = false;
					}

					else
						matrix[row - 1][col - 1].set_imj(atof(temp.c_str()));

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
				matrix[row - 1][col - 1].set_real(atof(temp.c_str()));

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
					matrix[row - 1][col - 1].set_real(atof(temp.c_str()));
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
