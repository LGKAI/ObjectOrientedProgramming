#include "Rectangle.h"

Rectangle::Rectangle() : HeightFigure() {}

Rectangle::Rectangle(int height, int width) : HeightFigure(height, width) {}

Rectangle::~Rectangle() {}

float Rectangle::Area() {
    return static_cast<float>(mHeight * mWidth);
}