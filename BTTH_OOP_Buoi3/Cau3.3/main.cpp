#include <iostream>

using namespace std;

class MatHang {
private:
    string ten;
public:
    virtual void nhap() {
        cout << "Nhap ten mat hang: ";
        cin.ignore();
        getline(cin, ten);
    }
    virtual void xuat() {
        cout << "Ten mat hang: " << ten << endl;
    }
    virtual ~MatHang() {}
};

class MayTinh : public MatHang {
private:
    int speed;
public:
    void nhap() override {
        MatHang::nhap();
        cout << "Nhap speed: ";
        cin >> speed;
    }
    void xuat() override {
        MatHang::xuat();
        cout << "Speed: " << speed << endl;
    }
};

class MayIn : public MatHang {
private:
    int dpi;
public:
    void nhap() override {
        MatHang::nhap();
        cout << "Nhap dpi: ";
        cin >> dpi;
    }
    void xuat() override {
        MatHang::xuat();
        cout << "Dpi: " << dpi << endl;
    }
};


int main()
{
     int n, m;
    cout << "Nhap so luong may tinh: ";
    cin >> n;
    cout << "\nNhap so luong may in: ";
    cin >> m;

    MatHang** a = new MatHang*[n];
    MatHang** b = new MatHang*[m];

    for(int i = 0; i < n; i++) {
        cout << "\nNhap thong tin may tinh" << endl;
        a[i] = new MayTinh();
        a[i]->nhap();
    }
    for(int i = 0; i < n; i++) {
        cout << "\nNhap thong tin may in" << endl;
        b[i] = new MayIn();
        b[i]->nhap();
    }

    for(int i = 0; i < n; i++) {
        cout << "\nThong tin may tinh" << endl;
        a[i]->xuat();
    }
    for(int i = 0; i < n; i++) {
        cout << "\nThong tin may in" << endl;
        a[i]->xuat();
    }

    for(int i = 0; i < n; i++) delete a[i];
    for(int i = 0; i < m; i++) delete b[i];
    delete[] a;
    delete[] b;

    return 0;

    return 0;
}
