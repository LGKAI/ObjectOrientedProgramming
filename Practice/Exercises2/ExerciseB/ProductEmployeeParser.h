#ifndef PRODUCTEMPLOYEEPARSER_H
#define PRODUCTEMPLOYEEPARSER_H

#include "IParsable.h"
#include "ProductEmployee.h"
#include <sstream>
#include <vector>

class ProductEmployeeParser : public IParsable {
public:
    Object* parse(string data) override {
        vector<string> result;
        string temp;

        stringstream dt(data);
        while (getline(dt, temp, ',')) {
            stringstream d(temp);
            string tmp;
            while (getline(d, tmp, '=')) result.push_back(tmp);
        }

        return new ProductEmployee(stoi(result[1]), stoi(result[3]));
    }

    string toString() override { return "ProductEmployeeParser"; }
};

#endif