#include "Employee.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Employee::Employee(string name, int id, double baseSalary) {
    this->name = name;
    this->id = id;
    this->baseSalary = baseSalary;
}

string Employee::getName() {
    return name;
}

int Employee::getID() {
    return id;
}

double Employee::getBaseSalary() {
    return baseSalary;
}

void Employee::display() {
    cout << "[" << getType() << "] " << getName() << " - " << getID() << " - ";
    cout << setprecision(2) << fixed << getTotalSalary() << '\n';
}