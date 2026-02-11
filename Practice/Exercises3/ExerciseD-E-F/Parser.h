#ifndef PARSER_H
#define PARSER_H

#include "Employee.h"
#include "Office.h"
#include "Engineer.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Parser {
public:
    static Employee* parse(string& line) {
        vector<string> s;
        string cur = "";
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == ',') {
                s.push_back(cur);
                cur = "";
            }
            else cur += line[i];
        }
        s.push_back(cur);
        string name = s[1];
        int id = stoi(s[2]);
        double baseSalary = stod(s[3]);
        if (s[0] == "Office") {
            double allowance = stod(s[4]);
            return new Office(name, id, baseSalary, allowance);
        }
        else {
            int overtimeHours = stoi(s[4]);
            double overtimeRate = stod(s[5]);
            return new Engineer(name, id, baseSalary, overtimeHours, overtimeRate);
        }
    }
};

#endif