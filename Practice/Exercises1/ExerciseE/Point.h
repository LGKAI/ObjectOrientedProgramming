#ifndef POINT_H_
#define POINT_H_

#include <bits/stdc++.h>
using namespace std;

class Point {
private:
    double x, y;

public:
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    double distanceTo(const Point& other) const {
        double dx = x - other.x, dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
    
    void output() const {
        cout << setprecision(2) << fixed << '(' << x << ',' << y << ")\n";
    }
};

#endif