#include <iostream>
#include <string>
#include "Matrix.h"
#include "Complex.h"

using namespace std;

int main(void)
{
	// Get first matrix from user
	string mat1;
	cout << "ENTER FIRST MATRIX: ";
	getline(cin, mat1);
	Matrix matrix1 (mat1);
	
	// get operator
	char operation;
	cout << "ENTER OPERATOR: ";
	cin >> operation;
	cin.clear();
	cin.ignore(10000, '\n');
	
	// sum operation
	if (operation == '+')
	{
		// get another matrix from user
		string mat2;	
		cout << "ENTER SECOND MATRIX: ";
		getline(cin, mat2);
		Matrix matrix2 (mat2);
		(matrix1 + matrix2).print();
	}

	// substract operation
	else if (operation == '-')
	{
		// get another matrix from user
		string mat2;	
		cout << "ENTER SECOND MATRIX: ";
		getline(cin, mat2);
		Matrix matrix2 (mat2);

		(matrix1 - matrix2).print();
	}

	// multiplication operation
	else if (operation == '*')
	{
		// get another matrix from user
		string mat2;	
		cout << "ENTER SECOND MATRIX: ";
		getline(cin, mat2);
		Matrix matrix2 (mat2);

		(matrix1 * matrix2).print();
	}

	// power operation
	else if (operation == '^')
	{
		float n;
		cout << "Enter Positive Integer: ";
		cin >> n;
		matrix1.power(n).print();
	}

	// transpose operation
	else if (operation == 'T')
	{
		matrix1.transpose().print();
	}

	//  calculate deerminant
	else if (operation == 'D')
	{
		matrix1.determinant().print();
		cout << endl;
	}

	// inverse matrix
	else if (operation == 'I')
	{
		matrix1.inverse().print();
	}

	// Divide opertaion
	else if (operation == '/')
	{
		// get another matrix from user
		string mat2;	
		cout << "ENTER SECOND MATRIX: ";
		getline(cin, mat2);
		Matrix matrix2 (mat2);

		(matrix1 / matrix2).print();
	}

	else
	{
		cout << "UNDEFINED OPERATOR\n";
		return 1;
	}

	// Success
	return 0;
}
