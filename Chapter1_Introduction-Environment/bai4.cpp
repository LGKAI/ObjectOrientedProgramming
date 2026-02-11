#include <iostream>
#include <fstream>
#include <cstdio>     // dùng remove(), rename()
#include <cstdlib>    // dùng system()
#include <string>

using namespace std;

// Tạo file và ghi nội dung
void taoFile(const string& tenFile) {
    ofstream file(tenFile);
    if (!file) {
        cout << "Khong the tao file.\n";
        return;
    }
    cout << "Nhap noi dung file (ket thuc bang dau #):\n";
    string dong;
    while (getline(cin, dong) && dong != "#") {
        file << dong << endl;
    }
    file.close();
    cout << "Da tao file: " << tenFile << endl;
}

// Xem nội dung file
void xemFile(const string& tenFile) {
    ifstream file(tenFile);
    if (!file) {
        cout << "Khong the mo file.\n";
        return;
    }
    cout << "Noi dung file:\n";
    string dong;
    while (getline(file, dong)) {
        cout << dong << endl;
    }
    file.close();
}

// Xóa file
void xoaFile(const string& tenFile) {
    if (remove(tenFile.c_str()) == 0)
        cout << "Da xoa file: " << tenFile << endl;
    else
        cout << "Khong the xoa file.\n";
}

// Đổi tên file
void doiTenFile(const string& tenCu, const string& tenMoi) {
    if (rename(tenCu.c_str(), tenMoi.c_str()) == 0)
        cout << "Da doi ten file thanh: " << tenMoi << endl;
    else
        cout << "Khong the doi ten file.\n";
}

// Sao chép file
void copyFile(const string& tenNguon, const string& tenDich) {
    ifstream in(tenNguon);
    ofstream out(tenDich);
    if (!in || !out) {
        cout << "Khong the sao chep file.\n";
        return;
    }
    string dong;
    while (getline(in, dong)) {
        out << dong << endl;
    }
    in.close();
    out.close();
    cout << "Da sao chep file sang: " << tenDich << endl;
}

// Cắt/Nối file (di chuyển nội dung từ file A sang B)
void catFile(const string& tenNguon, const string& tenDich) {
    ifstream in(tenNguon);
    ofstream out(tenDich, ios::app); // nối vào cuối file
    if (!in || !out) {
        cout << "Khong the cat file.\n";
        return;
    }
    string dong;
    while (getline(in, dong)) {
        out << dong << endl;
    }
    in.close();
    out.close();
    remove(tenNguon.c_str()); // xóa file nguồn
    cout << "Da cat file " << tenNguon << " sang " << tenDich << endl;
}

int main() {
    int luaChon;
    string tenFile, tenMoi;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tao file\n";
        cout << "2. Xem file\n";
        cout << "3. Xoa file\n";
        cout << "4. Doi ten file\n";
        cout << "5. Copy file\n";
        cout << "6. Cat file\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> luaChon;
        cin.ignore(); // loại bỏ ký tự xuống dòng

        switch (luaChon) {
            case 1:
                cout << "Nhap ten file muon tao: ";
                getline(cin, tenFile);
                taoFile(tenFile);
                break;
            case 2:
                cout << "Nhap ten file muon xem: ";
                getline(cin, tenFile);
                xemFile(tenFile);
                break;
            case 3:
                cout << "Nhap ten file muon xoa: ";
                getline(cin, tenFile);
                xoaFile(tenFile);
                break;
            case 4:
                cout << "Nhap ten file cu: ";
                getline(cin, tenFile);
                cout << "Nhap ten file moi: ";
                getline(cin, tenMoi);
                doiTenFile(tenFile, tenMoi);
                break;
            case 5:
                cout << "Nhap ten file nguon: ";
                getline(cin, tenFile);
                cout << "Nhap ten file dich: ";
                getline(cin, tenMoi);
                copyFile(tenFile, tenMoi);
                break;
            case 6:
                cout << "Nhap ten file nguon: ";
                getline(cin, tenFile);
                cout << "Nhap ten file dich: ";
                getline(cin, tenMoi);
                catFile(tenFile, tenMoi);
                break;
            case 0:
                cout << "Tam biet!\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (luaChon != 0);

    return 0;
}