#include <iostream>
using namespace std;

int main() {
    double tu, mau, res;

    cout << "Nhap tu: ";
    cin >> tu;
    cout << "Nhap mau: ";
    cin >> mau;

    try {
        // Kiểm tra điều kiện lỗi
        if (mau == 0) {
            // Ném ngoại lệ kiểu chuỗi
            throw "Loi: Mau deo duoc bang 0!!!";
        }
        res = tu / mau;
        cout << "Ket qua: " << res << endl;
    }
    catch (const char* msg) { // msg là chuỗi bị ném ra
        // Bắt và hiển thị chuỗi thông báo lỗi
        cerr << "Da bat duoc ngoai le: " << msg << endl;
    }

    return 0;
}