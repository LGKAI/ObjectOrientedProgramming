#include <bits/stdc++.h>
using namespace std;

struct CodeBook {
    static const int LEN = 22;
    static const int MOD = 45;
    static const int MAX_VAL = 1 << LEN;
    static const int NUM_Time = 86400;
    int* rev_map;
    vector<int> forward_map;
    bool initialized;

    CodeBook() {
        initialized = false;
        rev_map = new int[MAX_VAL];
        memset(rev_map, -1, sizeof(int) * MAX_VAL);
    }

    ~CodeBook() {
        delete[] rev_map;
    }

    void init() {
        if (initialized) return;
        
        int count = 0;
        for (int i = 0; i < MAX_VAL; ++i) {
            if (count >= NUM_Time) break;
            long long sum = 0;
            for (int k = 0; k < LEN; ++k) {
                if ((i >> k) & 1) {
                    sum += (k + 1);
                }
            }
            if (sum % MOD == 0) {
                rev_map[i] = count;
                forward_map.push_back(i);
                count++;
            }
        }
        initialized = true;
    }

    string intToString(int val) {
        string s = "";
        for (int i = 0; i < LEN; ++i) {
            s += ((val >> i) & 1) ? '1' : '0';
        }
        return s;
    }

    int stringToInt(const string& s) {
        int val = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                val |= (1 << i);
            }
        }
        return val;
    }
};

static CodeBook sharedBook;

class Captain {
public:
    Captain() {
        sharedBook.init();
    }

    std::string encode(std::string time) {
        int h, m, s;
        sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s);
        int timeID = h * 3600 + m * 60 + s;
        if (timeID < sharedBook.forward_map.size()) {
            int codeVal = sharedBook.forward_map[timeID];
            return sharedBook.intToString(codeVal);
        }
        return "";
    }
};

class Soldier {
private:
    int id;

public:
    Soldier() : id(0) {
        sharedBook.init();
    }

    Soldier(int id) : id(id) {
        sharedBook.init();
    }

    std::string decode(std::string s) {
        int foundID = -1;
        int n = s.length();

        if (n == 22) {
            int val = sharedBook.stringToInt(s);
            if (sharedBook.rev_map[val] != -1) {
                foundID = sharedBook.rev_map[val];
            } else {
                for (int i = 0; i < 22; ++i) {
                    int fixedVal = val ^ (1 << i);
                    if (sharedBook.rev_map[fixedVal] != -1) {
                        foundID = sharedBook.rev_map[fixedVal];
                        break;
                    }
                }
            }
        }
        else if (n == 21) {
            for (int i = 0; i <= 21; ++i) {
                string sub0 = s.substr(0, i) + "0" + s.substr(i);
                int val0 = sharedBook.stringToInt(sub0);
                if (sharedBook.rev_map[val0] != -1) {
                    foundID = sharedBook.rev_map[val0];
                    break;
                }
                string sub1 = s.substr(0, i) + "1" + s.substr(i);
                int val1 = sharedBook.stringToInt(sub1);
                if (sharedBook.rev_map[val1] != -1) {
                    foundID = sharedBook.rev_map[val1];
                    break;
                }
            }
        }
        else if (n == 23) {
            for (int i = 0; i < 23; ++i) {
                string sub = s.substr(0, i) + s.substr(i + 1);
                int val = sharedBook.stringToInt(sub);
                if (sharedBook.rev_map[val] != -1) {
                    foundID = sharedBook.rev_map[val];
                    break;
                }
            }
        }
        if (foundID != -1) {
            int h = foundID / 3600;
            int rem = foundID % 3600;
            int m = rem / 60;
            int sec = rem % 60;
            char buffer[10];
            sprintf(buffer, "%02d:%02d:%02d", h, m, sec);
            return string(buffer);
        }
        return "00:00:00";
    }
};

// #include "main.h"