#include <bits/stdc++.h>
#include "Point3D.h"
using namespace std;

Point3D::Point3D() {
    x = y = z = 0;
}

Point3D::Point3D(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

double Point3D::distance(Point3D other) {
    double dx = x - other.x;
    double dy = y - other.y;
    double dz = z - other.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

void Point3D::move(double dx, double dy, double dz) {
    x += dx;
    y += dy;
    z += dz;
}

void Point3D::rotate() {
    double oldX = x;
    x = -y;
    y = oldX;
}

void Point3D::print() const {
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}