#include <iostream>
using namespace std;

template <typename T>
class MyArray {
private:
    T* data;      // con trỏ tới vùng nhớ mảng
    int size;     // kích thước mảng

public:
    // Constructor: khởi tạo mảng với kích thước cho trước
    MyArray(int n) {
        size = n;
        data = new T[size];   // cấp phát động
    }

    // Destructor: giải phóng bộ nhớ
    ~MyArray() {
        delete[] data;
    }

    // Trả về kích thước mảng
    int getSize() const {
        return size;
    }

    // Lấy giá trị phần tử thứ i
    T get(int index) const {
        if (index < 0 || index >= size) {
            cout << "Chi so khong hop le!\n";
            return T();  // trả về giá trị mặc định
        }
        return data[index];
    }

    // Gán giá trị cho phần tử thứ i
    void set(int index, T value) {
        if (index < 0 || index >= size) {
            cout << "Chi so khong hop le!\n";
            return;
        }
        data[index] = value;
    }

    // In toàn bộ mảng
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MyArray<int> arr(5);

    // Gán giá trị
    for (int i = 0; i < arr.getSize(); i++) {
        arr.set(i, i * 10);
    }

    // Lấy giá trị
    cout << "Gia tri arr[2] = " << arr.get(2) << endl;

    // In toàn bộ mảng
    cout << "Mang: ";
    arr.print();

    return 0;
}