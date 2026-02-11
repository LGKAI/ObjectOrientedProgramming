#include <iostream>
#include "Fraction.h"
using namespace std;

int gcd(int a, int b) {
    // a > b
    if (!b) return a;
    return gcd(b, a % b);
}

Fraction::Fraction(): numerator(0), denominator(1) {}

Fraction::Fraction(int a, int b): numerator(a), denominator(b ? b : 1) {}

Fraction::Fraction(int a): numerator(a), denominator(1) {}

Fraction::~Fraction() {}

void Fraction::input() {
    cout << "Enter numerator: ";
    cin >> numerator;
    bool firstTime = true;
    do {
        if (firstTime) cout << "Enter denominator: ";
        else cout << "Error: Denominator can not be 0!\nRe-enter denominator: ";
        cin >> denominator;
        firstTime = false;
    } while (!denominator);
}

void Fraction::output() {
    Fraction::simplify();
    if (numerator * denominator >= 0) {
        numerator = abs(numerator);
        denominator = abs(denominator);
    }
    else {
        numerator = -abs(numerator);
        denominator = abs(denominator);
    }
    cout << "Fraction: " << numerator << "/" << denominator << "\n";
}

void Fraction::setNumerator(int a) {
    numerator = a;
    // this->numerator = a;
}

// void Fraction::setNumerator(int numerator) {
//     this->numerator = numerator; // bắt buộc dùng this để phân biệt 2 biến trùng tên
// }

void Fraction::setDenominator(int a) {
    if (!a) cout << "Error: Denominator can not be 0!\n";
    else denominator = a;
}

int Fraction::getNumerator() {
    return numerator;
}

int Fraction::getDenominator() {
    return denominator;
}

void Fraction::simplify() {
    int g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
}

Fraction Fraction::plus(Fraction other) {
    int nn = numerator * other.denominator + other.numerator * denominator;
    int nd = denominator * other.denominator;
    Fraction rs(nn, nd);
    return rs;
}

Fraction Fraction::subtract(Fraction other) {
    int nn = numerator * other.denominator - other.numerator * denominator;
    int nd = denominator * other.denominator;
    Fraction rs(nn, nd);
    return rs;
}

Fraction Fraction::multiply(Fraction other) {
    int nn = numerator * other.numerator;
    int nd = denominator * other.denominator;
    Fraction rs(nn, nd);
    return rs;
}

Fraction Fraction::divide(Fraction other) {
    int nn = numerator * other.denominator;
    int nd = denominator * other.numerator;
    Fraction rs(nn, nd);
    return rs;
}

Fraction Fraction::inverse() {
    Fraction rs;
    rs.setDenominator(numerator);
    rs.setNumerator(denominator);
    return rs;
}