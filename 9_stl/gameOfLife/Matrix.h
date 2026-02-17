#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <algorithm>
#include <cstdlib>
#include <vector>

/* Matrix:
 * A wrapper class around raw dynamically allocated arrays to provide
 * more convenient syntax for accessing elements.
 */

template <typename T>
class Matrix {
    const std::size_t _rows;
    const std::size_t _cols;
    T *_arr;

  public:
    Matrix(std::size_t rows, std::size_t cols)
        : _rows(rows), _cols(cols), _arr(new T[rows * cols]) {
        // Initialize to some random values
        std::generate(begin(), end(), []() { return static_cast<T>(std::rand() % 2); });
    }

    Matrix(std::size_t rows, std::size_t cols, T uniform_value)
        : _rows(rows), _cols(cols), _arr(new T[rows * cols]) { // Initialize to a given uniform value
        // TODO: Apply an algorithm to fill this object with the uniform_value
        std::fill(_arr, _arr + (rows * cols), uniform_value);
    }

    Matrix() = delete;

    T &operator()(int i, int j) {
        return _arr[i * _cols + j];
    }

    const T &operator()(int i, int j) const {
        return _arr[i * _cols + j];
    }

    std::vector<T> get_row(std::size_t i) {
        std::vector<T> row(_cols);

        // Copy from the address of _arr[i*_cols] to (exclusive) _arr[(i+1)*_cols]
        std::copy(_arr + i * _cols, _arr + (i + 1) * _cols, row.begin());

        return row;
    }

    void set_row(std::size_t i, const std::vector<T> &from) {
        auto begin_address = _arr + i * _cols;
        // TODO: Apply an algorithm to copy all the elements from the given vector
        // to a given row of this object. You can use the begin_address.
        std::copy(from.begin(), from.end(), begin_address);
    }

    std::vector<T> get_column(std::size_t j) {
        std::vector<T> column(_rows);

        // The elements of the column are not stored contiguously,
        // therefore we need to get them manually
        for (auto i = 0; i < _rows; i++) {
            column[i] = this->operator()(i, j);
        }

        return column;
    }

    void set_column(std::size_t j, const std::vector<T> &from) {
        for (auto i = 0; i < _rows; i++) {
            // We have not checked if from has at least as many elements
            // as we are trying to access, so let's better use .at()
            this->operator()(i, j) = from.at(i);
        }
    }

    Matrix(const Matrix &from)
        : _rows(from._rows), _cols(from._cols) {
        _arr = new T[from._rows * from._cols];
        std::copy(from._arr, from._arr + from._rows * from._cols, _arr);
    }

    Matrix &operator=(const Matrix &from) {
        if (this == &from) {
            return *this;
        }

        if (_rows == from._rows && _cols == from._cols) {
            std::copy(from._arr, from._arr + from._rows * from._cols, _arr);
        } else {
            throw std::invalid_argument("The two matrices need to have the same size to be assigned");
        }

        return *this;
    }

    ~Matrix() {
        delete[] _arr;
    }

    T *data() {
        return _arr;
    }

    T *begin() {
        return _arr;
    }

    T *end() {
        return _arr + (_rows * _cols);
    }

    std::size_t rows() const {
        return _rows;
    }

    std::size_t columns() const {
        return _cols;
    }
};

#endif