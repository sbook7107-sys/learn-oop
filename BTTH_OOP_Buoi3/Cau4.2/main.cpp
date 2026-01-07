#include <iostream>
using namespace std;

class Frac {
private:
    double a, b; // tử số và mẫu số

public:
    // Hàm thiết lập mặc định
    Frac(double tu = 0, double mau = 1) {
        a = tu;
        b = mau;
    }

    // Hàm nhập
    void input() {
        cout << "Nhap tu so: ";
        cin >> a;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> b;
        } while (b == 0);
    }

    // Hàm in
    void output() const {
        cout << a << "/" << b;
    }

    // Định nghĩa toán tử >
    bool operator>(const Frac& other) const {
        return (a / b) > (other.a / other.b);
    }

    // Toán tử gán =
    Frac& operator=(const Frac& other) {
        a = other.a;
        b = other.b;
        return *this;
    }
};

template <class T>
T myMax(T arr[], int n) {
    T maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

int main() {
    int n;

    // ======= MẢNG PHÂN SỐ =======
    cout << "Nhap so luong phan so: ";
    cin >> n;

    Frac* fs = new Frac[n];

    cout << "\n=== Nhap phan so ===\n";
    for (int i = 0; i < n; i++) {
        fs[i].input();
    }

    Frac maxFrac = myMax(fs, n);

    cout << "\nPhan so lon nhat la: ";
    maxFrac.output();
    cout << endl;

    delete[] fs;

    // ======= MẢNG SỐ THỰC =======
    cout << "\nNhap so luong so thuc: ";
    cin >> n;

    double* arr = new double[n];
    cout << "\n=== Nhap so thuc ===\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    double maxDouble = myMax(arr, n);
    cout << "\nSo lon nhat la: " << maxDouble << endl;

    delete[] arr;

    return 0;
}

