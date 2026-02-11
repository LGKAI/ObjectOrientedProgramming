#ifndef STUDENT_H_
#define STUDENT_H_

#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string id, name, email;
    Student(string a, string b, string c) : id(a), name(b), email(c) {}
};

#endif