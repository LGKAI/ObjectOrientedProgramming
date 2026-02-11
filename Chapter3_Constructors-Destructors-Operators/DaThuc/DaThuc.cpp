#include <iostream>
#include <cmath>
#include "DaThuc.h"
using namespace std;

// Constructor mặc định
DaThuc::DaThuc() {
    Bac = 0;
    HeSo = new double[1]{0};
}

// Constructor có tham số
DaThuc::DaThuc(int bac) {
    Bac = bac;
    HeSo = new double[Bac + 1];
    for (int i = 0; i <= Bac; ++i)
        HeSo[i] = 0;
}

// Copy constructor
DaThuc::DaThuc(const DaThuc& other) {
    Bac = other.Bac;
    HeSo = new double[Bac + 1];
    for (int i = 0; i <= Bac; ++i)
        HeSo[i] = other.HeSo[i];
}

// Destructor (kiểm tra null)
DaThuc::~DaThuc() {
    if (HeSo != nullptr) {
        delete[] HeSo;
        HeSo = nullptr;
    }
}

// Toán tử gán
DaThuc& DaThuc::operator=(const DaThuc& other) {
    if (this != &other) {
        if (HeSo != nullptr)
            delete[] HeSo;
        Bac = other.Bac;
        HeSo = new double[Bac + 1];
        for (int i = 0; i <= Bac; ++i)
            HeSo[i] = other.HeSo[i];
    }
    return *this;
}

// Toán tử cộng
DaThuc DaThuc::operator+(const DaThuc& other) const {
    int maxBac = (Bac > other.Bac) ? Bac : other.Bac;
    DaThuc tong(maxBac);
    for (int i = 0; i <= maxBac; ++i) {
        double a = (i <= Bac) ? HeSo[i] : 0;
        double b = (i <= other.Bac) ? other.HeSo[i] : 0;
        tong.HeSo[i] = a + b;
    }
    return tong;
}

// Toán tử trừ
DaThuc DaThuc::operator-(const DaThuc& other) const {
    int maxBac = (Bac > other.Bac) ? Bac : other.Bac;
    DaThuc hieu(maxBac);
    for (int i = 0; i <= maxBac; ++i) {
        double a = (i <= Bac) ? HeSo[i] : 0;
        double b = (i <= other.Bac) ? other.HeSo[i] : 0;
        hieu.HeSo[i] = a - b;
    }
    return hieu;
}

// Toán tử nhân
DaThuc DaThuc::operator*(const DaThuc& other) const {
    DaThuc tich(Bac + other.Bac);
    for (int i = 0; i <= Bac; ++i)
        for (int j = 0; j <= other.Bac; ++j)
            tich.HeSo[i + j] += HeSo[i] * other.HeSo[j];

    return tich;
}

// Toán tử chia (chia đa thức, chỉ lấy phần thương)
DaThuc DaThuc::operator/(const DaThuc& other) const {
    if (other.Bac == 0 && other.HeSo[0] == 0) {
        cerr << "Loi: chia cho da thuc 0!" << endl;
        return DaThuc();
    }
    if (Bac < other.Bac)
        return DaThuc(); // thương = 0
    DaThuc thuong(Bac - other.Bac);
    DaThuc du(*this);
    for (int i = du.Bac; i >= other.Bac; --i) {
        double hs = du.HeSo[i] / other.HeSo[other.Bac];
        int bacHieu = i - other.Bac;
        thuong.HeSo[bacHieu] = hs;
        for (int j = 0; j <= other.Bac; ++j)
            du.HeSo[j + bacHieu] -= hs * other.HeSo[j];
    }
    return thuong;
}

// Toán tử xuất <<
ostream& operator<<(ostream& os, const DaThuc& dt) {
    bool first = true;
    for (int i = dt.Bac; i >= 0; --i) {
        double hs = dt.HeSo[i];
        if (hs != 0) {
            if (!first) {
                os << (hs > 0 ? " + " : " - ");
            } else if (hs < 0) {
                os << "-";
            }
            first = false;
            double absHs = fabs(hs);
            if (i == 0)
                os << absHs;
            else if (i == 1)
                os << absHs << "x";
            else
                os << absHs << "x^" << i;
        }
    }
    if (first) os << "0";
    return os;
}