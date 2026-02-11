#include <bits/stdc++.h>
#include "PointArray.h"
using namespace std;

int main() {
    Point a(3, 2479);
    Point b(0, 2254);
    a.output();
    b.output();
    cout << a.distanceTo(b);

    PointArray v;
    string filename = "input.txt";
    v.loadFromFile(filename);
    v.output();
    v.findFarthestPoint(a).output();
    
    return 0;
}