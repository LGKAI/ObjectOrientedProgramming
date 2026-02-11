#ifndef FRACTIONARRAY_H_
#define FRACTIONARRAY_H_

#include <bits/stdc++.h>
#include "Fraction.h"
using namespace std;

class FractionArray {
private:
    vector<Fraction> v;

public:
    FractionArray() {
        v.clear();
    }

    void loadFromFile(const string& filename) {
        ifstream inp(filename);
        int num, den;
        while (inp >> num >> den) v.push_back(Fraction(num, den));
        inp.close();
    }

    Fraction sum() const {
        Fraction rs;
        for (const Fraction& i : v) rs = rs + i;
        return rs;
    }

    Fraction max() const {
        Fraction rs = v[0];
        for (const Fraction& i : v) if (rs < i) rs = i;
        return rs;
    }

    Fraction min() const {
        Fraction rs = v[0];
        for (const Fraction& i : v) if (i < rs) rs = i;
        return rs;
    }

    void sortArray() {
        sort(v.begin(), v.end());
    }

    void output() const {
        for (const Fraction& i : v) i.output();
    }
};

#endif