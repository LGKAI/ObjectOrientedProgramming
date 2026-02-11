#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "Device.h"
#include <string>
#include <vector>
using namespace std;

class Warehouse
{
private:
    std::vector<Device *> devices;

public:
    Warehouse() = default;

    void add(std::string line);
    void remove(std::string model);

    void display();
};

#endif