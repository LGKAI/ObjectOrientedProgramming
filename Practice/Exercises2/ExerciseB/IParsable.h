#ifndef IPARSABLE_H
#define IPARSABLE_H

#include <string>
#include "Object.h"
using namespace std;

class IParsable {
public:
    virtual ~IParsable() = default;
    virtual Object* parse(string data) = 0;
    virtual string toString() = 0;
};

#endif