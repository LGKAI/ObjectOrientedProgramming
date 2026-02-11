#ifndef PARSERFACTORY_H
#define PARSERFACTORY_H

#include <map>
#include <string>
#include <typeinfo>
#include "IParsable.h"

class ParserFactory {
private:
    map<string, IParsable*> _container;

public:
    void registerWith(IParsable* parser) {
        string key;
        string name = typeid(*parser).name();

        if (name.find("DailyEmployeeParser") != string::npos)
            key = "DailyEmployee";
        else if (name.find("ProductEmployeeParser") != string::npos)
            key = "ProductEmployee";
        else if (name.find("ManagerParser") != string::npos)
            key = "Manager";

        _container[key] = parser;
    }

    IParsable* create(string type) {
        if (_container.count(type))
            return _container[type];
        return nullptr;
    }
};

#endif