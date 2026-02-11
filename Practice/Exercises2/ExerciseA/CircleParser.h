#pragma once
#include "IParsable.h"
#include "Circle.h"

class CircleParser : public IParsable {
public:
    IShape* parse(string data) override {
        size_t pos = data.find('=');
        double r = stod(data.substr(pos + 1));
        return new Circle(r);
    }
    string toString() override { return "CircleParser"; }
};