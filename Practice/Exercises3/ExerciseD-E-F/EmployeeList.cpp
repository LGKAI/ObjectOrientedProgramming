#include "Employee.h"
#include "EmployeeList.h"
#include "Parser.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

EmployeeList::EmployeeList() {
    employees.clear();
}

void EmployeeList::add(string line) {
    employees.push_back(Parser::parse(line));
}

void EmployeeList::remove(int id) {
    vector<Employee*> temp;
    for (Employee* employee : employees) if (employee->getID() != id) temp.push_back(employee);
    employees = temp;
}

void EmployeeList::display() {
    for (Employee* employee : employees) employee->display();
}