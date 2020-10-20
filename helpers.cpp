#include "helpers.h"
#include "Matrix.h"
#include <iostream>
#include <fstream>
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


void print_vector(vector<vector<Complex>*>* matrix)
{
    for (size_t i = 0; i < matrix->size(); i++)
    {
        for (size_t j = 0; j < matrix->at(i)->size(); j++)
        {
            matrix->at(i)->at(j).print();
            cout << " ";
        }  
        cout << endl;
    }
}

double round(double value, int precision)
{
	long long power = pow(10, precision);
	double val = (long) (value * power + 0.5);
	return (double) val / power;
}


Matrix get_matrix(ifstream& in_file)
{
    string line;
    getline(in_file, line);
    size_t idx = line.find(':');
    return Matrix(line.substr(idx + 2));
}


void check_matrices(const Matrix& matrix1, const Matrix& matrix2)
{
    if (matrix1 == matrix2)
        cout << "passed.\n";
    else
    {
        cout << "failed.\n";
        matrix1.print();
        matrix2.print();
    }
}


Complex get_complex(ifstream& in_file)
{
    string line;
    getline(in_file, line);
    size_t idx = line.find(':');
    return Complex(line.substr(idx + 2));
}


void check_complex(Complex complex1, Complex complex2)
{
    if (complex1 == complex2)
        cout << "passed.\n";
    else
    {
        cout << "failed.\n";
        complex1.print();
        cout << endl;
        complex2.print();
        cout << endl;
    }
}
