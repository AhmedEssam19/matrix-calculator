# Matrix-Calculator

Matrix-Calculator is a C++ program that implements the basic operations on 2D matrices that support complex domain.

Operations are Add, Subtract, Inverse, Multiply, Transpose, Determinant, Power, and Divide.

## Usage

* Surround the matrix with square brackets.
* Use comma ',' to separate rows.
* Use whitespace to separate numbers in the row.
* Enter complex numbers in the form of a+bj.
* For Add operation `A + B` enter '+'.
* For Subtract operation `A - B` enter '-'.
* For Multiply operation `A . B` enter '*'.
* For power operation enter '^', then enter positive integer as the power.
* For Transpose operation enter 'T'.
* For Determinant operation `|A|` enter 'D'.
* For Inverse operation`A^-1` enter 'I'.
* For Divide operation `A / B = A.B^-1`enter '/'.


## Example
```console
Enter first matrix: [1+j 2-j, 3 j]
Enter operator: +
Enter second matrix: [-j 5, 8.5 0.35j]
Result: [1 7-j, 11.5 1.35j] 
```
## Testing
* Python script generated 45 different test cases in three files, each contains 15 test cases. 
* The program passed all test cases.
* Memory leakage was tested by Valgrind and the program passed it.
