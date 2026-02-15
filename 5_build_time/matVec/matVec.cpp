#include <cstddef>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/src/Core/Matrix.h>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

using RowMatrixXd = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>;

void print_vector(Eigen::VectorXd &to_print, const std::string &label = "v") {
    std::cout << label << ": " << "( " << to_print << " )\n";
}

void print_matrix(RowMatrixXd &to_print, const std::string &label = "A") {
    std::cout << label << ": " << "\n" << to_print << "\n";
}

int main() {
    std::vector<double> v;

    // Vector Input
    double x;

    std::cout << "Enter vector elements:" << std::endl;
    while (std::cin >> x) {
        v.push_back(x);
    }
    std::cin.clear();
    std::cin.ignore();

    Eigen::VectorXd vec = Eigen::Map<Eigen::VectorXd>(v.data(), v.size());
    print_vector(vec);
    const auto N = v.size();

    // Matrix Input
    std::cout << "Enter the " << N * N << " elements of the square matrix (row first):" << std::endl;
    std::vector<double> A(N * N);
    for (auto i = 0U; i < N * N; i++) {
        double y;
        std::cin >> y;
        A[i] = y;
    }

    RowMatrixXd mat = Eigen::Map<RowMatrixXd>(A.data(), N, N);

    print_matrix(mat);

    // Multiplication
    std::cout << "Result: \n" << mat * vec << "\n";

    return 0;
}
