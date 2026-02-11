#ifndef STUDENTTOTABLECONVERTER_H_
#define STUDENTTOTABLECONVERTER_H_

#include <bits/stdc++.h>
#include "Student.h"
using namespace std;

class StudentsToTableConverter {
private:
    vector<string> headers;
    vector<int> col_size;

public:
    StudentsToTableConverter() {
        headers.clear();
        col_size.clear();
    }

    StudentsToTableConverter(vector<string>& a, vector<int>& b) {
        headers = {a.begin(), a.end()};
        col_size = {b.begin(), b.end()};
    }

    string intToString(int x) const {
        string rs = "";
        while (x) rs += (char)('0' + x % 10), x /= 10;
        reverse(rs.begin(), rs.end());
        return rs; 
    }

    string convert(const vector<Student>& a) const {
        string rs = "";
        rs += '|';
        for (int i = 0; i < headers.size(); ++i) {
            string s = headers[i];
            for (int j = 0; j < col_size[i] - s.size(); ++j) rs += ' ';
            rs += s + '|';
        }
        int tot_size = rs.size();
        rs += '\n';
        for (int i = 0; i < tot_size; ++i) rs += '-';
        rs += '\n';
        int id = 1;
        for (const Student& i : a) {
            rs += '|';
            string strId = intToString(id++);
            for (int j = 0; j < col_size[0] - strId.size(); ++j) rs += ' ';
            rs += strId + '|';
            for (int j = 0; j < col_size[1] - i.id.size(); ++j) rs += ' ';
            rs += i.id + '|';
            for (int j = 0; j < col_size[2] - i.name.size(); ++j) rs += ' ';
            rs += i.name + '|';
            for (int j = 0; j < col_size[3] - i.email.size(); ++j) rs += ' ';
            rs += i.email + '|' + '\n';
        }
        return rs;
    }
};

#endif