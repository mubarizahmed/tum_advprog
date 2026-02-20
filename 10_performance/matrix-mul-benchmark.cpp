#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

/* Compile like this:
 *   g++ -O3 matrix-mul-benchmark.cpp -o matrix-mul-benchmark
 *   ./matrix-mul-benchmark
 *
 *   You should observe a high performance for smaller matrices.
 *   For larger matrices, the performance drops, as data is fetched from RAM (main memory) instead of the cache.
 */

// Simple naive matrix multiplication: C = A * B
void multiply(size_t N, const std::vector<double>& A, const std::vector<double>& B, std::vector<double>& C) {
  for (auto i = 0; i < N; ++i) {
    for (auto j = 0; j < N; ++j) {
      for (auto k = 0; k < N; ++k) {
        if (k == 0) {
          C[i * N + j] = A[i * N + k] * B[k * N + j];
        } else {
          C[i * N + j] += A[i * N + k] * B[k * N + j];
        }
      }
    }
  }
}

int main() {
  // Sizes to test: from small (cache-friendly) to large (RAM-heavy)
  std::vector<size_t> sizes = {128, 256, 384, 512, 768, 1024, 1536, 2048};

  std::cout << std::left << std::setw(10) << "Size" << std::setw(15) << "Time (s)" << std::setw(15) << "GFLOPS"
            << std::endl;
  std::cout << "------------------------------------------" << std::endl;

  for (auto N : sizes) {
    std::vector<double> A(N * N, 1.1), B(N * N, 2.2), C(N * N, 0.0);

    auto start = std::chrono::high_resolution_clock::now();
    multiply(N, A, B, C);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end - start;

    // Matrix mult is (2N - 1)*N*N operations
    double gflops = (2.0 * N - 1.0) * N * N / (diff.count() * 1e9);

    std::cout << std::left << std::setw(10) << N << std::setw(15) << std::fixed << std::setprecision(4) << diff.count()
              << std::setw(15) << gflops << std::endl;
  }

  return 0;
}