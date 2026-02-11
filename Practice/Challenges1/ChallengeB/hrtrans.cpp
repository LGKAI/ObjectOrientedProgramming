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
        string raw = toBit5(h) + toBit6(m) + toBit6(s);
        reverse(raw.begin(), raw.end());
        string rs = "";
        for (int i = 1; i <= 22; ++i) {
            if (i == 1 || i == 2 || i == 4 || i == 8 || i == 16) {
                rs += '0';
            }
            else {
                rs += raw.back();
                raw.pop_back();
            }
        }
        for (int i = 1; i <= 22; ++i) if (i != 1 && i != 2 && i != 4 && i != 8 && i != 16 && rs[i - 1] == '1') {
            for (int j = 0; j <= 4; ++j) if (i >> j & 1) {
                if (rs[(1 << j) - 1] == '0') rs[(1 << j) - 1] = '1';
                else rs[(1 << j) - 1] = '0';
            }
        }
        return rs;
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

int stringToInt(string s) {
    int rs = 0;
    for (int i = 0; i < s.size(); ++i) rs = rs * 2 + (s[i] - '0');
    return rs;
}

class Soldier {
private:
    int id;

public:
    Soldier() {}
    Soldier(int i) : id(i) {}
    string decode(string time) {
        string wrong = "00000";
        for (int i = 0; i <= 4; ++i) {
            char cur = '0';
            for (int j = 1; j <= 22; ++j) if ((j != (1 << i)) && j >> i & 1) {
                if (time[j - 1] == '1') cur = (cur == '0' ? '1' : '0');
            }
            if (cur != time[(1 << i) - 1]) {
                wrong[4 - i] = '1';
            }
        }
        // cout << "Wrong : " << wrong << '\n';
        if (wrong != "00000") {
            int pos = stringToInt(wrong);
            // cout << "Wrong at pos : " << pos << '\n';
            time[pos - 1] = (time[pos - 1] == '0' ? '1' : '0');
        }
        // cout << "After correct : \n" << time << '\n';
        string rs = "";
        for (int i = 1; i <= 22; ++i) if (i != 1 && i != 2 && i != 4 && i != 8 && i != 16) {
            rs += time[i - 1];
        }
        string h = toStringInt(rs.substr(0, 5)), m = toStringInt(rs.substr(5, 6)), s = toStringInt(rs.substr(11, 6));
        return h + ":" + m + ":" + s;
    }
};

// #include "main.h"

int main() {
    string time = "12:30:11";
    Captain c;
    Soldier s;
    string en = c.encode(time);
    en[18] = (en[18] == '0' ? '1' : '0');
    cout << en << '\n';
    cout << s.decode(en) << '\n';
    return 0;
}