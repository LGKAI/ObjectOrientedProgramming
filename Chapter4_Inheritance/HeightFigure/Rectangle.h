#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "HeightFigure.h"

class Rectangle : public HeightFigure {
public:
    Rectangle();
    Rectangle(int, int);
    ~Rectangle(); // virtual ~Rectangle() cũng được
    float Area() override; // virtual float Area() cũng được (nên vậy)
};

#endif