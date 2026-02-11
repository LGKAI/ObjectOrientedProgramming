#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "HeightFigure.h"

class Triangle : public HeightFigure {
public:
    Triangle();
    Triangle(int height, int base);
    ~Triangle();
    float Area() override;
};

#endif