#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>

#include <iostream>
#include <stdexcept>

// all of your function definitions should be in this file now
template <typename T>
class Matrix {
public:
    Matrix(std::size_t N);
    Matrix(std::vector<std::vector<int>> nums);

    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;
    void set_value(std::size_t i, std::size_t j, int n);
    int get_value(std::size_t i, std::size_t j) const;
    int get_size() const;
    int sum_diagonal_major() const;
    int sum_diagonal_minor() const;
    void swap_rows(std::size_t r1, std::size_t r2);
    void swap_cols(std::size_t c1, std::size_t c2);
    void print_matrix() const;

private:
    std::vector<std::vector<T>> data;
    std::size_t size;
};


// functions go here:
// 1. Read values from a file into the matrix
    // constructor of size
template <typename T>
Matrix<T>::Matrix(std::size_t N) : size(N), data(N, std::vector<T>(N, 0)) {}

    // constructor from vector of vectors
template <typename T>
Matrix<T>::Matrix(std::vector<std::vector<int>> nums) {
    size = nums.size();
    data.resize(size, std::vector<T>(size));
    for (std::size_t i = 0; i < size; ++i)
        for (std::size_t j = 0; j < size; ++j)
            data[i][j] = static_cast<T>(nums[i][j]);
}

// 2. Add two matrices and display the result
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs) const {
    if (size != rhs.size)
        throw std::invalid_argument("Matrix sizes do not match for addition.");
    Matrix<T> result(size);
    for (std::size_t i = 0; i < size; ++i)
        for (std::size_t j = 0; j < size; ++j)
            result.data[i][j] = data[i][j] + rhs.data[i][j];
    return result;
}

// 3. Multiply two matrices and display the result
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &rhs) const {
    if (size != rhs.size)
        throw std::invalid_argument("Matrix sizes do not match for multiplication.");
    Matrix<T> result(size);
    for (std::size_t i = 0; i < size; ++i)
        for (std::size_t j = 0; j < size; ++j)
            for (std::size_t k = 0; k < size; ++k)
                result.data[i][j] += data[i][k] * rhs.data[k][j];
    return result;
}

// 4. Get the sum of matrix diagonal elements
    // set_value
template <typename T>
void Matrix<T>::set_value(std::size_t i, std::size_t j, int n) {
    if (i >= size || j >= size)
        throw std::out_of_range("Index out of bounds in set_value.");
    data[i][j] = static_cast<T>(n);
}

    // get_value
template <typename T>
int Matrix<T>::get_value(std::size_t i, std::size_t j) const {
    if (i >= size || j >= size)
        throw std::out_of_range("Index out of bounds in get_value.");
    return static_cast<int>(data[i][j]);
}

    // get)size
template <typename T>
int Matrix<T>::get_size() const {
    return static_cast<int>(size);
}

    // sum of major
template <typename T>
int Matrix<T>::sum_diagonal_major() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i)
        sum += data[i][i];
    return sum;
}

    // sum of minor
template <typename T>
int Matrix<T>::sum_diagonal_minor() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i)
        sum += data[i][size - i - 1];
    return sum;
}

// 5. Swap matrix rows and display the result
template <typename T>
void Matrix<T>::swap_rows(std::size_t r1, std::size_t r2) {
    if (r1 >= size || r2 >= size)
        throw std::out_of_range("Invalid row indices.");
    std::swap(data[r1], data[r2]);
}

// 6. Swap matrix columns and display the result
template <typename T>
void Matrix<T>::swap_cols(std::size_t c1, std::size_t c2) {
    if (c1 >= size || c2 >= size)
        throw std::out_of_range("Invalid column indices.");
    for (std::size_t i = 0; i < size; ++i)
        std::swap(data[i][c1], data[i][c2]);
}

// 7. Update matrix rows and display the result
template <typename T>
void Matrix<T>::print_matrix() const {
    for (const auto &row : data) {
        for (const auto &val : row)
            std::cout << val << " ";
        std::cout << "\n";
    }
}

#endif // __MATRIX_HPP__
