#ifndef STUDENTCARD_H
#define STUDENTCARD_Η

#include <iostream>
#include <string>

#include "Student.h"

class StudentCard {
    // TODO
  private:
    const Student _owner;

  public:
    StudentCard(const Student &);
    void print();
};

#endif