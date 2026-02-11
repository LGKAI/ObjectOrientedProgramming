#ifndef OBJECT_H
#define OBJECT_H

#include <string>
using namespace std;

class Object {
public:
    virtual ~Object() = default;
    virtual string toString() = 0;
};

#endif