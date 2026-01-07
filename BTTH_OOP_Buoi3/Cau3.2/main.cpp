#include <iostream>

using namespace std;

class SV {
private:
    string lop, hoTen;
public:
    virtual void nhap() {
        cout << "\nNhap lop: ";
        cin.ignore();
        getline(cin, lop);
        cout << "\nNhap ho ten: ";
        getline(cin, hoTen);
    }
    virtual void xuat() {
        cout << "\nHo ten: " << hoTen;
        cout << "\nLop: " << lop << endl;
    }
    virtual ~SV() {}
};

class SVSP : public SV {
private:
    double hocBong;
public:
    void nhap() override {
        cout << "\nNhap thong tin SVSP" << endl;
        SV::nhap();
        cout << "\nNhap hoc bong: ";
        cin >> hocBong;
    }
    void xuat() override {
        SV::xuat();
        cout << "\nHoc bong: " << hocBong << endl;
    }
};

class SVTC : public SV {
private:
    double hocPhi;
public:
    void nhap() override {
        SV::nhap();
        cout << "\nNhap hoc phi: ";
        cin >> hocPhi;
    }
    void xuat() override {
        SV::xuat();
        cout << "\nHoc phi: " << hocPhi << endl;
    }
};

int main()
{
    int n, m;
    cout << "Nhap so luong SVSP: ";
    cin >> n;
    cout << "\nNhap so luong SVTC: ";
    cin >> m;

    SV** a = new SV*[n];
    SV** b = new SV*[m];

    for(int i = 0; i < n; i++) {
        cout << "\nNhap thong tin SVSP" << endl;
        a[i] = new SVSP();
        a[i]->nhap();
    }
    for(int i = 0; i < n; i++) {
        cout << "\nNhap thong tin SVTC" << endl;
        b[i] = new SVTC();
        b[i]->nhap();
    }

    for(int i = 0; i < n; i++) {
        cout << "\nThong tin SVSP" << endl;
        a[i]->xuat();
    }
    for(int i = 0; i < n; i++) {
        cout << "\nThong tin SVSP" << endl;
        a[i]->xuat();
    }

    for(int i = 0; i < n; i++) delete a[i];
    for(int i = 0; i < m; i++) delete b[i];
    delete[] a;
    delete[] b;

    return 0;
}
