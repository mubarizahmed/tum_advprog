#include "Course.h"
#include <iostream>

Course::Course(std::string id, CourseType type)
    : _id{id}, _type{type} {}

std::string Course::getId() {
    return _id;
}