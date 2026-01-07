#include <iostream>

using namespace std;

class MyTime {
private:
    int gio, phut, giay;
public:
    MyTime() : gio(0), phut(0), giay(0) {}
    MyTime(int h, int m, int s) : gio(h), phut(m), giay(s) {}

    void nhap()
    {
        cout << "\nNhap gio: ";
        cin >> gio;
        cout << "Nhap phut: ";
        cin >> phut;
        cout << "Nhap giay: ";
        cin >> giay;
    }

    void in()
    {
        cout << gio << ":" << phut << ":" << giay;
    }

    friend bool operator>=(const MyTime &m1, MyTime &m2);
};


bool operator>=(const MyTime &m1, const MyTime &m2) {
    if(m1.gio > m2.gio) return true;
    if(m1.gio < m2.gio) return false;
    if(m1.phut > m2.phut) return true;
    if(m1.phut < m2.phut) return false;
    returrn m1.giay >= m2.giay;
}

int main()
{
    MyTime m[5];
    for(int i = 0; i < n; i++) {
        m.nhap();
    }

    int max = 0, min = 0;
    for(int i = 1; i < 5; i++) {
        if(m[i] >= m[max])
            max = i;
        if(m[min] >= m[i])
            min = i;
    }

    cout << "\nThoi gian lon nhat: ";
    m[max].in();
    cout << "\nThoi gian be nhat: ";
    m[min].in();

    return 0;
}
