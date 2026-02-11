#include "Laptop.h"
#include "Device.h"
#include <iostream>
#include <string>
using namespace std;

Laptop::Laptop(string name, string model, int year, double cost, double warrantyFee) : Device(name, model, year, cost), warrantyFee(warrantyFee) {};

string Laptop::getType() const
{
    return "Laptop";
}

double Laptop::getTotalCost() const
{
    double total = this->cost + this->warrantyFee;
    return total;
}