#ifndef POINTARRAY_H_
#define POINTARRAY_H_

#include <bits/stdc++.h>
#include "Point.h"
using namespace std;

class PointArray {
private:
    vector<Point> v;

public:
    PointArray() {
        v.clear();
    }

    void loadFromFile(const string& filename) {
        ifstream inp(filename);
        double x, y;
        while (inp >> x >> y) v.push_back(Point(x, y));
        inp.close();
    }

    Point findFarthestPoint(const Point& P) const {
        double maxDist = -1;
        Point rs;
        for (const Point& i : v) if (i.distanceTo(P) > maxDist) {
            maxDist = i.distanceTo(P);
            rs = i;
        }
        return rs;
    }
    
    void output() const {
        for (const Point& i : v) i.output();
    }
};

#endif