#ifndef EMPLOYEEMANAGER_H_
#define EMPLOYEEMANAGER_H_

#include <bits/stdc++.h>
#include "Employee.h"
using namespace std;

class EmployeeManager {
private:
    std::vector<Employee> employees;

public:
    void addEmployee(const Employee& em) {
        employees.push_back(em);
    }

    void removeEmployee(const string& id) {
        for (auto i = 0; i < employees.size(); i++) {
            if (employees[i].getEmployeeID() == id) {
                employees.erase(employees.begin() + i);
            }
        }
    }

    Employee findEmployeeByID(const string& id) {
        for (auto i = 0; i < employees.size(); i++) {
            if (employees[i].getEmployeeID() == id) {
                return employees[i];
            }
        }
        return Employee();
    }

    void displayAllEmployees() {
        for (auto i = 0; i < employees.size(); i++) {
            employees[i].displayInfo();
            if (i != employees.size() - 1) {
                cout << "==============================" << endl;
            }
        }
    }
};

#endif