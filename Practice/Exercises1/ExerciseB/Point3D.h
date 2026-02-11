#ifndef POINT3D_H
#define POINT3D_H

class Point3D {
private:
    double x, y, z;

public:
    Point3D(); // khởi tạo mặc định (0, 0, 0)
    Point3D(double x, double y, double z); // khởi tạo với 3 toạ độ cho trước

    double distance(Point3D other); // tính khoảng cách đến điểm khác
    void move(double dx, double dy, double dz); // di chuyển theo vector
    void rotate(); // quay 90 độ theo chiều dương quanh trục Oz (x -> -y, y -> x)

    void print() const; // in ra để test (không submit codeforces)
};

#endif