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

    Complex& operator=(const Complex &c1)
    {
        if(this != &c1)
        {
            a = c1.a;
            b = c1.b;
        }
        return *this;
    }

    Complex operator+(const Complex &c1)
    {
        return Complex(a + c1.a, b + c1.b);
    }
};

int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    Complex c[n];
    for(int i = 0; i < n; i++) {
        c[i].nhap();
    }

    Complex tong;
    for(int i = 0; i < n; i++) {
        tong = tong + c[i];
    }
    cout << "\n
    Tong cac so phuc: ";
    tong.in();
    cout << endl;

    return 0;
}
