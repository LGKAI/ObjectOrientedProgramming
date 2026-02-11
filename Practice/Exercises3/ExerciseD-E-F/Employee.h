#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    double baseSalary;

public:
    Employee(string name, int id, double baseSalary);
    string getName();
    int getID();
    double getBaseSalary();
    virtual string getType() const = 0;
    virtual double getTotalSalary() const = 0;
    void display();
};

#endif