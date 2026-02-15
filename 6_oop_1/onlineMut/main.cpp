#include <iostream>

#include "Course.h"
#include "Student.h"
#include "StudentCard.h"

int main() {
  Student Eve("Eve", "12345");

  StudentCard eves_card(Eve);
  eves_card.print();

  const Course AdvProg("IN1503", CourseType::Lecture);
  Eve.register_for(AdvProg);
  Eve.list_courses();
}