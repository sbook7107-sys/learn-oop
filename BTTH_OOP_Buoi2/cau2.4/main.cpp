#include <iostream>

using namespace std;

class Media {
private:
    string tenGoi;
    double giaBan;
public:
    Media(string t = "", double g = 0) :tenGoi(t), giaBan(g) {}

    void nhap()
    {
        cout << "\nNhap ten goi: ";
        getline(cin, tenGoi);
        cout << "\nGia ban: ";
        cin >> giaBan;
    }

    void hienThi()
    {
        cout << "\nTen goi: " << tenGoi;
        cout << "\nGia ban: " << giaBan;
    }
};

class Book : public Media {
private:
    int soTrang;
    string tacGia;
public:
    Book(int tr = 0, string tg = "", string t = "", double g = 0)
    : Media(t, g), soTrang(tr), tacGia(tg) {}

    void nhap()
    {
        Media::nhap();
        cout << "\nNhap so trang: ";
        cin >> soTrang;
        cin.ignore();
        cout << "\nNhap ten  tac gia: ";
        getline(cin, tacGia);
    }

    void hienThi()
    {
        Media::hienThi();
        cout << "\nSo trang: " << soTrang;
        cout << "\nTen tac gia: " << tacGia;
    }
};

class Video : public Media {
private:
    int thoiGianChay;
public:
    Video(int tgc = 0, string t = "", double g = 0)
    : Media(t, g), thoiGianChay(tgc) {}

    void nhap()
    {
        Media::nhap();
        cout << "\nNhap thoi gian chay: ";
        cin >> thoiGianChay;
    }

    void hienThi()
    {
        Media::hienThi();
        cout << "\nThoi gian chay la: " << thoiGianChay;
    }
};

int main()
{
    int n, m;
    cout << "\nNhap so luong sach: "; cin >> n;
    cout << "\nNhap so luong bang video: "; cin >> m;

    Book b[n];
    Video v[m];

    cout << "\nNhap thong tin doi tuong sach";
    for(int i = 0; i < n; i++) {
        cin.ignore();
        cout << "\nNhap thong tin doi tuong sach thu " << i + 1 << ":";
        b[i].nhap();
    }

    cout << "\nNhap thong tin doi tuong bang video";
    for(int i = 0; i < m; i++) {
        cin.ignore();
        cout << "\nNhap thong tin doi tuong bang video thu " << i + 1 << ":";
        v[i].nhap();
    }

    cout << "\nThong tin doi tuong sach";
    for(int i = 0; i < n; i++) {
        cout << "\nNhap thong tin doi tuong sach thu " << i + 1 << ":";
        b[i].hienThi();
    }

    cout << "\nThong tin doi tuong bang video";
    for(int i = 0; i < m; i++) {
        cout << "\nNhap thong tin doi tuong bang video thu " << i + 1 << ":";
        v[i].hienThi();
    }

    return 0;
}
