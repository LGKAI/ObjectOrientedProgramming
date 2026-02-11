#ifndef RECTANGLEPROVIDER_H_
#define RECTANGLEPROVIDER_H_

#include <bits/stdc++.h>
#include "Rectangle.h"
using namespace std;

class RectangleProvider {
public:
    RectangleProvider() {}
    static vector<Rectangle> getAll() {
        vector<Rectangle> rs;
        ifstream inp("rectangle.inp");
        int n;
        inp >> n;
        for (int i = 1; i <= n; i++) {
            int w, h;
            inp >> w >> h;
            rs.push_back(Rectangle(w, h));
        }
        inp.close();
        return rs;
    }
};

#endif