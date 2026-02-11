#pragma once
#include <vector>
#include <string>
using namespace std;

namespace Utils {
    class String {
    public:
        static vector<string> split(string s, string delim) {
            vector<string> result;
            size_t start = 0;
            size_t pos = s.find(delim);
            while (pos != string::npos) {
                result.push_back(s.substr(start, pos - start));
                start = pos + delim.length();
                pos = s.find(delim, start);
            }
            result.push_back(s.substr(start));
            return result;
        }
    };
}