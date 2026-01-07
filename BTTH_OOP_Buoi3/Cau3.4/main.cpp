#include <iostream>

using namespace std;

class Printer {
private:
    string name;
public:
    virtual void nhap() {
        cout << "Nhap ten may in: ";
        cin.ignore();
        getline(cin, name);
    }
    virtual void xuat() {
        cout << "Ten may in: " << name << endl;
    }
    bool operator> (Printer& p1) {
        return name > p1.name;
    }
    virtual ~Printer() {}
};

class Laser : public Printer {
private:
    int dpi;
public:
    void nhap() override {
        Printer::nhap();
        cout << "Nhap dpi: ";
        cin >> dpi;
    }
    void xuat() override {
        Printer::xuat();
        cout << "Dpi: " << dpi << endl;
    }
    int getDpi() {return dpi;}
    void setDpi(int Dpi) {Dpi = dpi;}
};

class ColorLaser : public Laser {
private:
    string color;
public:
    void nhap() override {
        Laser::nhap();
        cin.ignore();
        cout << "Nhap loai mau: ";
        getline(cin, color);
    }
    void xuat() override {
        Printer::xuat();
        cout << "Dpi: " << getDpi();
        cout << "Loai mau: " << color << endl;
    }
};

int main()
{
    int n, m;
    cout << "Nhap so luong may Laser: ";
    cin >> n;
    cout << "\nNhap so luong may ColorLaser: ";
    cin >> m;

    Printer** a = new Printer*[n];
    Printer** b = new Printer*[m];

    for(int i = 0; i < n; i++) {
        cout << "\nNhap thong tin may Laser" << endl;
        a[i] = new Laser();
        a[i]->nhap();
    }
    for(int i = 0; i < m; i++) {
        cout << "\nNhap thong tin may ColorLaser" << endl;
        b[i] = new ColorLaser();
        b[i]->nhap();
    }

    for(int i = 0; i < n; i++) {
        cout << "\nThong tin may Laser" << endl;
        a[i]->xuat();
    }
    for(int i = 0; i < m; i++) {
        cout << "\nThong tin may ColorLaser" << endl;
        a[i]->xuat();
    }

    for(int i = 0; i < n; i++) delete a[i];
    for(int i = 0; i < m; i++) delete b[i];
    delete[] a;
    delete[] b;

    return 0;

    return 0;
}
