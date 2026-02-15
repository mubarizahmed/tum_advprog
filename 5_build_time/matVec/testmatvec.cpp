#include <cassert>
#include <cstddef>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/src/Core/Matrix.h>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

template <typename T>
using Matrix = std::vector<std::vector<T>>;
template <typename T>
using Vector = std::vector<T>;

template <typename T>
std::vector<T> operator*(const std::vector<std::vector<T>> &matrix, const std::vector<T> &vector) {
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

int main() {
    std::mt19937 gen(0);
    std::uniform_int_distribution<> int_dist(2, 10);

    int N = int_dist(gen);

    std::pair<Vector<int>, Matrix<int>> int_pair = generate_matrix_vector_pair<int>(N);

    // manual result
    Vector<int> r_int = int_pair.second * int_pair.first;
    Eigen::Map<Eigen::VectorXi> res_manual(r_int.data(), r_int.size());

    // using eigen
    Eigen::Map<Eigen::VectorXi> v_i_t(int_pair.first.data(), int_pair.first.size());

    Eigen::Matrix<int, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> m_i_t(N, N);
    for (size_t i = 0; i < N; ++i) {
        // Map the i-th inner vector and assign it to the i-th row
        m_i_t.row(i) = Eigen::Map<Eigen::VectorXi>(int_pair.second[i].data(), N);
    }

    Eigen::VectorXi res_eigen = m_i_t * v_i_t;

    std::cout << "matrix: \n" << m_i_t << std::endl;
    std::cout << "vec: \n" << v_i_t << std::endl;
    std::cout << "result: \n" << m_i_t * v_i_t << std::endl;

    assert(res_manual == res_eigen);

    return 0;
}
