#include <iostream>
using namespace std;

class MyTime {
private:
    int gio, phut, giay;
public:
    MyTime(int g = 0, int p = 0, int s = 0)
        : gio(g), phut(p), giay(s) {}

    void nhap() {
        cout << "\nNhap gio: ";  cin >> gio;
        cout << "Nhap phut: ";   cin >> phut;
        cout << "Nhap giay: ";   cin >> giay;
    }

    void hienThi() const {
        cout << gio << ":"
             << (phut < 10 ? "0" : "") << phut << ":"
             << (giay < 10 ? "0" : "") << giay;
    }
};

class MyDate {
private:
    int ngay, thang, nam;
public:
    MyDate(int d = 1, int m = 1, int y = 2000)
        : ngay(d), thang(m), nam(y) {}

    void nhap() {
        cout << "\nNhap ngay: ";  cin >> ngay;
        cout << "Nhap thang: ";   cin >> thang;
        cout << "Nhap nam: ";     cin >> nam;
    }

    void hienThi() const {
        cout << ngay << "-" << thang << "-" << nam;
    }
};

class DateTime : public MyDate, public MyTime {
public:
    DateTime(int d = 1, int m = 1, int y = 2000,
             int g = 0, int p = 0, int s = 0)
        : MyDate(d, m, y), MyTime(g, p, s) {}

    void nhap() {
        cout << "\nNhap ngay gio";
        MyDate::nhap();
        MyTime::nhap();
    }

    void hienThi() const {
        cout << "\nThoi gian: ";
        MyDate::hienThi();
        cout << " ";
        MyTime::hienThi();
    }
};

int main() {
    const int n = 3;
    DateTime dt[n];

    for (int i = 0; i < n; i++) {
        cout << "Doi tuong thu " << i + 1 << ":";
        dt[i].nhap();
    }

    for (int i = 0; i < n; i++) {
        cout << "\nDoi tuong thu " << i + 1 << ":";
        dt[i].hienThi();
    }

    cout << endl;
    return 0;
}
