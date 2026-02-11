#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<string, int> num_order = {
    {"10", 9},
    {"2", 1},
    {"3", 2},
    {"4", 3},
    {"5", 4},
    {"6", 5},
    {"7", 6},
    {"8", 7},
    {"9", 8},
    {"A", 13},
    {"J", 10},
    {"K", 12},
    {"Q", 11}
};
map<string, int> typ_order = {
    {"C", 2},
    {"H", 4},
    {"P", 1},
    {"T", 3}
};
map<vector<int>, int> permu_order = {
    {{0, 1, 2, 3}, 0},
    {{0, 1, 3, 2}, 1},
    {{0, 2, 1, 3}, 2},
    {{0, 2, 3, 1}, 3},
    {{0, 3, 1, 2}, 4},
    {{0, 3, 2, 1}, 5},
    {{1, 0, 2, 3}, 6},
    {{1, 0, 3, 2}, 7},
    {{1, 2, 0, 3}, 8},
    {{1, 2, 3, 0}, 9},
    {{1, 3, 0, 2}, 10},
    {{1, 3, 2, 0}, 11},
    {{2, 0, 1, 3}, 12},
    {{2, 0, 3, 1}, 13},
    {{2, 1, 0, 3}, 14},
    {{2, 1, 3, 0}, 15},
    {{2, 3, 0, 1}, 16},
    {{2, 3, 1, 0}, 17},
    {{3, 0, 1, 2}, 18},
    {{3, 0, 2, 1}, 19},
    {{3, 1, 0, 2}, 20},
    {{3, 1, 2, 0}, 21},
    {{3, 2, 0, 1}, 22},
    {{3, 2, 1, 0}, 23}
};
vector<int> pm(4, 0);
int id = 0;
bool mark[5];

class Card {
private:
    string num;
    string typ;
public:
    Card() {}
    Card(string s) {
        if (s.size() == 2) {
            num = s.substr(0, 1);
            typ = s.substr(1, 1);
        }
        else {
            num = s.substr(0, 2);
            typ = s.substr(2, 1);
        }
    }
    Card(string n, string t) : num(n), typ(t) {}
    bool operator<(const Card& other) {
        if (num != other.num) {
            return num_order[num] < num_order[other.num];
        }
        return typ_order[typ] < typ_order[other.typ];
    }
    bool operator!=(const Card& other) {
        return num != other.num || typ != other.typ;
    }
    bool operator==(const Card& other) {
        return num == other.num && typ == other.typ;
    }
    operator string() {
        return num + typ;
    }
    string getNum() { return num; }
    string getType() { return typ; }
};

bool cmp(Card a, Card b) {
    if (a.getNum() != b.getNum()) {
        return num_order[a.getNum()] < num_order[b.getNum()];
    }
    return typ_order[a.getType()] < typ_order[b.getType()];
}

class An {
public:
    An() {}
    vector<string> pick(vector<string> X) {
        vector<Card> x;
        for (string &i : X) x.push_back(Card(i));
        sort(x.begin(), x.end(), cmp);
        pair<Card, Card> p;
        for (int i = 0; i < 6; ++i) for (int j = i + 1; j < 6; ++j)
            if (x[i].getType() == x[j].getType())
                p = {x[i], x[j]};
        vector<Card> remain;
        // remain.push_back(p.first);
        for (int i = 0; i < 6; ++i) if (x[i] != p.first && x[i] != p.second) {
            remain.push_back(x[i]);
        }
        int dif = num_order[p.second.getNum()] - num_order[p.first.getNum()];
        vector<int> permu;
        for (auto &[v, id] : permu_order) if (id == dif) {
            permu = v;
        }
        vector<string> rs = {(string)p.first};
        for (int i = 0; i < 4; ++i) rs.push_back((string)remain[permu[i]]);
        return rs;
    }
};

class Binh {
public:
    Binh() {}
    string guess(vector <string> X) {
        vector<Card> x;
        for (string i : X) x.push_back(Card(i));
        Card fi = x[0];
        string typ = fi.getType();
        string num;
        vector<Card> y = {x.begin() + 1, x.end()};
        sort(y.begin(), y.end(), cmp);
        vector<int> permu;
        for (int i = 1; i < 5; ++i) for (int j = 0; j < 4; ++j)
            if (x[i] == y[j]) 
                permu.push_back(j);
        int dif = permu_order[permu];
        int num_id = num_order[fi.getNum()] + dif;
        for (auto &[n, id] : num_order) if (id == num_id) num = n;
        Card rs(num, typ);
        return (string)rs;
    }
};

int main() {
    vector<string> X = {"2C", "9H", "5H", "JC", "8T", "6P"};
    An a;
    Binh b;
    vector<string> picked = a.pick(X);
    cout << "Picked: ";
    for (string i : picked) cout << i << ' ';
    cout << '\n';
    cout << "Guess: " << b.guess(picked) << '\n';
    return 0;
}

// #include "main.h"