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

    friend Vector operator*(double k, const Vector &vec);
};

Vector operator*(double k, const Vector &vec)
{
    Vector res(vec.n);
    for(int i = 0; i < vec.n; i++) {
        res.v[i] = k * vec.v[i];
    }
    return res;
}

int main()
{
    int k;
    cout << "Nhap k: ";
    cin >> k;

    int n;
    cout << "Nhap so phan tu cua vector a: ";
    cin >> n;

    Vector a(n);
    cout << "\nNhap vector a: ";
    a.nhap();

    cout << "\nThong tin vector a: ";
    a.in();

    Vector tich = k * a;
    cout << "\nTich cua k va vector a la: ";
    tich.in();
    return 0;
}
