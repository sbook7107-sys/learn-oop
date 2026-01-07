#include <iostream>

using namespace std;

class Media {
private:
    string tenGoi;
    double giaBan;
public:
    Media() : tenGoi(""), giaBan(0) {}
    Media(string tg, double gb) : tenGoi(tg), giaBan(gb) {}
    virtual void nhap() {
        cout << "Nhap ten goi: ";
        cin.ignore();
        getline(cin, tenGoi);
        cout << "Nhap gia ban: ";
        cin >> giaBan;
    }
    virtual void xuat() {
        cout << "Ten goi: " << tenGoi;
        cout << "Gia ban: " << giaBan << endl;
    }
};

class Book : public Media {
private:
    int soTrang;
    string tacGia;
public:
    Book() : Media(), soTrang(0), tacGia("") {}
    Book(string tg, double gb, int st, string Tg) :
        Media(tg, gb), soTrang(st), tacGia(Tg) {}
    void nhap() override {
        Media::nhap();
        cout << "Nhap so trang: ";
        cin >> soTrang;
        cin.ignore();
        cout << "Nhap ten tac gia: ";
        getline(cin, tacGia);
    }
    void xuat() override {
        Media::xuat();
        cout << "So trang: " << soTrang;
        cout << "Ten tac gia: " << tacGia;
    }
};

class Video : public Media {
private:
    double thoiGianChay;
public:
    Video() : Media(), thoiGianChay(0) {}
    Video(string tg, double gb, double tgc) :
        Media(tg, gb), thoiGianChay(tgc) {}
    void nhap() override {
        Media::nhap();
        cout << "Nhap thoi gian chay: ";
        cin >> thoiGianChay;
    }
    void xuat() override {
        Media::xuat();
        cout << "Thoi gian chay: " << thoiGianChay << endl;
    }
};

int main()
{
    int n, m;
    cout << "Nhap so luong sach: ";
    cin >> n;
    cout << "\nNhap so luong video: ";
    cin >> m;

    Media** a = new Media*[n];
    Media** b = new Media*[m];

    for(int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sach" << endl;
        a[i] = new Book();
        a[i]->nhap();
    }
    for(int i = 0; i < m; i++) {
        cout << "\nNhap thong tin video" << endl;
        b[i] = new Video();
        b[i]->nhap();
    }

    for(int i = 0; i < n; i++) {
        cout << "\nThong tin sach" << endl;
        a[i]->xuat();
    }
    for(int i = 0; i < m; i++) {
        cout << "\nThong tin video" << endl;
        a[i]->xuat();
    }

    for(int i = 0; i < n; i++) delete a[i];
    for(int i = 0; i < m; i++) delete b[i];
    delete[] a;
    delete[] b;

    return 0;

    return 0;
}
