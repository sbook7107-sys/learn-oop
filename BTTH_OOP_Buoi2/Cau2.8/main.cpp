#include <iostream>
using namespace std;

class MyTime {
private:
    int gio, phut, giay;
public:
    MyTime(int g = 0, int p = 0, int s = 0) : gio(g), phut(p), giay(s) {}

    void nhap()
    {
        cout << "\nNhap gio: "; cin >> gio;
        cout << "\nNhap phut: "; cin >> phut;
        cout << "\nNhap giay: "; cin >> giay;
    }

    void hienThi()
    {
        cout << "\nThong tin gio:phut:giay la: ";
        cout << gio << ":" << phut << ":" << giay;
    }
};

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
        cout << "\nNgay-thang-nam: ";
        cout << ngay << "-" << thang << "-" << nam;
    }
};

class MyFile : public MyTime, public MyDate {
private:
    string fileName;
    int fileSize;
public:
    MyFile(string ten = "", int kichThuoc = 0, int g = 0, int p = 0, int s = 0, int d = 1, int m = 1, int y  = 200)
    : MyTime(g, p, s), MyDate(d, m, y), fileName(ten), fileSize(kichThuoc) {}

    void nhap()
    {
        cin.ignore();
        cout << "\nNhap ten file: ";
        getline(cin, fileName);
        cout << "\nNhap kich thuoc: ";
        cin >> fileSize;
        MyDate::nhap();
        MyTime::nhap();
    }

    void hienThi()
    {
        cout << "\nThong tin: " << fileName;
        cout << "\nKich thuoc: " << fileSize;
        MyDate::hienThi();
        MyTime::hienThi();
    }

    int getKichThuoc() const {return fileSize;}
};

int main() {
    const int n = 5;
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
            if(m[i]->getKichThuoc() < m[j]->getKichThuoc()) {
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
