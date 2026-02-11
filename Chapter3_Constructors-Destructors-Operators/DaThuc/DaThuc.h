#ifndef DATHUC_H
#define DATHUC_H

#include <iostream>
using namespace std;

class DaThuc {
private:
    int Bac;          // Bậc của đa thức
    double* HeSo;     // Mảng hệ số (HeSo[i] là hệ số của x^i)

public:
    // Constructor & Destructor
    DaThuc();                          
    DaThuc(int bac);                   
    DaThuc(const DaThuc& other);       
    ~DaThuc();                         

    // Toán tử gán
    DaThuc& operator=(const DaThuc& other);

    // Các toán tử số học
    DaThuc operator+(const DaThuc& other) const;
    DaThuc operator-(const DaThuc& other) const;
    DaThuc operator*(const DaThuc& other) const;
    DaThuc operator/(const DaThuc& other) const; // chia đa thức (giả sử chia có dư)

    // Xuất đa thức
    friend ostream& operator<<(ostream& os, const DaThuc& dt);
};

#endif