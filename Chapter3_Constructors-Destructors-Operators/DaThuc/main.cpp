#include <iostream>
#include "DaThuc.h"
using namespace std;

int main() {
    int bacA, bacB;

    cout << "Nhap bac cua da thuc a: ";
    cin >> bacA;
    DaThuc a(bacA);

    cout << "Nhap he so cua da thuc a (tu bac 0 den " << bacA << "):\n";
    for (int i = 0; i <= bacA; ++i) {
        double hs;
        cin >> hs;
        a.operator=(a); // kiểm tra self-assignment, không ảnh hưởng
        a = a;          // test lại gán chính nó
    }

    cout << "\nNhap bac cua da thuc b: ";
    cin >> bacB;
    DaThuc b(bacB);

    cout << "Nhap he so cua da thuc b (tu bac 0 den " << bacB << "):\n";
    for (int i = 0; i <= bacB; ++i) {
        double hs;
        cin >> hs;
    }

    // Tạo bản sao để test copy
    DaThuc c = a;

    // Thực hiện các phép toán
    DaThuc tong = a + b;
    DaThuc hieu = a - b;
    DaThuc tich = a * b;
    DaThuc thuong = a / b; // chỉ tính phần thương

    // Xuất kết quả
    cout << "\n================ KET QUA ================\n";
    cout << "Da thuc a: " << a << endl;
    cout << "Da thuc b: " << b << endl;
    cout << "Da thuc c (copy cua a): " << c << endl;
    cout << "\nTong (a + b): " << tong << endl;
    cout << "Hieu (a - b): " << hieu << endl;
    cout << "Tich (a * b): " << tich << endl;
    cout << "Thuong (a / b): " << thuong << endl;
    cout << "=========================================\n";

    return 0;
}