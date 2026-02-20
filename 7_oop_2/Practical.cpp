#include <iostream>
#include <string>

#include "Practical.h"

Practical::Practical(std::string id, std::size_t num_worksheets)
    : Course(id), _num_worksheets(num_worksheets) {
  std::cout << "Constructing the practical " << _id << std::endl;
}

std::string Practical::type() const {
  return "Practical";
}

void Practical::describe() const {
  std::cout << "This is a must-take practical course. Don't miss it!\n"
            << "There are " << _num_worksheets << " worksheets in this practical course." << std::endl;
}
