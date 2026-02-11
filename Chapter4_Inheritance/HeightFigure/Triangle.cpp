#include "Triangle.h"

Triangle::Triangle() : HeightFigure(0, 0) {}

Triangle::Triangle(int height, int base) : HeightFigure(height, base) {}

Triangle::~Triangle() {}

float Triangle::Area() {
    return 0.5f * mHeight * mWidth;
}