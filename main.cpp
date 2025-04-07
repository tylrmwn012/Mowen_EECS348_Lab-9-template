#include <iostream>
#include "matrix.hpp"

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> mat1_vals = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::vector<std::vector<int>> mat2_vals = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    Matrix<int> mat1(mat1_vals);
    Matrix<int> mat2(mat2_vals);

    std::cout << "Matrix 1:\n";
    mat1.print_matrix();
    std::cout << "\nMatrix 2:\n";
    mat2.print_matrix();

    std::cout << "\nMatrix 1 + Matrix 2:\n";
    Matrix<int> sum = mat1 + mat2;
    sum.print_matrix();

    std::cout << "\nMatrix 1 * Matrix 2:\n";
    Matrix<int> product = mat1 * mat2;
    product.print_matrix();

    std::cout << "\nSum of major diagonal of Matrix 1: ";
    std::cout << mat1.sum_diagonal_major() << "\n";

    std::cout << "Sum of minor diagonal of Matrix 1: ";
    std::cout << mat1.sum_diagonal_minor() << "\n";

    std::cout << "\nSwapping rows 0 and 2 in Matrix 1:\n";
    mat1.swap_rows(0, 2);
    mat1.print_matrix();

    std::cout << "\nSwapping columns 0 and 2 in Matrix 1:\n";
    mat1.swap_cols(0, 2);
    mat1.print_matrix();

    std::cout << "\nSetting value at (1,1) in Matrix 1 to 99:\n";
    mat1.set_value(1, 1, 99);
    mat1.print_matrix();

    std::cout << "\nValue at (1,1): " << mat1.get_value(1, 1) << "\n";
    std::cout << "Matrix size: " << mat1.get_size() << "x" << mat1.get_size() << "\n";

    return 0;
}

