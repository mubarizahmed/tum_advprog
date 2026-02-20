#include "Curriculum.h"
#include "Course.h"
#include "Lecture.h"
#include "Practical.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

Curriculum::Curriculum() {
  // Of course, not every curriculum should offer the same courses, but let's simplify a bit for now. :-)
  _available_courses.push_back(std::make_shared<Lecture>("IN1503", "stardate 3025.3")); // Advanced Programming
  _available_courses.push_back(std::make_shared<Practical>("IN2186", 4));               // CFD Lab
  std::cout << "Our university now offers a new curriculum with the following courses:" << std::endl;
  print_courses();
}

void Curriculum::print_courses() const {
  std::cout << "Available courses "
            << "(id, type):" << std::endl;
  for (auto const& course : _available_courses) {
    std::cout << course->id() << ", " << course->type() << std::endl;
  }
  std::cout << "Only the aforementioned courses are officially approved.\n" << std::endl;
}

std::shared_ptr<const Course> Curriculum::request(std::string id) const {
  for (auto const& course : _available_courses) {
    if (course->id() == id) return course;
  }
  // Course not found, throw an exception which should be handled outside
  throw(std::runtime_error("Course with id " + id + " not found in available courses."));
}
