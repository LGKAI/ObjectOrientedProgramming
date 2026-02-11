#include "Engineer.h"
#include <iostream>
#include <string>
using namespace std;

Engineer::Engineer(string name, int id, double baseSalary, int overtimeHours, double overtimeRate) : Employee(name, id, baseSalary),
    overtimeHours(overtimeHours), overtimeRate(overtimeRate) {};

string Engineer::getType() const {
    return "Engineer";
}

double Engineer::getTotalSalary() const {
    return baseSalary + overtimeHours * overtimeRate;
}