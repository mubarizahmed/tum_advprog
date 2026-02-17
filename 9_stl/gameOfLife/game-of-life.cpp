#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <thread>

#include "Matrix.h"
#include "utilities.h"

std::vector<bool> get_neighbors(Matrix<bool> &domain, int i, int j) {
    // Return all my neighbors, but not myself:
    // + + +    4 0 6
    // + o +    2 o 3
    // + + +    7 1 5
    return std::vector<bool>{domain(i - 1, j), domain(i + 1, j), domain(i, j - 1), domain(i, j + 1),
        domain(i - 1, j - 1), domain(i + 1, j + 1), domain(i - 1, j + 1), domain(i + 1, j - 1)};
}

void evolve(char &value) {
    /** We needed to encode more information here:
     *  If a cell is alive, we offset its sum with an arbitrary value of 100.
     *  If it is dead, there is no offset.
     *
     * Why?
     * - Because evolve() needs to only have one argument
     *   to be able to use it with for_each.
     * - Because we had no each way to access the actual value (dead or alive)
     *   without storing it as a pair with the sum.
     *
     * If you want to apply a more readable way, you probably want to go for it.
     **/

    if (value == 2) {
        value = 0;
    } else if (value == 102) {
        value = 1;
    } else if (value == 3 || value == 103) {
        value = 1;
    } else {
        value = 0;
    }
}

void set_boundaries(Matrix<bool> &domain) {
    // Each cell needs its direct neighbors (i+-1, j+-1).
    // To make this easier, we wrap the inner matrix (actual domain) with a ghost layer.
    // The ghost layer contains copies of the rows and columns of the other side.

    auto N = domain.rows();

    // Store a copy of the top-most real row into the bottom ghost layer
    domain.set_row(N - 1, domain.get_row(1));
    // Reverse: store a copy of the bottom-most real row into the top ghost layer
    domain.set_row(0, domain.get_row(N - 2));
    // Similarly for the left- and right-most columns
    domain.set_column(N - 1, domain.get_column(1));
    domain.set_column(0, domain.get_column(N - 2));

    // Match the corners to the opposite diagonals
    domain(0, 0) = domain(N - 2, N - 2);
    domain(N - 1, N - 1) = domain(1, 1);
    domain(0, N - 1) = domain(N - 2, 1);
    domain(N - 1, 0) = domain(1, N - 2);
}

int main() {

    // Main parameters to play with: size of the domain, number of iterations, visualization pause interval
    const auto N = 10;
    const auto epochs = 5;
    std::chrono::milliseconds sleep_time(1000);

    Matrix<bool> domain(N, N);
    set_boundaries(domain);

    Matrix<char> sums(N - 2, N - 2, 0);

    // Main time loop: each epoch is one iteration
    for (auto t = 0; t < epochs; t++) {

        /**
         *  Main steps of our game of life implementation:
         *  1. Get all the neighbors of each cell (to be able to pass them to an algorithm).
         *  2. Store the sum of the neighbors of each cell in a separate sums matrix.
         *     For the cells that are alive, offset the sum by 100 (see comments in evolve()).
         *  3. Apply evolve() to each element of sums, modifying sums in-place.
         *  4. Copy the new sums back to domain.
         *  5. Apply a periodic boundary condition.
         **/
        for (auto i = 1; i < N - 1; i++) {
            for (auto j = 1; j < N - 1; j++) {
                auto neighbors = get_neighbors(domain, i, j);
                if (domain(i, j) == 1) {
                    sums(i - 1, j - 1) = 100;
                }
                // TODO: Apply an algorithm to accumulate (calculate the sum of) all
                // the neighbors of this cell and store it to the sums(i-1, j-1)
                char neighbors_sum = std::accumulate(neighbors.begin(), neighbors.end(), 0);
                sums(i - 1, j - 1) = neighbors_sum;
            }
        }
        // TODO: Apply the evolve function to each element in sums
        std::for_each(sums.begin(), sums.end(), evolve);

        // Copying the new sums back to the domain
        for (auto i = 1; i < N - 1; i++) {
            for (auto j = 1; j < N - 1; j++) {
                domain(i, j) = sums(i - 1, j - 1);
            }
        }

        set_boundaries(domain);

        // TODO-Idea: Replace this printing with a plot, using an external
        // visualization library, such as one of:
        // https://github.com/sciplot/sciplot
        // https://github.com/alandefreitas/matplotplusplus
        // https://github.com/lava/matplotlib-cpp
        print_domain(domain);

        // Feel free to remove this, we only add
        // it here to make the evolution easier to observe
        std::this_thread::sleep_for(sleep_time);
    }
}

// TODO-Idea: Replace the .begin()/.end() versions of these algorithms with C++20 ranges.
