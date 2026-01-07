#include <iostream>

using namespace std;

int ucln(int a, int b)
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

    friend int ucln(int a, int b);

    void rutGon()
    {
        int g = ucln(tu, mau);
        if(g == 0) return;
        tu /= g;
        mau /= g;
        if(mau < 0) {
            mau = -mau;
            tu = -tu;
        }
    }

    bool operator==(const PS &p1)
    {
        return tu * p1.mau == mau * p1.tu;
    }
};

int main()
{
    int n;
    cout << "\nNhap so phan tu: ";
    cin >> n;

    PS p[n];
    for(int i = 0; i <n; i++) {
        p[i].nhap();
        p[i].rutGon();
    }

    PS x;
    cout << "\nNhap phan so x: ";
    x.nhap();

    bool found = false;
    for(int i = 0; i < n; i++) {
         if(p[i] == x) {
            found = true;
            break;
         }
    }
    if(found)
        cout << "\nCo phan so x trong mang";
    else
        cout << "\nKhong co phan so x trong mang";

    return 0;
}
