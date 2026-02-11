#pragma once
#include <string>
#include "IShape.h"

class IParsable {
public:
    virtual ~IParsable() = default;
    virtual IShape* parse(string data) = 0;
    virtual string toString() = 0;
};