#include <iostream>

using namespace std;

class MyAddress {
private:
    string tinh, huyen;
public:
    MyAddress(string t = "", string h = "") : tinh(t), huyen(h) {}
    ~MyAddress() {}

    void nhap()
    {
        cin.ignore();
        cout << "\nNhap tinh: ";
        getline(cin, tinh);
        cout << "\nNhap huyen: ";
        getline(cin, huyen);
    }

    void hienThi()
    {
        cout << "\nTinh: " << tinh;
        cout << "\nHuyen: " << huyen;
    }
};

class Person : public MyAddress {
private:
    string name;
    int phone;
public:
    Person(string ten = "", int sdt = 0, string t = "", string h = "")
    : MyAddress(t, h), name(ten), phone(sdt) {}

    void nhap()
    {
        cin.ignore();
        cout << "\nNhap ho ten: ";
        getline(cin, name);
        cout << "\nNhap so dien thoai: ";
        cin >> phone;
        MyAddress::nhap();
    }

    void hienThi()
    {
        cout << "\nHo ten: " << name;
        cout << "\nSo dien thoai: " << phone;
        MyAddress::hienThi();
    }
};

class Officer : public Person {
private:
    double salary;
public:
    Officer(double luong = 0, string ten = "", int sdt = 0, string t = "", string h = "")
    : Person(ten, sdt, t, h), salary(luong) {}

    void nhap()
    {
        Person::nhap();
        cout << "\nNhap luong: ";
        cin >> salary;
    }

    void hienThi()
    {
        Person::hienThi();
        cout << "\nLuong: " << salary << endl;
    }

    double getLuong() const {return salary;}
};

int main()
{
    const int n = 4;
    Officer *o[n];

    cout << "Nhap thong tin 4 doi tuong";
    for(int i = 0; i < n; i ++) {
        cin.ignore();
        cout << "\nNhap thong tin doi tuong thu " << i + 1 << ":";
        o[i] = new Officer();
        o[i]->nhap();
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(o[i]->getLuong() > o[j]->getLuong())
                swap(o[i], o[j]);
        }
    }

    cout << "\nThong tin 4 doi tuong truoc sap xep";
    for(int i = 0; i < n; i ++) {
        cout << "\nThong tin doi tuong thu " << i + 1 << ":";
        o[i]->hienThi();
    }

    cout << "\nThong tin 4 doi tuong truoc sap xep";
    for(int i = 0; i < n; i ++) {
        cout << "\nThong tin doi tuong thu " << i + 1 << ":";
        o[i]->hienThi();
    }

    return 0;
}
