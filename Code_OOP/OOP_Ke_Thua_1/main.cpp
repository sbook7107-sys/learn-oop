#include <iostream>
#include <string>
using namespace std;

/*
class Media {
private:
    string tenGoi;
    double giaBan;
public:
    Media(string tg, double gb) {
        tenGoi = tg;
        giaBan = gb;
    }
    void nhap() {
        cout << "\nNhap ten goi: ";
        getline(cin, tenGoi);
        cout << "\nNhap gia ban: ";
        cin >> giaBan;
    }
    void xuat() {
        cout << "Ten goi: " << tenGoi;
        cout << "\nGia ban: " << giaBan << endl;
    }
};

class Book : public Media {
private:
    int soTrang;
    string tacGia;
public:
    Book(string tenGoi, double giaBan, int st, string tG)
    : Media(tenGoi, giaBan) {
        soTrang = st;
        tacGia = tG;
    }
    void nhap() {
        Media::nhap();
        cout << "\nNhap so trang: ";
        cin >> soTrang;
        cout << "\nNhap tac gia: ";
        getline(cin, tacGia);
    }
    void xuat() {
        Media::xuat();
        cout << "So trang: " << soTrang;
        cout << "\nTac gia: " << tacGia << endl;
    }
};

class Video : public Media {
private:
    int thoiGianChay;
public:
    Video(string tenGoi, double giaBan, int tgc)
    : Media(tenGoi, giaBan) {
        thoiGianChay = tgc;
    }
    void nhap() {
        Media::nhap();
        cout << "\nNhap thoi gian chay: ";
        cin >> thoiGianChay;
    }
    void xuat() {
        Media::xuat();
        cout << "Thoi gian chay (phut): " << thoiGianChay << endl;
    }
};

int main()
{
    Media m1("Lap trinh C++", 50000);
    Book b1("Lap trinh C++", 50000, 200, "Nguyen Van A");
    Video v1("Lap trinh C++", 50000, 30);

    m1.xuat();
    cout << endl;
    b1.xuat();
    cout << endl;
    v1.xuat();

    return 0;
}
*/



class Media {
private:
    string tenGoi;
    double giaBan;
public:
    Media(string tg, double gb) {
        tenGoi = tg;
        giaBan = gb;
    }
    virtual void nhap() {
        cout << "\nNhap ten goi: ";
        getline(cin, tenGoi);
        cout << "\nNhap gia ban: ";
        cin >> giaBan;
    }
    virtual void xuat() {
        cout << "Ten goi: " << tenGoi;
        cout << "\nGia ban: " << giaBan << endl;
    }
};

class Book : public Media {
private:
    int soTrang;
    string tacGia;
public:
    Book(string tenGoi, double giaBan, int st, string tG)
    : Media(tenGoi, giaBan) {
        soTrang = st;
        tacGia = tG;
    }
    void nhap() override {
        Media::nhap();
        cout << "\nNhap so trang: ";
        cin >> soTrang;
        cout << "\nNhap tac gia: ";
        getline(cin, tacGia);
    }
    void xuat() override {
        Media::xuat();
        cout << "So trang: " << soTrang;
        cout << "\nTac gia: " << tacGia << endl;
    }
};

class Video : public Media {
private:
    int thoiGianChay;
public:
    Video(string tenGoi, double giaBan, int tgc)
    : Media(tenGoi, giaBan) {
        thoiGianChay = tgc;
    }
    void nhap() override {
        Media::nhap();
        cout << "\nNhap thoi gian chay: ";
        cin >> thoiGianChay;
    }
    void xuat() override {
        Media::xuat();
        cout << "Thoi gian chay (phut): " << thoiGianChay << endl;
    }
};

int main()
{
    Media m1("Lap trinh C++", 50000);
    Book b1("Lap trinh C++", 50000, 200, "Nguyen Van A");
    Video v1("Lap trinh C++", 50000, 30);

    Media *p1, *p2;
    p1 = &b1;
    b1.xuat();
    cout << endl;

    p2 = &v1;
    v1.xuat();

    return 0;
}
