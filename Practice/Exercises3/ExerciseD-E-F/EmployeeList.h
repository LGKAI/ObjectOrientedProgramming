#ifndef EMPLOYEELIST_H
#define EMPLOYEELIST_H

#include "Employee.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class EmployeeList {
private:
    vector<Employee*> employees;

public:
    EmployeeList();
    void add(string line);
    void remove(int id);
    void display();
};

#endif