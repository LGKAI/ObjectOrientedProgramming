#ifndef MANAGERPARSER_H
#define MANAGERPARSER_H

#include "IParsable.h"
#include "Manager.h"
#include <sstream>
#include <vector>

class ManagerParser : public IParsable {
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

        return new Manager(stoi(result[1]), stoi(result[3]), stoi(result[5]));
    }

    string toString() override { return "ManagerParser"; }
};

#endif