#ifndef COURSE_H
#define COURSE_H

#include <string>

// TODO
enum class CourseType { Lecture, Seminar, Practical };

class Course {
    // TODO
  private:
    const std::string _id;
    const CourseType _type;

  public:
    Course(std::string, CourseType);
    std::string getId();
};

#endif // COURSE_Η