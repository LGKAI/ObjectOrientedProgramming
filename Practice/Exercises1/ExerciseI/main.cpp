#include <bits/stdc++.h>
#include "StudentManager.h"
using namespace std;

int main() {
    StudentManager manager;
    Student s1("Nguyen Van A", "SV001", 20, "Hanoi", 3.65);
    Student s2("Tran Thi B", "SV002", 19, "Hai Phong", 3.85);
    Student s3("Le Van C", "SV003", 21, "Da Nang", 2.95);

    manager.addStudent(s1);
    manager.addStudent(s2);
    manager.addStudent(s3);
    manager.displayAllStudents();

    Student found = manager.findStudentByID("SV002");
    found.displayInfo();

    manager.removeStudent("SV001");
    manager.displayAllStudents();

    return 0;
}