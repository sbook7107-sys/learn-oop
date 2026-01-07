#include <iostream>

using namespace std;

class Shape {
public:
    virtual double tinhDT() {return 0;}
    virtual void nhap() {}
    virtual void xuat() {cout << "" << tinhDT() << endl; }
};

class Circle : public Shape {
private:
    double r;
public:
    Circle() {r = 0;}
    void nhap() override {
        cout << "\nNhap ban kinh: ";
        cin >> r;
    }
    double tinhDT() override {
        return 3.1415 * r * r;
    }
    void xuat() override {
        cout << "\nDien tich hinh tron la: "
        << tinhDT() << endl;
    }
};

class Rectangle : public Shape {
private:
    double cd, cr;
public:
    Rectangle() {cd = cr = 0;}
    void nhap() override {
        cout << "\nNhap chieu dai: ";
        cin >> cd;
        cout << "\nNhap chieu rong: ";
        cin >> cr;
    }
    double tinhDT() override {
        return cd * cr;
    }
    void xuat() override {
        cout << "\nDien tich hcn: "
        << tinhDT() << endl;
    }
};

int main()
{
    int n, m;
    cout << "Nhap so luong hinh tron: ";
    cin >> n;
    cout << "\nNhap so luong hcn: ";
    cin >> m;

    Shape** c = new Shape*[n];
    Shape** t = new Shape*[m];

    cout << "\nNhap thong tin hinh tron" << endl;
    for(int i = 0; i < n; i++) {
        c[i] = new Circle();
        c[i]->nhap();
    }

    cout << "\nNhap thong tin hcn" << endl;
    for(int i = 0; i < m; i++) {
        t[i] = new Rectangle();
        t[i]->nhap();
    }

    cout << "\nThong tin hinh tron" << endl;
    for(int i = 0; i < n; i++) {
        c[i]->xuat();
    }

    cout << "\nThong tin hcn" << endl;
    for(int i = 0; i < m; i++) {
        t[i]->xuat();
    }

    for(int i = 0; i < n; i++) delete c[i];
    for(int i = 0; i < m; i++) delete t[i];

    delete[] c;
    delete[] t;

    return 0;
}
