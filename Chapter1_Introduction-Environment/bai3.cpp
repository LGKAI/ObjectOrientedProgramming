#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Chuẩn hóa: loại bỏ số 0 ở đầu
string chuanHoa(string s) {
    while (s.length() > 1 && s[0] == '0') s.erase(0, 1);
    return s;
}

// So sánh hai số lớn
int soSanh(string a, string b) {
    a = chuanHoa(a);
    b = chuanHoa(b);
    if (a.length() != b.length())
        return a.length() > b.length() ? 1 : -1;
    return a > b ? 1 : (a < b ? -1 : 0);
}

// Cộng hai số lớn
string cong(string a, string b) {
    string ketQua = "";
    int nho = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len = max(a.length(), b.length());
    while (a.length() < len) a += '0';
    while (b.length() < len) b += '0';

    for (int i = 0; i < len; ++i) {
        int tong = (a[i] - '0') + (b[i] - '0') + nho;
        ketQua += (tong % 10) + '0';
        nho = tong / 10;
    }
    if (nho) ketQua += '1';
    reverse(ketQua.begin(), ketQua.end());
    return chuanHoa(ketQua);
}

// Trừ hai số lớn (a - b), giả sử a ≥ b
string tru(string a, string b) {
    string ketQua = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len = max(a.length(), b.length());
    while (a.length() < len) a += '0';
    while (b.length() < len) b += '0';

    int muon = 0;
    for (int i = 0; i < len; ++i) {
        int soA = a[i] - '0' - muon;
        int soB = b[i] - '0';
        if (soA < soB) {
            soA += 10;
            muon = 1;
        } else {
            muon = 0;
        }
        ketQua += (soA - soB) + '0';
    }
    reverse(ketQua.begin(), ketQua.end());
    return chuanHoa(ketQua);
}

// Nhân hai số lớn
string nhan(string a, string b) {
    int lenA = a.length(), lenB = b.length();
    vector<int> ketQua(lenA + lenB, 0);

    for (int i = lenA - 1; i >= 0; --i) {
        for (int j = lenB - 1; j >= 0; --j) {
            int tich = (a[i] - '0') * (b[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int tong = tich + ketQua[p2];
            ketQua[p2] = tong % 10;
            ketQua[p1] += tong / 10;
        }
    }

    string ketQuaStr = "";
    for (int num : ketQua) ketQuaStr += (num + '0');
    return chuanHoa(ketQuaStr);
}

// Chia hai số lớn (a / b), giả sử b ≠ 0
string chia(string a, string b) {
    if (soSanh(a, b) < 0) return "0";
    string thuong = "", phanDu = "";
    for (char c : a) {
        phanDu += c;
        phanDu = chuanHoa(phanDu);
        int dem = 0;
        while (soSanh(phanDu, b) >= 0) {
            phanDu = tru(phanDu, b);
            dem++;
        }
        thuong += (dem + '0');
    }
    return chuanHoa(thuong);
}

int main() {
    string a, b;
    cout << "=== Chuong trinh xu ly so nguyen lon ===\n";
    cout << "Nhap so thu nhat: ";
    cin >> a;
    cout << "Nhap so thu hai: ";
    cin >> b;

    cout << "\nTong: " << cong(a, b) << endl;

    if (soSanh(a, b) >= 0)
        cout << "Hieu: " << tru(a, b) << endl;
    else
        cout << "Hieu: -" << tru(b, a) << endl;

    cout << "Tich: " << nhan(a, b) << endl;

    if (b == "0")
        cout << "Khong the chia cho 0\n";
    else
        cout << "Thuong: " << chia(a, b) << endl;

    return 0;
}