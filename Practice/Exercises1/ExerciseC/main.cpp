#include <bits/stdc++.h>
#include "Fraction.h"
using namespace std;

int main() {
    Fraction a(1, 2);
    Fraction b(5, 2);

    cout << "a = " << a.to_string() << endl;
    cout << "b = " << b.to_string() << endl;

    cout << "a + b = " << a.add(b).to_string() << endl;
    cout << "a - b = " << a.subtract(b).to_string() << endl;
    cout << "a * b = " << a.multiply(b).to_string() << endl;
    cout << "a / b = " << a.divide(b).to_string() << endl;

    return 0;
}