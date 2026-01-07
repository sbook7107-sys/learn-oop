#include <iostream>
using namespace std;

class Complex {
private:
    double a, b;
public:
    Complex() : a(0), b(0) {}
    Complex(double thuc, double ao) : a(thuc), b(ao) {}
    Complex(const Complex &x) {
        a = x.a;
        b = x.b;
    }

    void nhap()
    {
        cout << "\nNhap phan thuc: ";
        cin >> a;
        cout << "Nhap phan ao: ";
        cin >> b;
    }

    void in()
    {
        cout << a;
        if(b >= 0) {
            cout << "+";
        }
        cout << b << "i";
    }

    Complex operator+(const Complex &c1) {
        return Complex(a + c1.a, b + c1.b);
    }
    Complex operator-(const Complex &c1) {
        return Complex(a - c1.a, b - c1.b);
    }
};


int main() {
    Complex x, y;
    cout << "\nNhap so phuc x: ";
    x.nhap();
    cout << "\nNhap so phuc y: ";
    y.nhap();

    Complex tong = x + y, hieu = x - y;
    cout << "\nTong cua so phuc x va y la: ";
    tong.in();
    cout << "\nHieu cua so phuc x va y la: ";
    hieu.in();

    return 0;
}
