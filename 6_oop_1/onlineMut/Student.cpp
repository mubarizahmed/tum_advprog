#include "Student.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

Student::Student(std::string name, std::string reg_no)
    : _name{name}, _reg_no{reg_no} {}

bool Student::register_for(const Course &course) {
    _registeredCourses.push_back(course);

    return true;
}
void Student::list_courses() {
    std::cout << "Registered courses:\n";
    std::for_each(_registeredCourses.begin(), _registeredCourses.end(),
        [](auto &course) { std::cout << course.getId() << "\n"; });
}