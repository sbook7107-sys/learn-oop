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
        cout << "Nhap mau so: ";
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

    friend bool operator>=(const PS &p1, const PS &p2);
};

bool operator>=(const PS &p1, const PS &p2)
{
    long long l = (long long)p1.tu * p2.mau;
    long long r = (long long)p2.tu * p1.mau;
    return l >= r;
}

int main()
{
    PS p[5];
    for(int i = 0; i < 5; i++) {
        p[i].nhap();
        p[i].rutGon();
    }

    int max = 0, min = 0;
    for(int i = 1; i < 5; i++) {
        if(p[i] >= p[max])
            max = i;
        if(p[min] >= p[i])
            min = i;
    }

    cout << "\nPhan so lon nhat: ";
    p[max].in();
    cout << "\nPhan so nho nhat: ";
    p[min].in();

    return 0;
}
