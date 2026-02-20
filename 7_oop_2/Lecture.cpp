#include <iostream>
#include <string>

#include "Lecture.h"

Lecture::Lecture(std::string id, std::string exam_date)
    : Course(id), _exam_date(exam_date) {
  std::cout << "Constructing the lecture " << _id << std::endl;
}

std::string Lecture::type() const {
  return "Lecture";
}

void Lecture::describe() const {
  std::cout << "This is a must-take lecture. Don't miss it!\n"
            << "The final exam is on " << _exam_date << "." << std::endl;
}
