#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Object.h"

class Employee : public Object {
public:
    virtual ~Employee() = default;
    virtual int salary() = 0;
    virtual string toString() = 0;
};

#endif