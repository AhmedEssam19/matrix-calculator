#pragma once

#include <vector>
#include <string>
#include "Complex.h"
using namespace std;

class Matrix
{
private:
    vector<vector<Complex> *> * matrix;
    size_t rows;
    size_t cols;

public:

    Matrix();

    Matrix(const string& mat);

    Matrix(vector<vector<Complex> *> * matrix);

    ~Matrix();

    Matrix operator+(Matrix mat) const;

    Matrix operator-(Matrix mat) const;

    Matrix operator*(Matrix mat) const;

    Matrix transpose() const;

    Matrix power(int n) const;

    Complex determinant() const;

    Matrix inverse() const;

    Matrix divide(Matrix mat) const;

    void print() const;

private:
    vector<Complex>* string_to_complex(string row);
};
