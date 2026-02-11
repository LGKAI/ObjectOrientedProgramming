#ifndef NUMBERFORMATINFO_H
#define NUMBERFORMATINFO_H

#include "Object.h"

class NumberFormatInfo : public Object {
private:
    string _currencyDecimalSeparator = ".";
    string _currencySymbol = "d";
    int _currencyPositive = 3;
    string _currencyPositiveFormat = "n $";

public:
    string currencyDecimalSeparator() { return _currencyDecimalSeparator; }
    string currencySymbol() { return _currencySymbol; }
    int currencyPositive() { return _currencyPositive; }
    string currencyPositiveFormat() { return _currencyPositiveFormat; }
    string toString() override { return "NumberFormatInfo"; }
};

#endif