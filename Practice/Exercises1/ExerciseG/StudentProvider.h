#ifndef STUDENTPROVIDER_H_
#define STUDENTPROVIDER_H_

#include <bits/stdc++.h>
#include "Student.h"
using namespace std;

class StudentProvider {
public:
    StudentProvider() {}
    static vector<Student> getAll() {
        ifstream inp("student.inp");
        vector<Student> rs;
        int n;
        inp >> n;
        for (int i = 1; i <= n; ++i) {
            string a, b, c;
            inp >> a;
            inp.ignore();
            getline(inp, b);
            inp >> c;
            rs.push_back(Student(a, b, c));
        }
        return rs;
    }
};

#endif