#ifndef SQUARE_H_
#define SQUARE_H_

#include "Rectangle.h"

class Square : public Rectangle {
public:
    Square();
    Square(int);
    ~Square();
    // Không cần override hàm Area (tính giống nhau thì sửa làm mẹ chi)
};

#endif