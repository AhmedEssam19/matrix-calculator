#include "Matrix.h"
#include "helpers.h"

const set<char> Matrix::ALLOWED_CHARACTERS {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                                            '.', '+', '-', 'j', 'e', ' ', ','};


// No-Arg constructor
Matrix::Matrix(): matrix{nullptr}, rows{0}, cols{0} {}


Matrix::Matrix(const string& mat)
{
    string string_matrix = strip(mat);
    if (string_matrix.front() != '[' || string_matrix.back() != ']')
    {
        cout << "ERROR: missing square brackets.\n";
        throw exception();
    }
    string_matrix = string_matrix.substr(1, string_matrix.length() - 2);

    for (size_t i = 0; i < string_matrix.length(); i++)
    {
        auto it = ALLOWED_CHARACTERS.find(string_matrix[i]);
        if (it == ALLOWED_CHARACTERS.end())
        {
            cout << "ERROR: invalid character(s).\n";
            throw exception();
        }
    }
    
    // split string to rows
    vector<string>* rows_of_string = split(string_matrix, ',');
    this->rows = rows_of_string->size();
    this->cols = 0;
    matrix = new vector<vector<Complex>*>(rows);

    // split each row to Complex objects
    for (size_t i = 0; i < rows; i++)
    {
        matrix->at(i) = string_to_complex(rows_of_string->at(i));
        if (i == 0)
            this->cols = matrix->at(i)->size();
        if (this->cols != matrix->at(i)->size())
        {
            cout << "ERROR: non-consistent number of element in row.\n";
            throw exception();
        }
    }

    delete rows_of_string;
}


Matrix::Matrix(vector<vector<Complex> *> * matrix): matrix{matrix}, rows{matrix->size()}
{
    if (rows > 0)
        cols = matrix->at(0)->size();
    else
        cols = 0;
}


// Copy constructor
Matrix::Matrix(const Matrix& source): rows{source.rows}, cols{source.cols}
{
    this->copy_matrix(source);
}


// Move construcor
Matrix::Matrix(Matrix&& source): matrix{source.matrix}, rows{source.rows}, cols{source.cols}
{
    source.matrix = nullptr;
}


// Destructor
Matrix::~Matrix()
{
    this->free_memory();
}


// Access matrix elements
Complex& Matrix::at(size_t i, size_t j) const
{
    return matrix->at(i)->at(j);
}


// Get number of columns
size_t Matrix::get_columns() const
{
    return cols;
}


// Get number of rows
size_t Matrix::get_rows() const
{
    return rows;
}


// Copy assignment
Matrix& Matrix::operator=(const Matrix& source)
{
    if (this == &source)
        return *this;

    free_memory();
    this->rows = source.rows;
    this->cols = source.cols;
    copy_matrix(source);

    return *this;
}


// Move assignment
Matrix& Matrix::operator=(Matrix&& source)
{
    if (this == &source)
        return *this;

    free_memory();
    matrix = source.matrix;
    this->rows = source.rows;
    this->cols = source.cols;
    source.matrix = nullptr;
    
    return *this;
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


ostream& operator<<(ostream& os, const Matrix& matrix)
{
    size_t rows = matrix.get_rows();
    size_t cols = matrix.get_columns();
    os << "[";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrix.at(i, j);

			if (j != cols - 1)
				os << ' ';
		}
		if (i != rows - 1)
			os << ", ";
	}
	os << "]\n";
}


// Free allocated memory
void Matrix::free_memory()
{
    if (matrix == nullptr)
        return;

    for (size_t i = 0; i < rows; i++)
        delete matrix->at(i);

    delete matrix;
}


// Copy source matrix to caller matrix
void Matrix::copy_matrix(const Matrix& source)
{
    matrix = get_2D_vector(rows, cols);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            this->at(i, j) = source.at(i, j);
}


Matrix Matrix::operator+(const Matrix& mat) const
{
    // check that both matrices have the same shape
    if (this->rows != mat.rows || this->cols != mat.cols)
    {
        cout << "ERROR: matrices don't have the same shape.\n";
        throw exception();
    }

    vector<vector<Complex>*>* res_matrix = get_2D_vector(rows, cols);

    for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			res_matrix->at(i)->at(j) = this->at(i, j) + mat.at(i, j);

    return Matrix(res_matrix);
}


Matrix Matrix::operator-(const Matrix& mat) const
{
    // check that both matrices have the same shape
    if (this->rows != mat.rows || this->cols != mat.cols)
    {
        cout << "ERROR: matrices don't have the same shape.\n";
        throw exception();
    }

    vector<vector<Complex>*>* res_matrix = get_2D_vector(rows, cols);

    for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			res_matrix->at(i)->at(j) = this->at(i, j) - mat.at(i, j);

    return Matrix(res_matrix);
}


Matrix Matrix::operator*(const Matrix& mat) const
{
    if (this->cols != mat.rows)
    {
        cout << "Error: dimention mismatch.\n";
        throw exception();
    }

    vector<vector<Complex>*>* res_matrix = get_2D_vector(this->rows, mat.cols);

    for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < mat.cols; j++)
			for (int k = 0; k < this->cols; k++)
					res_matrix->at(i)->at(j) = res_matrix->at(i)->at(j) + this->at(i, k) * mat.at(k, j);
        
    return Matrix(res_matrix);
}


Matrix Matrix::transpose() const
{
    vector<vector<Complex>*>* res_matrix = get_2D_vector(cols, rows);

    for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			res_matrix->at(j)->at(i) = this->at(i, j);
    
    return Matrix(res_matrix);
}


Matrix Matrix::power(double n) const
{
    // must be square matrix
    if (this->cols != this->rows)
    {
        cout << "Error: not square matrix.\n";
        throw exception();
    }
    // integer must be positive integer
    if (int(n) != n || int(n) < 1)
    {
        cout << "Error: non-positive integer power.\n";
        throw exception();
    }

    Matrix res_matrix(*this);
    for (size_t i = 0; i < n - 1; i++)
        res_matrix = res_matrix * (*this);
    
    return res_matrix;
}


Complex Matrix::determinant() const
{
    // must be square matrix
    if (this->cols != this->rows)
    {
        cout << "Error: not square matrix.\n";
        throw exception();
    }

    // base case
    if (rows == 1)
        return this->at(0, 0);

    // recursive case
    Complex det;
    int sign = 1;
    for (size_t k = 0; k < cols; k++)
	{
	    det = det + (this->at(0, k) * (supp_matrix(0, k).determinant()) * sign);
	    sign *= -1;
	}
    
    return det;
}


// Create supp matrix at specific element 
Matrix Matrix::supp_matrix(size_t row_number, size_t col_number) const
{
    vector<vector<Complex>*>* new_matrix = get_2D_vector(rows - 1, cols - 1);
    size_t row = 0;
    for (size_t i = 0; i < rows; i++)
    {
        // skip the row where the element located
        if (i == row_number)
           continue;

        size_t col = 0;
        for (size_t j = 0; j < cols; j++)
        {
            // skip the column where the element located 
            if (j == col_number)
                continue;

            new_matrix->at(row)->at(col) = this->at(i, j);
            col++;
        }
        row++;
    }

    return Matrix(new_matrix);
}


Matrix Matrix::inverse() const
{
    // must be square matrix
    if (this->cols != this->rows)
    {
        cout << "Error: not square matrix.\n";
        throw exception();
    }

    Complex factor = determinant().inverted();
    vector<vector<Complex>*>* res_matrix = get_2D_vector(rows, cols);

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            res_matrix->at(i)->at(j) = factor * (supp_matrix(j, i).determinant()) * pow(-1, i + j);
        
    return Matrix(res_matrix);
}


Matrix Matrix::operator/(const Matrix& mat) const
{
    // must be square matrix
    if (this->cols != this->rows)
    {
        cout << "Error: not square matrix.\n";
        throw exception();
    }

    return *this * mat.inverse();
}


vector<vector<Complex>*>* Matrix::get_2D_vector(size_t rows, size_t cols) const
{
    vector<vector<Complex>*>* array = new vector<vector<Complex>*> (rows);
    for (size_t i = 0; i < rows; i++)
        array->at(i) = new vector<Complex>(cols);
    
    return array;
}


// check for equality
bool Matrix::operator==(const Matrix& mat) const
{
    if (this == &mat)
        return true;

    if (!(this->rows == mat.rows && this->cols == mat.cols))
        return false;
    
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (!(this->at(i, j) == mat.at(i, j)))
                return false;
        
    return true;
}