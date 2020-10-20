import numpy as np
from numpy.linalg import matrix_power


def main():
    np.set_printoptions(precision=3)
    with open("test_cases3.txt", "wt") as file:
        for i in range(15):
            file.write(f"Test Case #{i + 1}:\n")
            arr1 = create_random_complex_matrix()
            file.write("Matrix1: " + matrix_to_string(arr1))
            file.write('\n')
            arr2 = create_random_complex_matrix()
            file.write("Matrix2: " + matrix_to_string(arr2))
            file.write('\n')
            file.write("Add: " + matrix_to_string(arr1 + arr2))
            file.write('\n')
            file.write("subtract: " + matrix_to_string(arr1 - arr2))
            file.write('\n')
            file.write("Multiply: " + matrix_to_string(arr1 @ arr2))
            file.write('\n')
            file.write("Matrix1 power 4: " + matrix_to_string(matrix_power(arr1, 4)))
            file.write('\n')
            file.write("Matrix2 power 4: " + matrix_to_string(matrix_power(arr2, 4)))
            file.write('\n')
            file.write("Matrix1 transpose: " + matrix_to_string(arr1.T))
            file.write('\n')
            file.write("Matrix2 transpose: " + matrix_to_string(arr2.T))
            file.write('\n')
            file.write("Matrix1 determinant: " + str(np.round(np.linalg.det(arr1), decimals=2))[1:-1])
            file.write('\n')
            file.write("Matrix2 determinant: " + str(np.round(np.linalg.det(arr2), decimals=2))[1:-1])
            file.write('\n')
            file.write("Matrix1 inverse: " + matrix_to_string(np.linalg.inv(arr1)))
            file.write('\n')
            file.write("Matrix2 inverse: " + matrix_to_string(np.linalg.inv(arr2)))
            file.write('\n')
            file.write("Matrix1 / Matrix2: " + matrix_to_string(arr1 @ np.linalg.inv(arr2)))
            file.write('\n')
            file.write("=" * 300)
            file.write('\n')


def matrix_to_string(matrix):
    lst = []
    for row in matrix:
        sup_lst = []
        for element in row:
            if str(element)[0] == "(":
                sup_lst.append(str(element)[1:-1])
            else:
                sup_lst.append((str(element)))

        lst.append(" ".join(element for element in sup_lst))

    return "[" + ", ".join(row for row in lst) + "]"


def create_random_complex_matrix():
    np.set_printoptions(precision=3)
    a = np.random.randint(10, size=(4, 4))
    b = np.random.randint(10, size=(4, 4))
    arr = np.empty((4, 4), dtype=complex)
    arr.real = a
    arr.imag = b
    return arr


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    main()
