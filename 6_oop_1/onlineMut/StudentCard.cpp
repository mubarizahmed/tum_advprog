#include "StudentCard.h"
#include "Student.h"

// TODO
StudentCard::StudentCard(const Student &owner)
    : _owner(owner) {}

void StudentCard::print() {
    std::cout << "TUM ID CARD\nName: " << _owner._name << "\nID: " << _owner._reg_no << "\n";
}