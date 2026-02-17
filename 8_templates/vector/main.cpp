#include "Vec.h"
#include <iostream>

int main() {
    Vec<double> myvec;

    myvec.push(2.0);
    myvec.push(3.0);

    // Test TODO 1
    if (myvec.size() != 2 and myvec.capacity() != 2) {
        std::cerr << "Failed Test 1a: \t Are you sure your push() function has been implemented correctly?\n";
    } else {
        std::cout << "Test 1 OK\n";
    }

    // Test TODO 2
    myvec.push(5.0);
    if (myvec[0] != 2.0 and myvec[1] != 3.0 and myvec[2] != 5.0) {
        std::cerr << "Failed Test 2: \t You may want to check your operator[] implementation.\n";
    } else if (myvec.capacity() != 4) {
        std::cerr << "Failed Test 1b: \t Vec does not seem to grow by factor of 2 on reallocation\n";
    } else {
        std::cout << "Test 2 OK\n";
    }

    // Test TODO 3
    /**
    int count = 0;
    for (const auto &elem : myvec)
    {
        std::cout << elem << std::endl;
        count++;
    }
    if(count != 3)
    {
        std::cerr << "Failed Test 3: \t Printed more than size() elements. Something could be wrong with the end()
    method\n";
    }
    else{
        std::cout << "Test 3 OK\n";
    }
    */
}
