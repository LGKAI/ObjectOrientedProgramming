#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <bits/stdc++.h>
#include "Student.h"
using namespace std;

class StudentManager {
private:
    std::vector<Student> students;

public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void removeStudent(const std::string& studentID) {
        for (auto i = 0; i < students.size(); i++){
            if (students[i].getStudentID() == studentID){
                students.erase(students.begin() + i);
            }
        }
    }

    Student findStudentByID(const std::string& studentID) {
        for (auto i = 0; i < students.size(); i++){
            if (students[i].getStudentID() == studentID){
                return students[i];
            }
        }
        return Student();
    }

    void displayAllStudents() {
        for (auto i = 0; i < students.size(); i++){
            students[i].displayInfo();
            if (i != students.size() - 1){
                cout << "--------------------" << endl;
            }
        }
    }
};

#endif