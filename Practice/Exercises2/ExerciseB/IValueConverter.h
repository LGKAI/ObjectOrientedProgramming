#ifndef IVALUECONVERTER_H
#define IVALUECONVERTER_H

#include "Object.h"
#include <string>

class IValueConverter {
public:
    virtual ~IValueConverter() = default;
    virtual string convert(Object* object) = 0;
    virtual string toString() = 0;
};

#endif