#include <iostream>

int gcd_recursive(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd_recursive(b, a % b);
    }
}

int gcd_iterative(int a, int b) {
    while (b != 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

int gcd_iterative_swap(int a, int b) {
    while (b != 0) {
        std::swap(a, b);
        b = b % a;
    }
    return a;
}

int main() {
    int a = 60;
    int b = 70;

    std::cout << "a: " << a << " b: " << b << std::endl;

    std::cout << "Recursive: " << gcd_recursive(a, b) << "\n";
    std::cout << "Iterative: " << gcd_iterative(a, b) << "\n";
    std::cout << "Iterative swap: " << gcd_iterative_swap(a, b) << "\n";

    // in loop

    // generate random

    // import existing

    // assert

    return 0;
}