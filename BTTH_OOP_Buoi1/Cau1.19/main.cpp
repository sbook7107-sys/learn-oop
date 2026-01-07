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

    bool operator>=(const PS &p1) {
        return tu * p1.mau >= mau * p1.tu;
    }
};

int main()
{
    PS p[5];
    for(int i = 0; i < 5; i++) {
        p[i].nhap();
        p[i].rutGon();
    }

    int max = 0;
    for(int i = 0; i < 5; i++) {
        if(p[i] >= p[max])
            max = i;
    }
    cout << "\nPhan so lon nhat la: ";
    p[max].in();
    cout << endl;

    return 0;
}
