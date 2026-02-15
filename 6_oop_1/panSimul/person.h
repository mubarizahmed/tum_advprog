#ifndef __PERSON_H_
#define __PERSON_H_
#include <array>
#include <random>
#include <string>

enum class Status {
    Healthy,
    Infectious,
};

class Person {
  private:
    Status status = Status::Healthy;
    // location is two dimensional
    std::array<double, 2> curr_location = {0.0, 0.0};
    // Each person should get a unique id
    // Sometimes we name private member variables starting with
    // an underscore. It is a common convention, but there are
    // also people that disagree with it and specific names can
    // make the compiler complain. Just pick one convention and
    // be consistent.
    const unsigned _id;

    // static class member: shared across all class objects
    // inline: so we can initialize it here, see worksheet.
    static inline unsigned counter = 0;

  public:
    Person(std::array<double, 2>);

    std::array<double, 2> get_location() const;

    void advance();

    unsigned get_id() const;

    Person(const Person &other);
    Person &operator=(const Person &other);
};

#endif // __PERSON_H_
