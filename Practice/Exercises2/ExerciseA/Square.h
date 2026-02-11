#pragma once
#include "IShape.h"

class Square : public IShape {
private:
    double a;
public:
    Square(double a = 0) : a(a) {}

    double area() override { return a * a; }
    double perimeter() override { return 4 * a; }
    string toString() override { return "Square"; }
};