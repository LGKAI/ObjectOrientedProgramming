#include <bits/stdc++.h>
#include "FractionArray.h"
using namespace std;

int main() {
    Fraction a(3, 2479);
    Fraction b(0, 2254);
    cout << "Sum of a + b: " << a + b << "\n";
    cout << "Smaller fraction: ";
    if (a < b)
        a.output();
    else
        b.output();

    FractionArray arr;
    string filename = "input.txt";
    arr.loadFromFile(filename);
    cout << "List of fractions:\n";
    arr.output();
    cout << "Sum of fractions:\n" << arr.sum() << "\n";
    cout << "Maximum fraction:\n" << arr.max() << "\n";
    cout << "Minimum fraction:\n" << arr.min() << "\n";
    arr.sortArray();
    cout << "Sorted fractions:\n";
    arr.output();

    return 0;
}