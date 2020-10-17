#include "Complex.h"

// declaring matrices
Complex matrix1[100][100];
Complex resmatrix[100][100];

// declaring string and character
string Matrix1;
char op;

// declaring rows and coloums
int row1 = 1, col1 = 1;
int E;
int main(void)
{
	// get matrix from user
	cout << "ENTER FIRST MATRIX: ";
	getline(cin, Matrix1);

	// check and extract floats
	if (checkMatrix(Matrix1, matrix1, row1, col1))
		return 1;
	do
	{
		// get operator
		cout << "ENTER OPERATOR: ";
		cin >> op;

		// sum operation
		if (op == '+')
		{
			// declare needen variables
			Complex matrix2[100][100];
			int row2 = 1, col2 = 1;
			string Matrix2;

			// get another matrix from user
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "ENTER SECOND MATRIX: ";
			getline(cin, Matrix2);

			// check and extract floats
			if (checkMatrix(Matrix2, matrix2, row2, col2))
				return 1;

			// check same rows and coloumns
			if (row2 != row1 || col2 != col1)
			{
				cout << "ADDING CONDITION VIOLATED\n";
				return 1;
			}
			// sum matrices
			for (int i = 0; i < row1; i++)
			{
				for (int j = 0; j < col1; j++)
					resmatrix[i][j] = matrix1[i][j] + matrix2[i][j];
			}

			// print matrix
			showMat(resmatrix, row1, col1);

			// save it to matrix1
			copyMat(matrix1, resmatrix, row1, col1);
		}

		// substract operation
		else if (op == '-')
		{
			// declare needen variables
			Complex matrix2[100][100];
			int row2 = 1, col2 = 1;
			string Matrix2;

			// get another matrix from user
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "ENTER SECOND MATRIX: ";
			getline(cin, Matrix2);

			// check and extract floats
			if (checkMatrix(Matrix2, matrix2, row2, col2))
				return 1;

			// check same rows and coloumns
			if (row2 != row1 || col2 != col1)
			{
				cout << "SUBTRACTING CONDITION VIOLATED\n";
				return 1;
			}
			// substract matrices
			for (int i = 0; i < row1; i++)
			{
				for (int j = 0; j < col1; j++)
					resmatrix[i][j] = matrix1[i][j] - matrix2[i][j];
			}

			// print matrix
			showMat(resmatrix, row1, col1);

			// save it to matrix1
			copyMat(matrix1, resmatrix, row1, col1);
		}

		// multiplication operation
		else if (op == '*')
		{
			// declare needen variables
			Complex matrix2[100][100];
			int row2 = 1, col2 = 1;
			string Matrix2;

			// get another matrix from user
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "ENTER SECOND MATRIX: ";
			getline(cin, Matrix2);

			// check and extract floats
			if (checkMatrix(Matrix2, matrix2, row2, col2))
				return 1;

			// check same rows and coloumns
			if (col1 != row2)
			{
				cout << "MULTIPLICATION CINDITION VIOLATED\n";
				return 1;
			}

			// multiply operation
			for (int i = 0; i < row1; i++)
			{
				for (int j = 0; j < col2; j++)
				{
					for (int k = 0; k < col1; k++)
						resmatrix[i][j] = resmatrix[i][j] + matrix1[i][k] * matrix2[k][j];
				}
			}
			// print matrix
			showMat(resmatrix, row1, col2);

			// save it to matrix1
			copyMat(matrix1, resmatrix, row1, col2);
		}

		// power operation
		else if (op == '^')
		{
			//check if square matrix
			if (row1 != col1)
			{
				cout << "NOT SQUARE MATRIX\n";
				return 1;
			}

			// get positive integer power from user
			float n;
			cout << "Enter Positive Integer: ";
			cin >> n;
			if (n - (int)n != 0 || n < 1)
			{
				cout << "ERROR: ENTER POSITIVE INTEGER\n";
				return 1;
			}

			Complex temp[100][100];

			// set result for power 1
			for (int i = 0; i < row1; i++)
			{
				for (int j = 0; j < col1; j++)
				{
					resmatrix[i][j] = matrix1[i][j];
				}
			}

			// power opaeration
			for (int k = 1; k < n; k++)
			{
				for (int i = 0; i < row1; i++)
				{
					for (int j = 0; j < col1; j++)
					{
						for (int m = 0; m < col1; m++)
							temp[i][j] = temp[i][j] + resmatrix[i][m] * matrix1[m][j];
					}
				}

				// filling and empty matrices
				for (int i = 0; i < row1; i++)
				{
					for (int j = 0; j < col1; j++)
					{
						resmatrix[i][j] = temp[i][j];
						temp[i][j].setreal(0);
						temp[i][j].setimj(0);
					}
				}

			}

			// print matrix
			showMat(resmatrix, row1, col1);

			// save it to matrix1
			copyMat(matrix1, resmatrix, row1, col1);
		}

		// transpose operation
		else if (op == 'T')
		{
			for (int i = 0; i < col1; i++)
			{
				for (int j = 0; j < row1; j++)
					resmatrix[i][j] = matrix1[j][i];
			}
			// print matrix
			showMat(resmatrix, col1, row1);

			// save it to matrix1
			copyMat(matrix1, resmatrix, row1, col1);
		}

		//  calculate deerminant
		else if (op == 'D')
		{
			//check if square matrix
			if (row1 != col1)
			{
				cout << "NOT SQUARE MATRIX\n";
				return 1;
			}

			Complex determin = det(matrix1, row1);
			cout << "Determinant = ";
			determin.print();
			return 0;
		}

		// inverse matrix
		else if (op == 'I')
		{
			//check if valid inverse matrix
			if (row1 != col1 || det(matrix1, row1) == Complex(0, 0))
			{
				cout << "NOT SQUARE MATRIX OR DET EQUAL 0";
				return 1;
			}

			Complex temp[100][100];
			Complex adjMat[100][100];
			Complex determinant = det(matrix1, row1);

			// make adj Matrix
			for (int i = 0; i < row1; i++)
			{
				for (int j = 0; j < col1; j++)
				{
					suppMat(matrix1, i, j, row1, temp);
					adjMat[i][j] = det(temp, row1 - 1) * pow(-1, i + j + 2);
				}
			}

			// make inverse matrix
			for (int i = 0; i < row1; i++)
			{
				for (int j = 0; j < col1; j++)
				{
					resmatrix[i][j] = determinant.inverted() * adjMat[j][i];
				}
			}

			// print matrix
			showMat(resmatrix, row1, col1);

			// save it to matrix1
			copyMat(matrix1, resmatrix, row1, col1);
		}

		// Divide opertaion
		else if (op == '/')
		{
			// declare needen variables
			Complex matrix2[100][100];
			int row2 = 1, col2 = 1;
			string Matrix2;

			// get another matrix from user
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "ENTER SECOND MATRIX: ";
			getline(cin, Matrix2);

			// check and extract floats
			if (checkMatrix(Matrix2, matrix2, row2, col2))
				return 1;

			if (row2 != col2 || det(matrix2, row2) == Complex(0, 0))
			{
				cout << "NOT SQUARE MATRIX OR DET EQUAL 0\n";
				return 1;
			}

			Complex temp[100][100];
			Complex adjMat[100][100];
			Complex determinant = det(matrix2, row2);

			// make adj Matrix
			for (int i = 0; i < row2; i++)
			{
				for (int j = 0; j < col2; j++)
				{
					suppMat(matrix2, i, j, row2, temp);
					adjMat[i][j] = det(temp, row2 - 1) * pow(-1, i + j + 2);
				}
			}

			// make inverse matrix
			for (int i = 0; i < row2; i++)
			{
				for (int j = 0; j < col2; j++)
				{
					matrix2[i][j] = determinant.inverted() * adjMat[j][i];
				}
			}

			if (col1 != row2)
			{
				cout << "MULTIPLICATION CONDITION VIOLATED\n";
				return 1;
			}

			// multiply operation
			for (int i = 0; i < row1; i++)
			{
				for (int j = 0; j < col2; j++)
				{
					for (int k = 0; k < col1; k++)
						resmatrix[i][j] = resmatrix[i][j] + matrix1[i][k] * matrix2[k][j];
				}
			}
			// print matrix
			showMat(resmatrix, row1, col2);

			// save it to matrix1
			copyMat(matrix1, resmatrix, row1, col1);
		}

		else
		{
			cout << "UNDEFINED OPERATOR\n";
			return 1;
		}

		cout << "ENTER 1 TO CONTINUE OR 0 TO EXIT: ";
		cin >> E;
	}
	while (E == 1);

	// Success
	return 0;
}
