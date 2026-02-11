#ifndef FRACTION_H_
#define FRACTION_H_

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

class Fraction {
private:
    int num, den;

public:
    void simplify() {
        int g = gcd(num, den);
        num /= g;
        den /= g;
        if (!num) den = 1;
        else if (num * den < 0) num = -abs(num), den = abs(den);
        else num = abs(num), den = abs(den);
    }

    Fraction(int n = 0, int d = 1) {
        num = n;
        den = d;
        simplify();
    }

    Fraction operator+(const Fraction& other) const {
        int n = 1LL * num * other.den + 1LL * den * other.num;
        int d = 1LL * den * other.den;
        Fraction rs(n, d);
        rs.simplify();
        return rs; 
    }

    bool operator<(const Fraction& other) const {
        return 1LL * num * other.den < 1LL * den * other.num;
    }

    void output() const {
        Fraction temp(num, den);
        temp.simplify();
        cout << temp.num << '/' << temp.den << '\n';
    }

    friend ostream& operator<<(ostream& os, const Fraction& frac) {
        Fraction temp(frac.num, frac.den);
        temp.simplify();
        os << temp.num << '/' << temp.den;
        return os;
    }
};

#endif