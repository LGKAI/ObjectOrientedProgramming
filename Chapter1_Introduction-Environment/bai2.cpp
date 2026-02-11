#include <iostream>
#include <cmath>
using namespace std;

// Cấu trúc điểm
struct Diem {
    double x, y;
};

// Tính khoảng cách giữa hai điểm
double khoangCach(Diem a, Diem b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Nhập tam giác
void nhapTamGiac(Diem& A, Diem& B, Diem& C) {
    cout << "Nhap toa do diem A (x y): ";
    cin >> A.x >> A.y;
    cout << "Nhap toa do diem B (x y): ";
    cin >> B.x >> B.y;
    cout << "Nhap toa do diem C (x y): ";
    cin >> C.x >> C.y;
}

// Xuất tam giác
void xuatTamGiac(Diem A, Diem B, Diem C) {
    cout << "A(" << A.x << ", " << A.y << "), ";
    cout << "B(" << B.x << ", " << B.y << "), ";
    cout << "C(" << C.x << ", " << C.y << ")\n";
}

// Kiểm tra tam giác hợp lệ (3 điểm không thẳng hàng)
bool tamGiacHopLe(Diem A, Diem B, Diem C) {
    double area = 0.5 * abs((B.x - A.x)*(C.y - A.y) - (C.x - A.x)*(B.y - A.y));
    return area > 0;
}

// Tính chu vi tam giác
double tinhChuVi(Diem A, Diem B, Diem C) {
    double AB = khoangCach(A, B);
    double BC = khoangCach(B, C);
    double CA = khoangCach(C, A);
    return AB + BC + CA;
}

// Tính diện tích tam giác (công thức Heron)
double tinhDienTich(Diem A, Diem B, Diem C) {
    double AB = khoangCach(A, B);
    double BC = khoangCach(B, C);
    double CA = khoangCach(C, A);
    double p = (AB + BC + CA) / 2;
    return sqrt(p * (p - AB) * (p - BC) * (p - CA));
}

// Kiểm tra tam giác đều
bool laTamGiacDeu(Diem A, Diem B, Diem C) {
    double AB = khoangCach(A, B);
    double BC = khoangCach(B, C);
    double CA = khoangCach(C, A);
    return fabs(AB - BC) < 1e-6 && fabs(BC - CA) < 1e-6;
}

// Kiểm tra tam giác cân
bool laTamGiacCan(Diem A, Diem B, Diem C) {
    double AB = khoangCach(A, B);
    double BC = khoangCach(B, C);
    double CA = khoangCach(C, A);
    return fabs(AB - BC) < 1e-6 || fabs(BC - CA) < 1e-6 || fabs(CA - AB) < 1e-6;
}

// Kiểm tra tam giác vuông (dùng định lý Pythagoras)
bool laTamGiacVuong(Diem A, Diem B, Diem C) {
    double AB = khoangCach(A, B);
    double BC = khoangCach(B, C);
    double CA = khoangCach(C, A);
    double AB2 = AB * AB, BC2 = BC * BC, CA2 = CA * CA;
    return fabs(AB2 + BC2 - CA2) < 1e-6 ||
           fabs(BC2 + CA2 - AB2) < 1e-6 ||
           fabs(CA2 + AB2 - BC2) < 1e-6;
}

int main() {
    Diem A, B, C;
    cout << "=== Chuong trinh xu ly tam giac ===\n";
    nhapTamGiac(A, B, C);
    cout << "\nToa do tam giac: ";
    xuatTamGiac(A, B, C);

    if (!tamGiacHopLe(A, B, C)) {
        cout << "Tam giac khong hop le (3 diem thang hang).\n";
        return 0;
    }

    cout << "Chu vi tam giac: " << tinhChuVi(A, B, C) << endl;
    cout << "Dien tich tam giac: " << tinhDienTich(A, B, C) << endl;

    if (laTamGiacDeu(A, B, C)) cout << "Tam giac deu\n";
    else if (laTamGiacCan(A, B, C)) cout << "Tam giac can\n";
    else if (laTamGiacVuong(A, B, C)) cout << "Tam giac vuong\n";
    else cout << "Tam giac thuong\n";

    return 0;
}