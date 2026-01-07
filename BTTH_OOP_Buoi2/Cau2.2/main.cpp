#include <iostream>

using namespace std;

class MyDate {
private:
    int ngay, thang, nam;
public:
    MyDate(int d = 1, int m = 1, int y = 2000) :
        ngay(d), thang(m), nam(y) {}

    void nhap()
    {
        cout << "\nNhap ngay thang nam: ";
        cin >> ngay >> thang >> nam;
    }

    void hienThi()
    {
        cout << "\nNgay-thang-nam: " << endl;
        cout << ngay << "-" << thang << "-" << nam;
    }

    bool operator >(const MyDate& m1)
    {
        if(nam > m1.nam) return nam > m1.nam;
        if(thang > m1.thang) return thang > m1.thang;
        return ngay > m1.ngay;
    }

    MyDate getDate()const {return *this;}
};

class Person : public MyDate {
private:
    string name;
    string address;
    int phone;
public:
    Person(string ten = "", string diaChi = "", int sdt = 0, int d = 1, int m = 1, int y = 2000)
    : MyDate(d, m, y), name(ten), address(diaChi), phone(sdt) {}

    void nhap()
    {
        cin.ignore();
        cout << "\nNhap ho ten: ";
        getline(cin, name);
        cout << "\nNhap dia chi: ";
        getline(cin, address);
        cout << "\nNhap so dien thoai: ";
        cin >> phone;
        MyDate::nhap();
    }

    void hienThi()
    {
        cout << "\nHo ten: " << name;
        cout << "\nDia chi: " << address;
        cout << "\nSo dien thoai: " << phone;
        MyDate::hienThi();
    }
};

class Officer : public Person {
private:
    double salary;
public:
    Officer(double luong = 0, string ten = "", string diaChi = "", int sdt = 0, int d = 1, int m = 1, int y = 2000)
    : Person(ten, diaChi, sdt, d, m, y), salary(luong) {}

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
};

int main()
{
    const int n = 4;
    Officer *o[n];

    cout << "Nhap thong tin 4 doi tuong";
    for(int i = 0; i < n; i ++) {
        cout << "\nNhap thong tin doi tuong thu " << i + 1 << ":";
        o[i] = new Officer();
        o[i]->nhap();
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(o[i]->getDate() > o[j]->getDate())
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
