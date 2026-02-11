#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include "Device.h"
#include <string>
using namespace std;

class Smartphone : public Device
{
private:
    double importTax;

public:
    Smartphone(string name, string model, int year, double cost, double importTax);
    string getType() const;
    double getTotalCost() const;
};

#endif