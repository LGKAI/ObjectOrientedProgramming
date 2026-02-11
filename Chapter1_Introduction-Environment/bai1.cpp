#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Cấu trúc đơn thức: ax^n
struct DonThuc {
    double heSo;
    int bac;
};

// Nhập đơn thức
DonThuc nhapDonThuc() {
    DonThuc dt;
    cout << "Nhap he so: ";
    cin >> dt.heSo;
    cout << "Nhap bac: ";
    cin >> dt.bac;
    return dt;
}

// Xuất đơn thức
void xuatDonThuc(DonThuc dt) {
    cout << dt.heSo << "x^" << dt.bac;
}

// Tính giá trị đơn thức tại x
double tinhGiaTriDonThuc(DonThuc dt, double x) {
    return dt.heSo * pow(x, dt.bac);
}

// Nhập đa thức
vector<DonThuc> nhapDaThuc() {
    int n;
    cout << "Nhap so luong don thuc: ";
    cin >> n;
    vector<DonThuc> daThuc(n);
    for (int i = 0; i < n; ++i) {
        cout << "Don thuc thu " << i + 1 << ":\n";
        daThuc[i] = nhapDonThuc();
    }
    return daThuc;
}

// Xuất đa thức
void xuatDaThuc(const vector<DonThuc>& daThuc) {
    for (size_t i = 0; i < daThuc.size(); ++i) {
        xuatDonThuc(daThuc[i]);
        if (i != daThuc.size() - 1) cout << " + ";
    }
    cout << endl;
}

// Tính giá trị đa thức tại x
double tinhGiaTriDaThuc(const vector<DonThuc>& daThuc, double x) {
    double tong = 0;
    for (const auto& dt : daThuc) {
        tong += tinhGiaTriDonThuc(dt, x);
    }
    return tong;
}

// Cộng hai đa thức
vector<DonThuc> congDaThuc(const vector<DonThuc>& a, const vector<DonThuc>& b) {
    vector<DonThuc> ketQua = a;
    for (const auto& dtB : b) {
        bool timThay = false;
        for (auto& dtA : ketQua) {
            if (dtA.bac == dtB.bac) {
                dtA.heSo += dtB.heSo;
                timThay = true;
                break;
            }
        }
        if (!timThay) ketQua.push_back(dtB);
    }
    return ketQua;
}

// Trừ hai đa thức
vector<DonThuc> truDaThuc(const vector<DonThuc>& a, const vector<DonThuc>& b) {
    vector<DonThuc> bAm = b;
    for (auto& dt : bAm) dt.heSo *= -1;
    return congDaThuc(a, bAm);
}

// Nhân hai đa thức
vector<DonThuc> nhanDaThuc(const vector<DonThuc>& a, const vector<DonThuc>& b) {
    vector<DonThuc> ketQua;
    for (const auto& dtA : a) {
        for (const auto& dtB : b) {
            DonThuc dt;
            dt.heSo = dtA.heSo * dtB.heSo;
            dt.bac = dtA.bac + dtB.bac;
            ketQua.push_back(dt);
        }
    }
    return ketQua;
}

int main() {
    cout << "=== Chuong trinh xu ly da thuc ===\n";
    vector<DonThuc> daThuc1 = nhapDaThuc();
    vector<DonThuc> daThuc2 = nhapDaThuc();

    cout << "\nDa thuc 1: ";
    xuatDaThuc(daThuc1);

    cout << "Da thuc 2: ";
    xuatDaThuc(daThuc2);

    double x;
    cout << "\nNhap gia tri x: ";
    cin >> x;

    cout << "Gia tri da thuc 1 tai x = " << x << ": " << tinhGiaTriDaThuc(daThuc1, x) << endl;
    cout << "Gia tri da thuc 2 tai x = " << x << ": " << tinhGiaTriDaThuc(daThuc2, x) << endl;

    cout << "\nTong hai da thuc: ";
    xuatDaThuc(congDaThuc(daThuc1, daThuc2));

    cout << "Hieu hai da thuc: ";
    xuatDaThuc(truDaThuc(daThuc1, daThuc2));

    cout << "Tich hai da thuc: ";
    xuatDaThuc(nhanDaThuc(daThuc1, daThuc2));

    return 0;
}

// Có 2 cách để chạy file .cpp
// Cách 1:
// 1. Ctrl ~ để mở terminal, gõ "g++ bai_1.cpp -o bai_1.exe" để tạo file output
// (phải mở đúng folder chứa file bai_1.cpp, nếu không thì phải viết cả path đến file)
// 2. Chạy file output bằng cách gõ tên file ./bai_1.exe

// Cách 2:
// 1. Bấm nút play để chạy như truyền thống rồi chọn g++
// 2. Tự động tạo file task.json, có thể chỉnh file đó để chỉnh file output tuỳ ý