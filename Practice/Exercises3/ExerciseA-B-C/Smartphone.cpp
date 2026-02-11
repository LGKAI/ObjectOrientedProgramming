#include "Smartphone.h"
#include <iostream>
#include <string>
using namespace std;

Smartphone::Smartphone(string name, string model, int year, double cost, double importTax) : Device(name, model, year, cost), importTax(importTax) {};

string Smartphone::getType() const
{
    return "Smartphone";
}

double Smartphone::getTotalCost() const
{
    double total = this->cost + this->importTax;
    return total;
}