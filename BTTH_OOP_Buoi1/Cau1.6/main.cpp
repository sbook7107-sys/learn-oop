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

    bool  operator>(const PS &p1)
    {
        return tu * p1.mau > mau * p1.tu;
    }
};

    void sapXepTangDan(PS p[], int n)
    {
        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-1-i; j++) {
                if(p[j] > p[j+1]) {
                    PS tmp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = tmp;
                }
            }
        }
    }

int main()
{
    int n;
    cout << "\nNhap so luong phan tu: ";
    cin >> n;

    PS p[n];
    for(int i = 0; i < n; i++) {
        p[i].nhap();
    }

    sapXepTangDan(p, n);
    cout << "\nMang sau khi sap xep tang dan: ";
    for(int i = 0; i < n; i++) {
        p[i].in();
        cout << " ";
    }

    return 0;
}
