#pragma once

#include <string>
#include "Complex.h"
#include <vector>

// split string on a specific character to a vector of strings 
vector<string>* split(string txt, char split_char);

// Eliminate spaces in the begining and at the end of string
string strip(string txt);

bool checkMatrix(string Matrix, Complex matrix[][100], int& row, int& col);
void showMat(Complex matrix[][100], int row, int col);
void suppMat(Complex matrix[][100], int rownum, int colnum, int n, Complex temp[][100]);
Complex det(Complex matrix[][100], int row);
void copyMat(Complex matrix1[][100], Complex matrix2[][100], int row, int col);
