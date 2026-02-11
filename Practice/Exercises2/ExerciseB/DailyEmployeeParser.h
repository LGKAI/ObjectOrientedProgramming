#ifndef DAILYEMPLOYEEPARSER_H
#define DAILYEMPLOYEEPARSER_H

#include "IParsable.h"
#include "DailyEmployee.h"
#include <sstream>
#include <vector>

class DailyEmployeeParser : public IParsable {
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

        return new DailyEmployee(stoi(result[1]), stoi(result[3]));
    }

    string toString() override { return "DailyEmployeeParser"; }
};

#endif