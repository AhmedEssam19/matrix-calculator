#pragma once

#include <string>
#include "Complex.h"
#include "Matrix.h"
#include <vector>

// split string on a specific character to a vector of strings 
vector<string>* split(string txt, char split_char);

// Eliminate spaces in the begining and at the end of string
string strip(string txt);

double round(double value, int precision);

Matrix get_matrix(ifstream& in_file);

void check_matrices(const Matrix& matrix1, const Matrix& matrix2);

Complex get_complex(ifstream& infile);

void check_complex(Complex complex1, Complex complex2);
