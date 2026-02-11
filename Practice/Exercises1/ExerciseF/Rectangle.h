#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <bits/stdc++.h>
using namespace std;

string intToString(int x) {
    if (!x) return "0";
    string rs = "";
    while (x) rs += (char)(x % 10 + '0'), x /= 10;
    reverse(rs.begin(), rs.end());
    return rs;
}

class Rectangle {
private:
    int wid, hei;
    
public:
    Rectangle() {}
    Rectangle(int w, int h) : wid(w), hei(h) {}
    string toString() {
        return "Rectangle Width=" + intToString(wid) + ", Height=" + intToString(hei);
    }
    int getWid() const { return wid; }
    int getHei() const { return hei; }
};

#endif