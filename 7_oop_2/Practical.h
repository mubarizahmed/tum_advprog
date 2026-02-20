#ifndef PRACTICAL_H
#define PRACTICAL_H

#include "Course.h"

class Practical : public Course {
private:
  const std::size_t _num_worksheets;

public:
  std::string type() const override;

  void describe() const override;

  Practical(std::string id, std::size_t num_worksheets);
};

#endif // PRACTICAL_H
