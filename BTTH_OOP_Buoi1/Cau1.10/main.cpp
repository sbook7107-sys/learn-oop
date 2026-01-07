#include <iostream>

using namespace std;

class Vector {
private:
    int n;
    double *v;
public:
    Vector() : n(0), v(nullptr) {}
    Vector(int size) : n(size), v(nullptr)
    {
        if(n > 0) {
            v = new double[n];
            for(int i = 0; i < n; i++) {
                v[i] = 0;
            }
        }
    }

    Vector(const Vector &vec) : n(vec.n), v(nullptr)
    {
        if(n > 0)
        {
            v = new double[n];
            for(int i = 0; i < n; i++) {
                v[i] = vec.v[i];
            }
        }
    }

    ~Vector() {}

    void nhap()
    {
        for(int i = 0; i < n; i++) {
            cout << "\nNhap gia tri v thu " << i + 1 << ":";
            cin >> v[i];
        }
    }

    void in()
    {
        cout << "[";
        for(int i = 0; i < n; i++) {
            cout << v[i];
            if(i != n - 1) cout << ", ";
        }
        cout << "]\n";
    }

    Vector& operator=(const Vector &vec)
    {
        if(this == &vec) return *this;
        n = vec.n;
        v = nullptr;
        if(n > 0) {
            v = new double[n];
            for(int i = 0; i < n; i++) {
                v[i] = vec.v[i];
            }
        }
        return *this;
    }

    bool kiemTra(const Vector &vec)
    {
        return n == vec.n;
    }

    friend Vector operator+(const Vector &v1, const Vector &v2);
};

Vector operator+(const Vector &v1, const Vector &v2)
{
    Vector res(v1.n);
    for(int i = 0; i < v1.n; i++) {
        res.v[i] = v1.v[i] + v2.v[i];
    }
    return res;
}

int main()
{
    int n;
    cout << "Nhap so phan tu cua vector a: ";
    cin >> n;

    Vector a(n);
    cout << "\nNhap vector a: ";
    a.nhap();

    cout << "\nThong tin vector a: ";
    a.in();

    int n1;
    cout << "Nhap so phan tu cua vector b: ";
    cin >> n1;

    Vector b(n);
    cout << "\nNhap vector b: ";
    b.nhap();

    cout << "\nThong tin vector b: ";
    b.in();

    if(a.kiemTra(b))
    {
        Vector tong = a + b;
        cout << "\nTong cua vector a va b la: ";
        tong.in();
    }
    else
        cout << "Khong cong duoc vi khong cung so phan tu";

    return 0;
}
