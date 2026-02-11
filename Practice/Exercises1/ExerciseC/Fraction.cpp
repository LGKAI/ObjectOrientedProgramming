#include <bits/stdc++.h>
#include "Fraction.h"
using namespace std;

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int num, int den) {
    numerator = num;
    denominator = den;
}

std::string Fraction::to_string() {
    string sn = "", sd = "";
    int tn = abs(numerator), td = abs(denominator);
    while (tn) sn += (char)(tn % 10 + '0'), tn /= 10;
    while (td) sd += (char)(td % 10 + '0'), td /= 10;
    reverse(sn.begin(), sn.end());
    reverse(sd.begin(), sd.end());
    if (numerator == 0) sn = "0";
    else if (numerator < 0) sn = '-' + sn;
    if (denominator < 0) sd = '-' + sd;
    return sn + '/' + sd;
}

Fraction Fraction::add(Fraction other) {
    int num = numerator * other.getDenominator() + other.getNumerator() * denominator;
    int den = denominator * other.getDenominator();
    Fraction res(num, den);
    res.simplify();
    return res;
}

Fraction Fraction::subtract(Fraction other) {
    int num = numerator * other.getDenominator() - other.getNumerator() * denominator;
    int den = denominator * other.getDenominator();
    Fraction res(num, den);
    res.simplify();
    return res;
}

Fraction Fraction::multiply(Fraction other) {
    int num = numerator * other.getNumerator();
    int den = denominator * other.getDenominator();
    Fraction res(num, den);
    res.simplify();
    return res;
}

Fraction Fraction::divide(Fraction other) {
    int num = numerator * other.getDenominator();
    int den = denominator * other.getNumerator();
    Fraction res(num, den);
    res.simplify();
    return res;
}

void Fraction::simplify() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    if (numerator == 0) {
        denominator = 1;
        return;
    }
    int g = __gcd(abs(numerator), abs(denominator));
    numerator /= g;
    denominator /= g;
}

int Fraction::getNumerator() { return numerator; }
int Fraction::getDenominator() { return denominator; }
void Fraction::setNumerator(int num) { numerator = num; }
void Fraction::setDenominator(int den) { denominator = den; }