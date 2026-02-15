#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"

#include <string>
#include <vector>

class Student {
    // TODO
  private:
    std::vector<Course> _registeredCourses;
    std::string _name;
    const std::string _reg_no;

    friend class StudentCard;

  public:
    Student(std::string, std::string);

    bool register_for(const Course &);
    void list_courses();
};

#endif // STUDENT_H