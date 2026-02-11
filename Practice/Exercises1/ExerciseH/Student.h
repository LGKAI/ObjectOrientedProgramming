#ifndef STUDENT_H
#define STUDENT_H

#include <bits/stdc++.h>
using namespace std;

class Student {
private:
    string fullName;
    string studentID;
    int age;
    string address;
    float gpa;

public:
    Student() {
        fullName = "";
        studentID = "";
        age = 0;
        address = "";
        gpa = 0.0;
    }

    Student(string name, string id, int age, string address, float gpa) {
        this->fullName = name;
        this->studentID = id;
        this->age = age;
        this->address = address;
        this->gpa = gpa;
    }

    void displayInfo() {
        cout << "Name: " << fullName << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
        cout << "GPA: " << fixed;
        cout.precision(3);
        cout << gpa << endl;
    }

    string getFullName() { return fullName; }
    string getStudentID() { return studentID; }
    int getAge() { return age; }
    string getAddress() { return address; }
    float getGPA() { return gpa; }

    void setFullName(string name) { fullName = name; }
    void setStudentID(string id) { studentID = id; }
    void setAge(int age) { this->age = age; }
    void setAddress(string address) { this->address = address; }
    void setGPA(float gpa) { this->gpa = gpa; }
};

#endif