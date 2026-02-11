#pragma once
#include "IParsable.h"
#include "Rectangle.h"

class RectangleParser : public IParsable {
public:
    IShape* parse(string data) override {
        size_t wPos = data.find('=');
        size_t commaPos = data.find(',');
        size_t hPos = data.find('=', commaPos);

        double w = stod(data.substr(wPos + 1, commaPos - wPos - 1));
        double h = stod(data.substr(hPos + 1));

        return new Rectangle(w, h);
    }
    string toString() override { return "RectangleParser"; }
};