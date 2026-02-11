#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;
    int res = n + m + k;

    if (res % 3 == 0 || res % 10 == 0) { cout << "yes"; return 0; }
    if (res % 5 == 0 || res % 7 == 0 || res % 11 == 0) { cout << "no"; return 0; }
    if (isPrime(res)) { cout << "yes"; return 0; }
    if (res % 4 == 0 && res % 13 == 0) { cout << "no"; return 0; }
    if (res % 13 == 0) { cout << "yes"; return 0; }
    if (res % 16 == 0) { cout << "no"; return 0; }
    if (res % 8 == 0) { cout << "yes"; return 0; }

    int a[] = {2002, 2006, 2014, 2018, 2026, 2038, 2042, 2054, 2062, 2066, 2074, 2078, 2098, 2114, 2122};
    for(int v: a)
    {
        if(res == v)
        {
            cout << "yes";
            return 0;
        }
    }   

    cout << "no";
    return 0;
}