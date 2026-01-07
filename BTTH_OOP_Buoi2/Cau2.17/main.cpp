#include <iostream>
#include <string>
using namespace std;

class Printer {
protected:
    string soHieu;
    int soLuong;
public:
    Printer(string sh = "", int sl = 0)
        : soHieu(sh), soLuong(sl) {}

    void nhapKho(int q) {
        soLuong += q;
    }

    void xuatKho(int q) {
        if (q <= soLuong)
            soLuong -= q;
        else
            cout << "\nSo luong khong hop le!";
    }

    virtual void nhap() {
        cin.ignore();
        cout << "\nNhap so hieu may in: ";
        getline(cin, soHieu);
        cout << "Nhap so luong may in: ";
        cin >> soLuong;
    }

    virtual void hienThi() const {
        cout << "\nSo hieu: " << soHieu;
        cout << "\nSo luong: " << soLuong;
    }

    int getSoLuong() const {
        return soLuong;
    }
};

class Laser : public virtual Printer {
protected:
    int dpi;
public:
    Laser(int d = 0, string sh = "", int sl = 0)
        : Printer(sh, sl), dpi(d) {}

    void nhap() override {
        Printer::nhap();
        cout << "Nhap DPI: ";
        cin >> dpi;
    }

    void hienThi() const override {
        Printer::hienThi();
        cout << "\nDPI: " << dpi;
    }
};

class ColorPrinter : public virtual Printer {
protected:
    string color;
public:
    ColorPrinter(string c = "", string sh = "", int sl = 0)
        : Printer(sh, sl), color(c) {}

    void nhap() override {
        Printer::nhap();
        cin.ignore();
        cout << "Nhap mau: ";
        getline(cin, color);
    }

    void hienThi() const override {
        Printer::hienThi();
        cout << "\nMau: " << color;
    }
};

class ColorLaser : public Laser, public ColorPrinter {
public:
    ColorLaser(string c = "", int d = 0, string sh = "", int sl = 0)
        : Printer(sh, sl), Laser(d, sh, sl), ColorPrinter(c, sh, sl) {}

    void nhap() override {
        Printer::nhap();
        cout << "Nhap DPI: ";
        cin >> dpi;
        cin.ignore();
        cout << "Nhap mau: ";
        getline(cin, color);
    }

    void hienThi() const override {
        Printer::hienThi();
        cout << "\nDPI: " << dpi;
        cout << "\nMau: " << color;
    }
};

int main() {
    const int n = 3;
    ColorLaser cl[n];

    for (int i = 0; i < n; i++) {
        cout << "\nMay in thu " << i + 1 << ":";
        cl[i].nhap();
    }

    for (int i = 0; i < n; i++) {
        cout << "\n\nMay in thu " << i + 1 << ":";
        cl[i].hienThi();
    }

    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += cl[i].getSoLuong();
    }
    cout << "\nTong so luong tat ca may in trong kho: " << tong << endl;

    return 0;
}
