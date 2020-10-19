#include "Matrix.h"
#include "helpers.h"

// No-Arg constructor
Matrix::Matrix():matrix{nullptr}, rows{0}, cols{0} {}

Matrix::Matrix(const string& mat)
{
    // split string to rows
    vector<string>* rows_of_string = split(mat, ',');
    this->rows = rows_of_string->size();
    this->cols = 0;
    matrix = new vector<vector<Complex>*>(rows);

    // split each row to Complex objects
    for (size_t i = 0; i < rows; i++)
    {
        matrix->at(i) = string_to_complex(rows_of_string->at(i));
        this->cols = matrix->at(i)->size();
    }

    delete rows_of_string;
}

Matrix::Matrix(vector<vector<Complex> *> * matrix):matrix{matrix}, rows{matrix->size()}, 
cols{matrix->at(0)->size()} {}

// Copy constructor
Matrix::Matrix(const Matrix& source): rows{source.rows}, cols{source.cols}
{
    matrix = new vector<vector<Complex>*>(rows, new vector<Complex>(cols));
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            matrix->at(i)->at(j) = source.at(i, j);
}

// Move construcor
Matrix::Matrix(Matrix&& source): matrix{source.matrix}
{
    source.matrix = nullptr;
}

// Destructor
Matrix::~Matrix()
{
    Matrix::free_memory();
}

// Access matrix elements
Complex& Matrix::at(size_t i, size_t j) const
{
    return matrix->at(i)->at(j);
}

// Convert string to vector of Complex objects
vector<Complex>* Matrix::string_to_complex(string row)
{
    vector<Complex>* vec = new vector<Complex>;
    vector<string>* row_of_strings = split(row, ' ');
    for (const string& complex: *row_of_strings)
        vec->push_back(Complex(complex));

    delete row_of_strings;
    return vec;
}

void Matrix::print() const
{
    cout << "RESULT: [";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix->at(i)->at(j).print();

			if (j != cols - 1)
				cout << ' ';
		}
		if (i != rows - 1)
			cout << ", ";
	}
	cout << "]\n";
}

// Free allocated memory
void Matrix::free_memory()
{
    for (size_t i = 0; i < rows; i++)
        delete matrix->at(i);

    delete matrix;
}
