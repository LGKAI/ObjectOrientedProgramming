#include <bits/stdc++.h>
#include "RectangleProvider.h"
#include "SolidRectangleConverter.h"
#include "HollowRectangleConverter.h"
using namespace std;

int main() {
    auto rectangles = RectangleProvider::getAll();
    SolidRectangleConverter solid(".");
	HollowRectangleConverter hollow("$");

    for (auto rectangle : rectangles) {
        std::cout << rectangle.toString() << "\n";
        std::cout << solid.convert(rectangle) << "\n";
        std::cout << hollow.convert(rectangle) << "\n";
        std::cout << "\n";
    }
    
    return 0;
}