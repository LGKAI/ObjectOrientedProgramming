#include <iostream>
using namespace std;

// Template hàm hoán đổi
template <typename T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Template hàm sắp xếp (Bubble Sort)
template <typename T>
void sortArray(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                mySwap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Template hàm in mảng
template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int a[] = {4, 1, 7, 3};
    double b[] = {3.1, 2.5, 9.0, 1.2};
    string c[] = {"khanh", "anh", "binh", "tuan"};

    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    int n3 = sizeof(c) / sizeof(c[0]);

    cout << "Mang int truoc khi sap xep: ";
    printArray(a, n1);
    sortArray(a, n1);
    cout << "Sau khi sap xep: ";
    printArray(a, n1);

    cout << "\nMang double truoc khi sap xep: ";
    printArray(b, n2);
    sortArray(b, n2);
    cout << "Sau khi sap xep: ";
    printArray(b, n2);

    cout << "\nMang string truoc khi sap xep: ";
    printArray(c, n3);
    sortArray(c, n3);
    cout << "Sau khi sap xep: ";
    printArray(c, n3);

    return 0;
}