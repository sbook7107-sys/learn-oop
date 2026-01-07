#include <iostream>

using namespace std;

class MyDate {
private:
    int ngay, thang, nam;
public:
    MyDate() : ngay(1), thang(1), nam(1900) {}
    MyDate(int d, int m, int y) : ngay(d), thang(m), nam(y) {}

    void nhap()
    {
        cout << "\nNhap ngay: ";
        cin >> ngay;
        cout << "Nhap thang: ";
        cin >> thang;
        cout << "Nhap nam: ";
        cin >> nam;
    }

    void in()
    {
        cout << ngay << "-" << thang << "-" << nam;
    }

    friend bool operator>=(const MyDate &m1, const MyDate &m2);
};

bool operator>=(const MyDate &m1, const MyDate &m2)
{
    if(m1.nam != m2.nam) return m1.nam > m2.nam;
    if(m1.thang != m2.thang) return m1.thang > m2.thang;
    return m1.ngay >= m2.ngay;
}

int main()
{
    MyDate m[5];
    for(int i = 0; i < 5; i++) {
        m[i].nhap();
    }

    int k = 0;
    for(int i = 1; i < 5; i++) {
        if(m[i] >= m[k])
            k = i;
    }
    cout << "\nThoi gian lon nhat la: ";
    m[k].in();
    cout << endl;

    return 0;
}
