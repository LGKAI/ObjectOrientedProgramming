#include "Office.h"
#include <iostream>
#include <string>
using namespace std;

Office::Office(string name, int id, double baseSalary, double allowance) : Employee(name, id, baseSalary), allowance(allowance) {};

string Office::getType() const {
    return "Office";
}

double Office::getTotalSalary() const {
    return baseSalary + allowance;
}