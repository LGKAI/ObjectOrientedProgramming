#ifndef INTEGERTOCURRENCYCONVERTER_H
#define INTEGERTOCURRENCYCONVERTER_H

#include "IValueConverter.h"
#include "Integer.h"
#include "NumberFormatInfo.h"
#include <sstream>
#include <algorithm>
#include <regex>

class IntegerToCurrencyConverter : public IValueConverter {
public:
    string convert(Object* object) override {
        auto number = dynamic_cast<Integer*>(object);
        int value = number->value();

        if (value == 0) return "0 d";

        stringstream builder;
        NumberFormatInfo info;
        int count = 0;

        while (value != 0) {
            int digit = value % 10;
            builder << digit;
            count++;

            if (count == 3 && value / 10 != 0) {
                builder << info.currencyDecimalSeparator();
                count = 0;
            }

            value /= 10;
        }

        string result = builder.str();
        reverse(result.begin(), result.end());

        string formatted = regex_replace(info.currencyPositiveFormat(), regex("n"), result);
        formatted = regex_replace(formatted, regex("\\$"), info.currencySymbol());
        return formatted;
    }

    string toString() override { return "IntegerToCurrencyConverter"; }
};

#endif