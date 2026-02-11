#include "Circle.h"
#include <cmath>  // dùng cho M_PI

Circle::Circle() : radius(0.0) {}

Circle::Circle(double r) : radius(r) {}

void Circle::setRadius(double r) {
    radius = r;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getArea() const {
    return M_PI * radius * radius;
}

double Circle::getCircumference() const {
    return 2 * M_PI * radius;
}