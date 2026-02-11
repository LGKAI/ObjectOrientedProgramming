#include "Device.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Device::Device(string name, string model, int year, double cost)
{
    this->name = name;
    this->model = model;
    this->year = year;
    this->cost = cost;
}

string Device::getName()
{
    return name;
}

string Device::getModel()
{
    return model;
}

int Device::getYear()
{
    return year;
}

double Device::getCost()
{
    return cost;
}

void Device::display()
{
    std::cout
        << "[" << this->getType() << "] " << this->getName()
        << "(" << this->getModel() << ") - "
        << this->getYear() << " - " << std::fixed << std::setprecision(2) << this->getTotalCost() << std::endl;
}