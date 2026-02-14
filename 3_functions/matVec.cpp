#include <cstddef>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/src/Core/Matrix.h>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

template <typename T>
void print_vector(std::vector<T> to_print, const std::string& label = "v") {
    std::cout << label << ": " << "( ";
    for (auto elem : to_print) {
        std::cout << elem;
        if (to_print.back() == elem) {
            std::cout << " )" << std::endl;
        } else {
            std::cout << ", ";
        }
    }
}

template <typename T>
void print_matrix(std::vector<std::vector<T>> to_print, const std::string& label = "A") {
    std::cout << label << ": " << "\t";
    // get references dont make copies!
    for (auto& row : to_print) {
        for (auto& cell : row) {
            std::cout << cell;
            // compare references not values wont work if comparing to copies!!
            if (&row.back() == &cell) {
                std::cout << std::endl;
            } else {
                std::cout << '\t';
            }
        }
        if (&to_print.back() != &row) {
            std::cout << "\t";
        }
    }
}

template <typename T>
std::vector<T> operator*(const std::vector<std::vector<T>>& matrix, const std::vector<T>& vector) {
    std::size_t N = vector.size();
    std::vector<int> result(N, 0); // init resultant vector
    for (auto i = 0U; i < N; i++) {
        for (auto j = 0U; j < N; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }

    return result;
}

template <typename T>
using Matrix = std::vector<std::vector<T>>;
template <typename T>
using Vector = std::vector<T>;

template <typename T>
std::pair<Vector<T>, Matrix<T>> generate_matrix_vector_pair(unsigned int N) {
    // random number generator
    std::mt19937 gen(0);

    std::uniform_real_distribution<> float_dist(-999.0, 999.0);

    Vector<T> vector(N);
    for (auto i = 0U; i < N; i++) {
        vector[i] = static_cast<T>(float_dist(gen));
    }

    Matrix<T> matrix(N);
    for (auto i = 0U; i < N; i++) {
        for (auto j = 0U; j < N; j++) {
            matrix[i].push_back(static_cast<T>(float_dist(gen)));
        }
    }

    return {vector, matrix};
}

bool test_matrix_vector_product() {
    std::mt19937 gen(0);
    std::uniform_int_distribution<> int_dist(2, 10);

    int N = int_dist(gen);

    std::pair<Vector<int>, Matrix<int>> int_pair = generate_matrix_vector_pair<int>(N);
    Vector<int> r_int = int_pair.second * int_pair.first;

    print_vector(r_int, "result int");

    Eigen::Map<Eigen::VectorXi> v_i_t(int_pair.first.data(), int_pair.first.size());

    // 1. Initialize a Row-Major Matrix (dynamic or fixed size)
    Eigen::Matrix<int, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> m_i_t(N, N);

    // 2. Copy data row-by-row
    for (size_t i = 0; i < N; ++i) {
        // Map the i-th inner vector and assign it to the i-th row
        m_i_t.row(i) = Eigen::Map<Eigen::VectorXi>(int_pair.second[i].data(), N);
    }

    std::cout << "matrix: \n" << m_i_t << std::endl;
    std::cout << "vec: \n" << v_i_t << std::endl;
    std::cout << "result: \n" << m_i_t * v_i_t << std::endl;

    return true;
}

int main() {
    std::vector<int> v;

    // Vector Input
    // int x;
    // std::cout << "Enter vector elements:" << std::endl;
    // while (std::cin >> x) {
    //     v.push_back(x);
    // }
    // std::cin.clear();
    // std::cin.ignore();

    // print_vector(v);
    // const auto N = v.size();

    // Matrix Input
    // std::cout << "Enter the " << N * N << " elements of the square matrix (row first):" << std::endl;
    // std::vector<std::vector<int>> A(N);
    // for (auto i = 0U; i < N; i++) {
    //     for (auto j = 0U; j < N; j++) {
    //         int y;
    //         std::cin >> y;
    //         A[i].push_back(y);
    //     }
    // }

    // print_matrix(A);

    // Multiplication
    // std::vector<int> m(N, 0); // init resultant vector
    // for (auto i = 0U; i < N; i++) {
    //     for (auto j = 0U; j < N; j++) {
    //         m[i] += A[i][j] * v[j];
    //     }
    // }
    // print_vector(m, "m");

    test_matrix_vector_product();

    return 0;
}
