#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include "Matrix.h"
#include <iostream>

void print_domain(const Matrix<bool>& domain) {
  // Prints only the internal part of the matrix,
  // only fot the purpose of the game of life

  bool e;

  std::system("clear");
  for (auto j = 0; j < domain.columns(); j++) {
    std::cout << "__";
  }
  std::cout << std::endl;

  for (auto i = 1; i < domain.rows() - 1; i++) {
    std::cout << "| ";
    for (auto j = 1; j < domain.columns() - 1; j++) {
      e = domain(i, j);
      if (e == 0) {
        std::cout << "  ";
      } else {
        std::cout << "+ ";
      }
    }
    std::cout << " |";
    std::cout << std::endl;
  }

  for (auto j = 0; j < domain.columns(); j++) {
    std::cout << "==";
  }
  std::cout << std::endl;
}

#endif