#pragma once
#include "IShape.h"
#include <cmath>
#define PI acos(-1)

class Circle : public IShape {
private:
    double r;
public:
    Circle(double r = 0) : r(r) {}

    double area() override { return PI * r * r; }
    double perimeter() override { return 2 * PI * r; }
    string toString() override { return "Circle"; }
};