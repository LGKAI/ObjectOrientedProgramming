#ifndef HOLLOWRECTANGLECONVERTER_H_
#define HOLLOWRECTANGLECONVERTER_H_

#include <bits/stdc++.h>
#include "Rectangle.h"
using namespace std;

class HollowRectangleConverter {
private:
    string a;
public:
    HollowRectangleConverter() : a("$") {}
    HollowRectangleConverter(string _a) : a(_a) {}
    string convert(const Rectangle& r) {
        string rs = "";
        int n = r.getWid(), m = r.getHei();
        if (n >= 1) {
            for (int i = 0; i < m; ++i) rs += a;
            rs += '\n';
        }
        for (int i = 0; i < n - 2; ++i) {
            if (m >= 1) rs += a;
            for (int j = 0; j < m - 2; ++j) {
                rs += " ";
            }
            if (m >= 2) rs += a;
            rs += '\n';
        }
        if (n >= 2) {
            for (int i = 0; i < m; ++i) rs += a;
            rs += '\n';
        }
        return rs;
    }
};

#endif