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

    Matrix(const Matrix& source);

    Matrix(Matrix&& source);

    ~Matrix();

    Complex& at(size_t i, size_t j) const;

    Matrix& operator=(const Matrix& source);

    Matrix& operator=(Matrix&& source);

    Matrix operator+(Matrix mat) const;

    Matrix operator-(Matrix mat) const;

    Matrix operator*(Matrix mat) const;

    Matrix transpose() const;

    Matrix power(int n) const;

    Complex determinant() const;

    Matrix inverse() const;

    Matrix operator/(Matrix mat) const;

    void print() const;

private:
    vector<Complex>* string_to_complex(string row);

    void free_memory();

    void copy_matrix(const Matrix& source);

    Matrix supp_matrix(size_t row, size_t col) const;

    vector<vector<Complex> *> * get_2D_vector(size_t rows, size_t cols) const;
};
