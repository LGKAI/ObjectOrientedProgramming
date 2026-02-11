#ifndef ENGINEER_H
#define ENGINEER_H

#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;

class Engineer : public Employee {
protected:
    int overtimeHours;
    double overtimeRate;

public:
    Engineer(string name, int id, double baseSalary, int overtimeHours, double overtimeRate);
    virtual string getType() const;
    virtual double getTotalSalary() const;
};

#endif