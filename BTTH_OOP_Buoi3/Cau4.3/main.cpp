#include <iostream>
using namespace std;

class Frac {
private:
    double a, b; // tử và mẫu

public:
    Frac(double tu = 0, double mau = 1) {
        a = tu;
        b = mau;
    }

    void input() {
        cout << "Nhap tu so: ";
        cin >> a;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> b;
        } while (b == 0);
    }

    void output() const {
        cout << a << "/" << b;
    }

    // Toán tử +
    Frac operator+(const Frac& other) const {
        Frac temp;
        temp.a = a * other.b + b * other.a;
        temp.b = b * other.b;
        return temp;
    }

    // Toán tử gán
    Frac& operator=(const Frac& other) {
        a = other.a;
        b = other.b;
        return *this;
    }
};

template <class T>
T sum(T arr[], int n) {
    T total = arr[0];
    for (int i = 1; i < n; i++) {
        total = total + arr[i];
    }
    return total;
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

    Frac tongFS = sum(fs, n);

    cout << "\nTong cac phan so: ";
    tongFS.output();
    cout << endl;

    delete[] fs;

    // ======= MẢNG SỐ NGUYÊN =======
    cout << "\nNhap so luong so nguyen: ";
    cin >> n;

    int* arr = new int[n];
    cout << "\n=== Nhap so nguyen ===\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int tongInt = sum(arr, n);
    cout << "\nTong cac so nguyen: " << tongInt << endl;

    delete[] arr;

    return 0;
}
