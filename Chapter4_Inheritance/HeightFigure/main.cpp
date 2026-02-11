#include <bits/stdc++.h>
#include "HeightFigure.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
using namespace std;

int main() {
/*  
    Rectangle rect(10, 6);
    cout << "Area of Rectangle = " << rect.Area() << endl;

    Square sq(5);
    cout << "Area of Square = " << sq.Area() << endl;

    Triangle tri(8, 4);
    cout << "Area of Triangle = " << tri.Area() << endl;

    // Dùng đa hình: con trỏ lớp cha trỏ đến lớp con
    HeightFigure* figure;
    // Không dùng được HeightFigure figure vì lúc này HeightFigure là abstract class

    figure = new Rectangle(7, 3);
    cout << "Area via polymorphism (Rectangle): " << figure->Area() << endl;
    delete figure;

    figure = new Square(6);
    cout << "Area via polymorphism (Square): " << figure->Area() << endl;
    delete figure;

    figure = new Triangle(9, 5);
    cout << "Area via polymorphism (Triangle): " << figure->Area() << endl;
    delete figure;
*/

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<HeightFigure*> v;
    for (int i = 0; i < n; ++i) {
        char type;
        cin >> type;
        if (type == 'R') {
            int w, h;
            cin >> w >> h;
            v.push_back(new Rectangle(w, h));
        }
        else if (type == 'S') {
            int s;
            cin >> s;
            v.push_back(new Square(s));
        }
        else {
            int w, h;
            cin >> w >> h;
            v.push_back(new Triangle(w, h));
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << v[i]->Area() << "\n";
    }

    return 0;
}

// g++ main.cpp HeightFigure.cpp Rectangle.cpp Square.cpp Triangle.cpp -o main.exe