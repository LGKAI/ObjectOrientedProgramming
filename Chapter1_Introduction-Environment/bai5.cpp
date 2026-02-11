#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct HocSinh {
    string maHS;
    string tenHS;
    float toan, van, ly, hoa, ngoaiNgu;
    string diaChi;
    string ghiChu;
};

// Tính điểm trung bình
float diemTB(const HocSinh& hs) {
    return (hs.toan + hs.van + hs.ly + hs.hoa + hs.ngoaiNgu) / 5;
}

// Xếp loại học sinh
string xepLoai(float dtb) {
    if (dtb >= 8) return "Gioi";
    else if (dtb >= 6.5) return "Kha";
    else if (dtb >= 5) return "Trung binh";
    else return "Yeu";
}

// Nhập thông tin học sinh
HocSinh nhapHocSinh() {
    HocSinh hs;
    cout << "Ma HS: "; getline(cin, hs.maHS);
    cout << "Ten HS: "; getline(cin, hs.tenHS);
    cout << "Toan: "; cin >> hs.toan;
    cout << "Van: "; cin >> hs.van;
    cout << "Ly: "; cin >> hs.ly;
    cout << "Hoa: "; cin >> hs.hoa;
    cout << "Ngoai Ngu: "; cin >> hs.ngoaiNgu;
    cin.ignore();
    cout << "Dia chi: "; getline(cin, hs.diaChi);
    cout << "Ghi chu: "; getline(cin, hs.ghiChu);
    return hs;
}

// Xuất thông tin học sinh
void xuatHocSinh(const HocSinh& hs) {
    cout << left << setw(10) << hs.maHS << setw(20) << hs.tenHS
         << setw(5) << hs.toan << setw(5) << hs.van << setw(5) << hs.ly
         << setw(5) << hs.hoa << setw(5) << hs.ngoaiNgu
         << setw(6) << fixed << setprecision(1) << diemTB(hs)
         << setw(12) << xepLoai(diemTB(hs))
         << setw(20) << hs.diaChi << setw(20) << hs.ghiChu << endl;
}

// Cập nhật học sinh theo mã
void capNhatHocSinh(vector<HocSinh>& ds) {
    string ma;
    cout << "Nhap ma hoc sinh can cap nhat: ";
    getline(cin, ma);
    for (auto& hs : ds) {
        if (hs.maHS == ma) {
            cout << "Nhap thong tin moi:\n";
            hs = nhapHocSinh();
            return;
        }
    }
    cout << "Khong tim thay hoc sinh.\n";
}

// Xóa học sinh theo mã
void xoaHocSinh(vector<HocSinh>& ds) {
    string ma;
    cout << "Nhap ma hoc sinh can xoa: ";
    getline(cin, ma);
    ds.erase(remove_if(ds.begin(), ds.end(), [&](HocSinh hs) {
        return hs.maHS == ma;
    }), ds.end());
    cout << "Da xoa hoc sinh (neu ton tai).\n";
}

// Sắp xếp danh sách
void sapXep(vector<HocSinh>& ds, bool theoMa, bool tangDan) {
    sort(ds.begin(), ds.end(), [&](HocSinh a, HocSinh b) {
        if (theoMa)
            return tangDan ? a.maHS < b.maHS : a.maHS > b.maHS;
        else
            return tangDan ? diemTB(a) < diemTB(b) : diemTB(a) > diemTB(b);
    });
}

// Lưu danh sách ra file
void luuFile(const vector<HocSinh>& ds, const string& tenFile) {
    ofstream out(tenFile);
    for (const auto& hs : ds) {
        out << hs.maHS << "," << hs.tenHS << "," << hs.toan << "," << hs.van << ","
            << hs.ly << "," << hs.hoa << "," << hs.ngoaiNgu << ","
            << hs.diaChi << "," << hs.ghiChu << "\n";
    }
    out.close();
    cout << "Da luu danh sach vao file.\n";
}

// Đọc danh sách từ file
void docFile(vector<HocSinh>& ds, const string& tenFile) {
    ifstream in(tenFile);
    ds.clear();
    string dong;
    while (getline(in, dong)) {
        HocSinh hs;
        size_t pos = 0;
        vector<string> fields;
        while ((pos = dong.find(',')) != string::npos) {
            fields.push_back(dong.substr(0, pos));
            dong.erase(0, pos + 1);
        }
        fields.push_back(dong);
        if (fields.size() >= 9) {
            hs.maHS = fields[0];
            hs.tenHS = fields[1];
            hs.toan = stof(fields[2]);
            hs.van = stof(fields[3]);
            hs.ly = stof(fields[4]);
            hs.hoa = stof(fields[5]);
            hs.ngoaiNgu = stof(fields[6]);
            hs.diaChi = fields[7];
            hs.ghiChu = fields[8];
            ds.push_back(hs);
        }
    }
    in.close();
    cout << "Da import danh sach tu file.\n";
}

// Hiển thị danh sách học sinh
void hienThiDanhSach(const vector<HocSinh>& ds) {
    cout << left << setw(10) << "MaHS" << setw(20) << "TenHS"
         << setw(5) << "To" << setw(5) << "Va" << setw(5) << "Ly"
         << setw(5) << "Ho" << setw(5) << "NN"
         << setw(6) << "DTB" << setw(12) << "XepLoai"
         << setw(20) << "DiaChi" << setw(20) << "GhiChu" << endl;
    for (const auto& hs : ds) xuatHocSinh(hs);
}

int main() {
    vector<HocSinh> danhSach;
    int chon;
    string tenFile;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Them hoc sinh\n";
        cout << "2. Cap nhat hoc sinh\n";
        cout << "3. Xoa hoc sinh\n";
        cout << "4. Xem danh sach\n";
        cout << "5. Sap xep theo MaHS\n";
        cout << "6. Sap xep theo diem TB\n";
        cout << "7. Luu danh sach ra file\n";
        cout << "8. Import danh sach tu file\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {
            case 1:
                danhSach.push_back(nhapHocSinh());
                break;
            case 2:
                capNhatHocSinh(danhSach);
                break;
            case 3:
                xoaHocSinh(danhSach);
                break;
            case 4:
                hienThiDanhSach(danhSach);
                break;
            case 5:
                sapXep(danhSach, true, true); // theo MaHS tăng
                hienThiDanhSach(danhSach);
                break;
            case 6:
                sapXep(danhSach, false, false); // theo điểm giảm
                hienThiDanhSach(danhSach);
                break;
            case 7:
                cout << "Nhap ten file de luu: ";
                getline(cin, tenFile);
                luuFile(danhSach, tenFile);
                break;
            case 8:
                cout << "Nhap ten file de doc: ";
                getline(cin, tenFile);
                docFile(danhSach, tenFile);
                break;
            case 0:
                cout << "Tam biet!\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (chon != 0);

    return 0;
}