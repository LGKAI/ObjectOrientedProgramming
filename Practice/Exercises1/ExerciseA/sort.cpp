#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 2 dòng trên để code chạy nhanh hơn (độ xe)

    string orderType, dataType;
    cin >> orderType >> dataType;
    int n;
    cin >> n;

    bool increase = (orderType == "increase");

    if (dataType == "int") {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end()); // mặc định là tăng dần
        if (!increase) reverse(a.begin(), a.end());
        for (int x : a) cout << x << "\n";
    }

    else if (dataType == "char") {
        vector<char> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        if (!increase) reverse(a.begin(), a.end());
        for (char c : a) cout << c << "\n";
    }

    else if (dataType == "string") {
        vector<string> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        if (!increase) reverse(a.begin(), a.end());
        for (string s : a) cout << s << "\n";
    }

    else if (dataType == "fraction") {
        vector<pair<int, int>> frac(n); // mỗi phần tử là (tử, mẫu)
        for (int i = 0; i < n; i++) {
            cin >> frac[i].first >> frac[i].second;
        }

        // hàm so sánh 2 phân số a/b và c/d
        auto cmp = [](pair<int,int> f1, pair<int,int> f2) {
            // f1 < f2 nếu a*d < c*b
            return (long long)f1.first * f2.second < (long long)f2.first * f1.second;
        };

        sort(frac.begin(), frac.end(), cmp);
        if (!increase) reverse(frac.begin(), frac.end());

        for (auto f : frac)
            cout << f.first << " " << f.second << "\n";
    }

    return 0;
}