#include <iostream>
using namespace std;

class MyAttr {
private:
    int attr;
public:
    MyAttr(int a = 0) : attr(a) {}

    void nhap()
    {
        cout << "\nNhap so hieu: ";
        cin >> attr;
    }

    void hienThi()
    {
        cout << "\nSo hieu: " << attr << endl;
    }
};

class MyDate {
private:
    int ngay, thang, nam;
public:
    MyDate(int d = 1, int m = 1, int y = 2000) :
        ngay(d), thang(m), nam(y) {}

    bool operator >(const MyDate& m1)
    {
        if(nam > m1.nam) return nam > m1.nam;
        if(thang > m1.thang) return thang > m1.thang;
        return ngay > m1.ngay;
    }

    void nhap()
    {
        cout << "\nNhap ngay thang nam: ";
        cin >> ngay >> thang >> nam;
    }

    void hienThi()
    {
        cout << "\nNgay-thang-nam: ";
        cout << ngay << "-" << thang << "-" << nam;
    }

    MyDate getDate() const {return *this;}
};

class MyFile : public MyAttr, public MyDate {
private:
    string fileName;
    int fileSize;
public:
    MyFile(string ten = "", int kichThuoc = 0, int a = 0, int d = 1, int m = 1, int y  = 200)
    : MyAttr(a), MyDate(d, m, y), fileName(ten), fileSize(kichThuoc) {}

    void nhap()
    {
        cin.ignore();
        cout << "\nNhap ten file: ";
        getline(cin, fileName);
        cout << "\nNhap kich thuoc: ";
        cin >> fileSize;
        MyDate::nhap();
        MyAttr::nhap();
    }

    void hienThi()
    {
        cout << "\nThong tin: " << fileName;
        cout << "\nKich thuoc: " << fileSize;
        MyDate::hienThi();
        MyAttr::hienThi();
    }
};

int main() {
    const int n = 4;
    MyFile *m[n];

    cout << "Nhap thong tin cac phan tu";
    for(int i = 0; i < n; i++) {
        cin.ignore();
        cout << "\nNhap thong tin phan tu thu " << i + 1 << ":";
        m[i] = new MyFile();
        m[i]->nhap();
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(m[i]->getDate() > m[j]->getDate()) {
                swap(m[i], m[j]);
            }
        }
    }

    cout << "\nThong tin cac doi tuong truoc sap xep";
    for(int i = 0; i < n; i++) {
        cout << "\nThong tin phan tu thu " << i + 1 << ":";
        m[i]->hienThi();
    }

    cout << "\nThong tin cac doi tuong sau sap xep";
    for(int i = 0; i < n; i++) {
        cout << "\nThong tin phan tu thu " << i + 1 << ":";
        m[i]->hienThi();
    }

    return 0;
}
