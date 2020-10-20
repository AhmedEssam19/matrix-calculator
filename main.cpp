#include <iostream>
#include <string>
#include "Matrix.h"
#include "Complex.h"

using namespace std;

int main(void)
{
	// Get first matrix from user
	string mat1;
	cout << "Enter first matrix: ";
	getline(cin, mat1);
	Matrix matrix1 (mat1);
	
	// get operator
	char operation;
	cout << "Enter operator: ";
	cin >> operation;
	cin.clear();
	cin.ignore(10000, '\n');
	
	// sum operation
	if (operation == '+')
	{
		// get another matrix from user
		string mat2;	
		cout << "Enter second matrix: ";
		getline(cin, mat2);
		Matrix matrix2 (mat2);
		cout << matrix1 + matrix2;
	}

	// substract operation
	else if (operation == '-')
	{
		// get another matrix from user
		string mat2;	
		cout << "Enter second matrix: ";
		getline(cin, mat2);
		Matrix matrix2 (mat2);

		cout << matrix1 - matrix2;
	}

	// multiplication operation
	else if (operation == '*')
	{
		// get another matrix from user
		string mat2;	
		cout << "Enter second matrix: ";
		getline(cin, mat2);
		Matrix matrix2 (mat2);

		cout << matrix1 * matrix2;
	}

	// power operation
	else if (operation == '^')
	{
		float n;
		cout << "Enter positive integer: ";
		cin >> n;
		cout << matrix1.power(n);
	}

	// transpose operation
	else if (operation == 'T')
	{
		cout << matrix1.transpose();
	}

	//  calculate deerminant
	else if (operation == 'D')
	{
		cout << matrix1.determinant() << endl;
	}

	// inverse matrix
	else if (operation == 'I')
	{
		cout << matrix1.inverse();
	}

	// Divide opertaion
	else if (operation == '/')
	{
		// get another matrix from user
		string mat2;	
		cout << "Enter second matrix: ";
		getline(cin, mat2);
		Matrix matrix2 (mat2);

		cout << matrix1 / matrix2;
	}

	else
	{
		cout << "Invalid operator\n";
		return 1;
	}

	// Success
	return 0;
}
