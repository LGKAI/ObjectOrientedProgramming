#ifndef INTEGER_H
#define INTEGER_H

#include "Object.h"

class Integer : public Object {
private:
    int _value;
public:
    Integer(int value = 0) : _value(value) {}
    int value() { return _value; }
    string toString() override { return "Integer"; }
};

#endif