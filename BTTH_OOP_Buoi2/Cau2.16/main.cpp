#include <iostream>
#include <string>
using namespace std;

class MyAddress {
private:
    string tinh, huyen;
public:
    MyAddress(string t = "", string h = "") : tinh(t), huyen(h) {}
    ~MyAddress() {}

    void nhap() {
        cin.ignore();
        cout << "\nNhap tinh: ";
        getline(cin, tinh);
        cout << "Nhap huyen: ";
        getline(cin, huyen);
    }

    void hienThi() const {
        cout << "\nTinh: " << tinh;
        cout << "\nHuyen: " << huyen;
    }
};

class MyDate {
private:
    int ngay, thang, nam;
public:
    MyDate(int d = 1, int m = 1, int y = 2000) : ngay(d), thang(m), nam(y) {}
    ~MyDate() {}

    void nhap() {
        cout << "\nNhap ngay: ";
        cin >> ngay;
        cout << "Nhap thang: ";
        cin >> thang;
        cout << "Nhap nam: ";
        cin >> nam;
    }

    void hienThi() const {
        cout << "\nNgay sinh: " << ngay << "/" << thang << "/" << nam;
    }

    bool operator>(const MyDate &other) const {
        if (nam != other.nam) return nam > other.nam;
        if (thang != other.thang) return thang > other.thang;
        return ngay > other.ngay;
    }
};

class Person : public MyDate, public MyAddress {
private:
    string name;
    long phone;
public:
    Person(string ten = "", long sdt = 0,
           int d = 1, int m = 1, int y = 2000,
           string t = "", string h = "")
        : MyDate(d, m, y), MyAddress(t, h), name(ten), phone(sdt) {}

    ~Person() {}

    void nhap() {
        cin.ignore();
        cout << "\nNhap ho ten: ";
        getline(cin, name);
        cout << "Nhap so dien thoai: ";
        cin >> phone;
        MyDate::nhap();
        MyAddress::nhap();
    }

    void hienThi() const {
        cout << "\nHo ten: " << name;
        cout << "\nSo dien thoai: " << phone;
        MyDate::hienThi();
        MyAddress::hienThi();
    }

    MyDate getDate() const {
        return *this;
    }
};

int main() {
    const int n = 4;
    Person *p[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin nguoi thu " << i + 1 << ":\n";
        p[i] = new Person();
        p[i]->nhap();
    }

    for (int i = 0; i < n; i++) {
        p[i]->hienThi();
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i]->getDate() > p[j]->getDate()) {
                swap(p[i], p[j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        p[i]->hienThi();
    }

    for (int i = 0; i < n; i++) {
        delete p[i];
    }

    return 0;
}
