#ifndef FRACTION_H_
#define FRACTION_H_

class Fraction {
private:
    int numerator;
    int denominator;
    
public:
    Fraction();
    Fraction(int, int);
    Fraction(int);
    virtual ~Fraction();
    
    void input();
    void output();
    void setNumerator(int);
    void setDenominator(int);
    int getNumerator();
    int getDenominator();
    void simplify();

    Fraction plus(Fraction);
    Fraction subtract(Fraction);
    Fraction multiply(Fraction);
    Fraction divide(Fraction);
    Fraction inverse();
};

#endif