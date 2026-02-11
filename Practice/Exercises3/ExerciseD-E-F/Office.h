#ifndef OFFICE_H
#define OFFICE_H

#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;

class Office : public Employee {
protected:
    double allowance;

public:
    Office(string name, int id, double baseSalary, double alowance);
    virtual string getType() const;
    virtual double getTotalSalary() const;
};

#endif