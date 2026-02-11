#ifndef DEVICE_H
#define DEVICE_H

#include <string>
using namespace std;

class Device
{
protected:
    string name;
    string model;
    int year;
    double cost;

public:
    Device(string name, string model, int year, double cost);
    string getName();
    string getModel();
    int getYear();
    double getCost();

    virtual string getType() const = 0;
    virtual double getTotalCost() const = 0;
    void display();
};

#endif