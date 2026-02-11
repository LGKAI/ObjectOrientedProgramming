#pragma once
#include <string>
using namespace std;

class IShape {
public:
    virtual ~IShape() = default;
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual string toString() = 0;
};