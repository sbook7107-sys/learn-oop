#include <iostream>
using namespace std;

class Complex {
private:
    double a, b;
public:
    Complex() : a(0), b(0) {}
    Complex(double thuc, double ao) : a(thuc), b(ao) {}

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

    friend Complex operator+(const Complex &c1, const Complex &c2);
    friend Complex operator-(const Complex &c1, const Complex &c2);
};

Complex operator+(const Complex &c1, const Complex &c2)
{
    return Complex(c1.a + c2.a, c1.b + c2.b);
}

Complex operator-(const Complex &c1, const Complex &c2)
{
    return Complex(c1.a - c2.a, c1.b - c2.b);
}

int main() {
    Complex c1, c2;
    cout << "Nhap thong tin c1: ";
    c1.nhap();
    cout << "\nNhap thong tin c2: ";
    c2.nhap();

    Complex tong = c1 + c2, hieu = c1 - c2;
    cout << "\Tong cua c1 va c2: ";
    tong.in();
    cout << "\nHieu cua c1 va c2: ";
    hieu.in();

    return 0;
}
