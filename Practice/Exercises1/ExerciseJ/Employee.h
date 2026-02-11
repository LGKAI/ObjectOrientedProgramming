#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <bits/stdc++.h>
using namespace std;

class Employee {
private:
    string fullName, employeeID, department;
    int age;
    float salary;

public:
    Employee() {
        fullName = "";
        employeeID = "";
        department = "";
        age = 0;
        salary = 0.00;
    }

    Employee(string name, string id, int a, string de, float sa) {
        fullName = name;
        employeeID = id;
        age = a;
        department = de;
        salary = sa;
    }

    void displayInfo() {
        cout << "Name: " << fullName << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Age: " << age << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << fixed << setprecision(2) << salary << endl;
    }

    string getFullName() {
        return fullName;
    }

    void setFullName(string name) {
        fullName = name;
    }

    string getEmployeeID() {
        return employeeID;
    }

    void setEmployeeID(string id) {
        employeeID = id;
    }

    int getAge() {
        return age;
    }

    void setAge(int a) {
        age = a;
    }

    string getDepartment() {
        return department;
    }

    void setDepartment(string de) {
        department = de;
    }

    float getSalary() {
        return salary;
    }

    void setSalary(float sa) {
        salary = sa;
    }
};

#endif