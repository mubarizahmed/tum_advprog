#ifndef LECTURE_H
#define LECTURE_H

#include "Course.h"

class Lecture : public Course {
private:
  std::string _exam_date;

public:
  std::string type() const override;

  void describe() const override;

  Lecture(std::string id, std::string exam_date);
};

#endif // LECTURE_H
