#include <bits/stdc++.h>
#include "Point3D.h"
using namespace std;

int main() {
    Point3D M(1, 2, 3);
    Point3D N(4, -5, 0);
    
    cout << "Distance between M and N: " << M.distance(N) << endl;

    M.move(1, -1, 2);
    cout << "M after moving: ";
    M.print();

    N.rotate();
    cout << "N after rotating: ";
    N.print();

    return 0;
}