#include <iostream>
#include <vector>

void print_vector(std::vector<int> to_print, const std::string& label = "v") {
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

void print_matrix(std::vector<std::vector<int>> to_print, const std::string& label = "A") {
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

int main() {
    std::vector<int> v;

    // Vector
    int x;
    std::cout << "Enter vector elements:" << std::endl;
    while (std::cin >> x) {
        v.push_back(x);
    }
    std::cin.clear();
    std::cin.ignore();

    print_vector(v);
    const auto N = v.size();

    // Matrix
    std::cout << "Enter the " << N * N << " elements of the square matrix (row first):" << std::endl;
    std::vector<std::vector<int>> A(N);
    for (auto i = 0U; i < N; i++) {
        for (auto j = 0U; j < N; j++) {
            int y;
            std::cin >> y;
            A[i].push_back(y);
        }
    }

    print_matrix(A);

    // Multiplication
    std::vector<int> m(N, 0); // init resultant vector
    for (auto i = 0U; i < N; i++) {
        for (auto j = 0U; j < N; j++) {
            m[i] += A[i][j] * v[j];
        }
    }
    print_vector(m, "m");

    return 0;
}
