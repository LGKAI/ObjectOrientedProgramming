#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee {
private:
    int _employeeCount, _paymentPerEmployee, _baseSalary;
public:
    Manager(int a, int b, int c)
        : _employeeCount(a), _paymentPerEmployee(b), _baseSalary(c) {}

    int salary() override { return _employeeCount * _paymentPerEmployee + _baseSalary; }
    string toString() override { return "Manager"; }
};

#endif