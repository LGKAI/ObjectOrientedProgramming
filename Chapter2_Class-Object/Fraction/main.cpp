#include <iostream>
#include "Fraction.h"
using namespace std;

int main() {
    Fraction a;
    Fraction b;
    a.input();
    b.input();
    Fraction c = a.plus(b);
    c.output();
    return 0;
}

// g++ main.cpp Fraction.cpp -o main.exe