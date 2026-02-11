#include <iostream>
#include "Circle.h"
using namespace std;

int main() {
    Circle c1(5.0);  // Tạo một hình tròn bán kính 5.0

    std::cout << "Radius: " << c1.getRadius() << std::endl;
    std::cout << "Area: " << c1.getArea() << std::endl;
    std::cout << "Circumference: " << c1.getCircumference() << std::endl;

    return 0;
}