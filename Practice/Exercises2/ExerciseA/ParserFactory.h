#pragma once
#include <map>
#include <string>
#include "IParsable.h"
#include "SquareParser.h"
#include "CircleParser.h"
#include "RectangleParser.h"

class ParserFactory {
private:
    map<string, IParsable*> parsers;
public:
    ParserFactory() {
        parsers["Square"] = new SquareParser();
        parsers["Circle"] = new CircleParser();
        parsers["Rectangle"] = new RectangleParser();
    }

    ~ParserFactory() {
        for (auto& p : parsers)
            delete p.second;
    }

    IParsable* create(string type) {
        return parsers[type];
    }
};