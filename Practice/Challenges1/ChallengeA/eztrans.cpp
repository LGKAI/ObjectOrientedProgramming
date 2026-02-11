#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string toBit5(int x) {
    string rs = "";
    while (x) rs += (char)(x % 2 + '0'), x /= 2;
    while (rs.size() < 5) rs.push_back('0');
    reverse(rs.begin(), rs.end());
    return rs;
}

string toBit6(int x) {
    string rs = "";
    while (x) rs += (char)(x % 2 + '0'), x /= 2;
    while (rs.size() < 6) rs.push_back('0');
    reverse(rs.begin(), rs.end());
    return rs;
}

class Captain {
public:
    Captain() {}
    string encode(string time) {
        int h = 0, m = 0, s = 0, cur = 0;
        bool first = 1;
        for (int i = 0; i < time.size(); ++i) {
            if (time[i] == ':') {
                if (first) {
                    h = cur;
                    cur = 0;
                }
                else {
                    m = cur;
                    cur = 0;
                }
                first = 0;
            }
            else cur = cur * 10 + (time[i] - '0');
        }
        s = cur;
        return toBit5(h) + toBit6(m) + toBit6(s);
    }
};

string toStringInt(string s) {
    int val = 0;
    for (char i : s) val = val * 2 + (i - '0');
    string rs = "";
    while (val) rs += (char)(val % 10 + '0'), val /= 10;
    while (rs.size() < 2) rs += '0';
    reverse(rs.begin(), rs.end());
    return rs;
}

class Soldier {
private:
    int id;

public:
    Soldier() {}
    Soldier(int i) : id(i) {}
    string decode(string time) {
        string h = toStringInt(time.substr(0, 5)), m = toStringInt(time.substr(5, 6)), s = toStringInt(time.substr(11, 6));
        return h + ":" + m + ":" + s;
    }
};

// #include "main.h"

int main() {
    string time = "12:30:11";
    Captain c;
    Soldier s;
    cout << s.decode(c.encode(time)) << '\n';
    return 0;
}