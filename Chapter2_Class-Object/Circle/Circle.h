#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
    double radius;

public:
    Circle();                        // Constructor mặc định
    Circle(double r);                // Constructor có tham số

    void setRadius(double r);        // Thiết lập bán kính
    double getRadius() const;        // Lấy bán kính

    double getArea() const;          // Tính diện tích
    double getCircumference() const; // Tính chu vi
};

#endif