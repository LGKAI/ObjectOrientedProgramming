#pragma once
#include "IShape.h"

class Rectangle : public IShape {
private:
    double w, h;
public:
    Rectangle(double w = 0, double h = 0) : w(w), h(h) {}

    double area() override { return w * h; }
    double perimeter() override { return 2 * (w + h); }
    string toString() override { return "Rectangle"; }
};