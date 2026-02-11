#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction();
    Fraction(int num, int den);

    std::string to_string();

    Fraction add(Fraction other);
    Fraction subtract(Fraction other);
    Fraction multiply(Fraction other);
    Fraction divide(Fraction other);

    void simplify();

    int getNumerator();
    int getDenominator();
    void setNumerator(int num);
    void setDenominator(int den);
};

#endif