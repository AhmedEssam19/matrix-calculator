#include <iostream>
#include <fstream>
#include <string>
#include "../helpers.h"
#include "../Matrix.h"
using namespace std;


int main()
{
    int test_cases = 15;
    ifstream in_file {"test_cases2.txt"};
    if (in_file)
    {
        for (size_t i = 0; i < test_cases; i++)
        {
            string s;
            getline(in_file, s);
            cout << s << endl;
            Matrix matrix1 = get_matrix(in_file);
            Matrix matrix2 = get_matrix(in_file);
            
            cout << "Add: ";
            Matrix res_matrix = get_matrix(in_file);
            check_matrices(matrix1 + matrix2, res_matrix);

            cout << "Subtract: ";
            res_matrix = get_matrix(in_file);
            check_matrices(matrix1 - matrix2, res_matrix);

            cout << "Multiply: ";
            res_matrix = get_matrix(in_file);
            check_matrices(matrix1 * matrix2, res_matrix);

            cout << "Matrix1 power 4: ";
            res_matrix = get_matrix(in_file);
            check_matrices(matrix1.power(4), res_matrix);

            cout << "Matrix2 power 4: ";
            res_matrix = get_matrix(in_file);
            check_matrices(matrix2.power(4), res_matrix);

            cout << "Matrix1 tanspose: ";
            res_matrix = get_matrix(in_file);
            check_matrices(matrix1.transpose(), res_matrix);

            cout << "Matrix2 transpose: ";
            res_matrix = get_matrix(in_file);
            check_matrices(matrix2.transpose(), res_matrix);

            cout << "Matrix1 determinant: ";
            Complex det = get_complex(in_file);
            check_complex(matrix1.determinant(), det);

            cout << "Matrix2 determinant: ";
            det = get_complex(in_file);
            check_complex(matrix2.determinant(), det);

            cout << "Matrix1 inverse: ";
            res_matrix = get_matrix(in_file);
            check_matrices(matrix1.inverse(), res_matrix);

            cout << "Matrix2 inverse: ";
            res_matrix = get_matrix(in_file);
            check_matrices(matrix2.inverse(), res_matrix);

            cout << "Matrix1 / Matrix2: ";
            res_matrix = get_matrix(in_file);
            check_matrices(matrix1 / matrix2, res_matrix);
            
            cout << endl;
            getline(in_file, s);
            for (size_t j = 0; j < 40; j++)
                cout << "=";

            cout << endl << endl;
        }
    }
}
