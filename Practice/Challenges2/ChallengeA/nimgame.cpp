#include <bits/stdc++.h>
using namespace std;

class Player {
private:
    vector<int> a;
    set<int> available;
    int xsum;

public:
    Player() {
        a.clear();
        xsum = 0;
    }

    Player(vector<int> _a) {
        a = _a;
        xsum = 0;
        for (int i = 0; i < a.size(); ++i) available.insert(i);
        for (const int& i : a) xsum = (xsum ^ i);
    }

    bool goFirst() {
        if (xsum) return true;
        return false;
    }

    pair<int, int> play() {
        pair<int, int> rs;
        if (xsum) {
            for (const int& i : available) {
                int t = (a[i] ^ xsum);
                if (t < a[i]) {
                    rs = {i, a[i] - t};
                    xsum = 0;
                    a[i] = t;
                    break;
                }
            }
        }
        else {
            for (int i = 0; i < a.size(); ++i) if (a[i]) {
                rs = {i, a[i]};
                a[i] = 0;
                xsum = (xsum ^ a[i]);
                break;
            }
        }
        if (!a[rs.first]) available.erase(rs.first);
        return rs;
    }

    void playBack(pair<int, int> k) {
        xsum = (xsum ^ a[k.first] ^ (a[k.first] - k.second));
        a[k.first] -= k.second;
        if (!a[k.first]) available.erase(k.first);
    }

    int getXSum() {
        return xsum;
    }

    int getSum() {
        int sum = 0;
        for (int i : a) sum += i;
        return sum;
    }
};

// #include "main.h"