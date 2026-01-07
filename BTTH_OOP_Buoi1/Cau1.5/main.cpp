#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

class PS {
private:
    int tu, mau;
public:
    PS() : tu(0), mau(1) {}
    PS(int t, int m) : tu(t), mau(m) {}

    void nhap()
    {
        cout << "\nNhap tu so: ";
        cin >> tu;
        cout << "\nNhap mau so: ";
        cin >> mau;
    }

    void in()
    {
        cout << tu << "/" << mau;
    }

    void rutGon()
    {
        int g = gcd(tu, mau);
        if(g == 0) return;
        tu /= g;
        mau /= g;
        if(mau < 0) {
            mau = -mau;
            tu = -tu;
        }
    }

    PS  operator+(const PS &p1)
    {
        int t = tu * p1.mau + mau * p1.tu;
        int m = mau * p1.mau;
        PS r(t, m);
        r.rutGon();
        return r;
    }

    PS  operator-(const PS &p1)
    {
        int t = tu * p1.mau - mau * p1.tu;
        int m = mau * p1.mau;
        PS r(t, m);
        r.rutGon();
        return r;
    }

    PS  operator*(const PS &p1)
    {
        int t = tu * p1.tu;
        int m = mau * p1.mau;
        PS r(t, m);
        r.rutGon();
        return r;
    }

    PS  operator/(const PS &p1)
    {
        int t = tu * p1.mau;
        int m = mau * p1.tu;
        PS r(t, m);
        r.rutGon();
        return r;
    }
};

int main()
{
    int n;
    cout << "\nNhap so luong phan tu: ";
    cin >> n;

    PS p[n];
    for(int i = 0; i < n; i++) {
        p[i].nhap();
    }

    PS tong;
    for(int i = 0; i < n; i++) {
        tong = tong + p[i];
    }

    cout << "\nTong cua cac phan so la: ";
    tong.in();
    cout << endl;

    return 0;
}
