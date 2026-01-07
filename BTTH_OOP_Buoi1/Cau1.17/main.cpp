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

    bool operator==(const Complex &c1) {
        return a == c1.a && b == c1.b;
    }
};


int main() {
    int n;
    cout << "\nNhap so luong phan tu: ";
    cin >> n;

    Complex c[n];
    for(int i = 0; i < n; i++) {
        c[i].nhap();
    }

    Complex x;
    cout << "\nNhap so phuc x: ";
    x.nhap();

    bool found = false;
    for(int i = 0; i < n; i++) {
        if(c[i] == x) {
            found = true;
            break;
        }
    }
    if(found)
        cout << "\nCo so phuc x trong mnag";
    else
        cout << "\nKhong co so phuc x trong mang";

    return 0;
}
