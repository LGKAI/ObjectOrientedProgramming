#pragma once
#include "IParsable.h"
#include "Square.h"

class SquareParser : public IParsable {
public:
    IShape* parse(string data) override {
        size_t pos = data.find('=');
        double a = stod(data.substr(pos + 1));
        return new Square(a);
    }
    string toString() override { return "SquareParser"; }
};