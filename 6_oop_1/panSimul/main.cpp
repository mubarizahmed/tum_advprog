#include <iostream>
#include <stdexcept>

#include "person.h"

int main() {

  // A couple of quick tests to check your implementation
  // is correct.
  Person Alice(std::array<double, 2>({0.0, 0.0}));
  Person Bob(std::array<double, 2>({1.0, 2.0}));

  if (Alice.get_id() == Bob.get_id()) {
    throw std::runtime_error("Alice and Bob have the same id!");
  }

  Person Alice_copy(Alice);
  if (Alice.get_id() == Alice_copy.get_id()) {
    throw std::runtime_error("Alice and Alice_copy have the same id!");
  }

  Alice = Bob;
  if (Bob.get_location() != Alice.get_location()) {
    throw std::runtime_error("Alice and Bob shoud have the same location");
  }
}
