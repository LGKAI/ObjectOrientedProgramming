#ifndef HEIGHTFIGURE_H_
#define HEIGHTFIGURE_H_

class HeightFigure {
protected:
    int mHeight;
    int mWidth;

public:
    HeightFigure();
    HeightFigure(int, int);
    virtual ~HeightFigure();
    // Hàm huỷ cũng phải là hàm ảo (lí do tương tự như hàm Area) -> Hàm huỷ ảo
    virtual float Area() = 0;
    // Hàm ảo biến HeightFigure thành abstract class -> Hàm thuần ảo
};

#endif