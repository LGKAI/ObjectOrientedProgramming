#include <bits/stdc++.h>
#include "EmployeeManager.h"
using namespace std;

int main() {
    EmployeeManager manager;
    Employee e1("Nguyen Van A", "E001", 30, "HR", 1500.5);
    Employee e2("Tran Thi B", "E002", 28, "Marketing", 2000.0);
    Employee e3("Le Van C", "E003", 35, "IT", 2500.75);

    manager.addEmployee(e1);
    manager.addEmployee(e2);
    manager.addEmployee(e3);
    manager.displayAllEmployees();

    Employee found = manager.findEmployeeByID("E002");
    found.displayInfo();

    manager.removeEmployee("E001");
    manager.displayAllEmployees();

    return 0;
}