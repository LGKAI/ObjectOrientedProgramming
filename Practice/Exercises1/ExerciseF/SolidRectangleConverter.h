#ifndef SOLIDRECTANGLECONVERTER_H_
#define SOLIDRECTANGLECONVERTER_H_

#include <bits/stdc++.h>
#include "Rectangle.h"
using namespace std;

class SolidRectangleConverter {
private:
    string a;
public:
    SolidRectangleConverter() : a(".") {}
    SolidRectangleConverter(string _a) : a(_a) {}
    string convert(const Rectangle& r) {
        string rs = "";
        int n = r.getWid(), m = r.getHei();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                rs += a;
            }
            rs += '\n';
        }
        return rs;
    }
};

#endif