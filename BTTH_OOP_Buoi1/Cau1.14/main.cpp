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

    bool operator==(const MyDate &m1)
    {
        return ngay == m1.ngay && thang == m1.thang && nam == m1.nam;
    }
};

int main()
{
    MyDate m[5];
    for(int i = 0; i < 5; i++) {
        m[i].nhap();
    }

    cout << endl;

    MyDate x;
    cout << "\nNhap gia tri x kieu MyDate: ";
    x.nhap();

    bool found = false;
    for(int i = 0; i < 5; i++) {
       if(m[i] == x) {
        found = true;
        break;
       }
    }
    if(found)
        cout << "\nCo gia tri x";
    else
        cout << "\nKhong co gia tri x";

    return 0;
}
