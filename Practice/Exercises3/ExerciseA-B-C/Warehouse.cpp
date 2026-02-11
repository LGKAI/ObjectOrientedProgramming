#include "Warehouse.h"
#include "Device.h"
#include "Laptop.h"
#include "Smartphone.h"
#include <string>
#include <vector>
using namespace std;

bool compare(std::string model1, std::string model2)
{
    if (model1.length() != model2.length())
    {
        return false;
    }

    for (int i = 0; i < model1.length(); i++)
    {
        if (tolower(model1[i]) != tolower(model2[i]))
        {
            return false;
        }
    };
    return true;
}

void Warehouse::add(std::string line)
{
    std::vector<std::string> tokens;
    std::string token;

    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            tokens.push_back(token);
            token.clear();
        }
        else
        {
            token.push_back(line[i]);
        }
    }
    tokens.push_back(token);
    token.clear();

    std::string type = tokens[0];
    std::string name = tokens[1];
    std::string model = tokens[2];
    int year = stoi(tokens[3]);
    double cost = stod(tokens[4]);
    double special = stod(tokens[5]);

    if (type == "Laptop")
    {
        this->devices.push_back(new Laptop(name, model, year, cost, special));
    }
    else if (type == "Smartphone")
    {
        this->devices.push_back(new Smartphone(name, model, year, cost, special));
    }
}

void Warehouse::remove(std::string model)
{
    std::vector<int> duplicate_index;

    for (int i = 0; i < this->devices.size(); i++)
    {
        Device *cur_device = this->devices[i];
        if (compare(model, cur_device->getModel()))
        {
            duplicate_index.push_back(i);
        }
    }

    for (int i = duplicate_index.size() - 1; i >= 0; i--)
    {
        this->devices.erase(this->devices.begin() + duplicate_index[i]);
    }

    return;
}

void Warehouse::display()
{
    for (Device *device : devices)
    {
        device->display();
    }
    return;
}