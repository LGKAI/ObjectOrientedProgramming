#ifndef LAPTOP_H
#define LAPTOP_H

#include "Device.h"
#include <string>
using namespace std;

class Laptop : public Device
{
private:
    double warrantyFee;

public:
    Laptop(string name, string model, int year, double cost, double warrantyFee);
    string getType() const;
    double getTotalCost() const;
};

#endif