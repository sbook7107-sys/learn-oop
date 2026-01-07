#include <iostream>
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
};

class Laser : public Printer {
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

class ColorLaser : public Laser {
private:
    int soMau;
public:
    ColorLaser(int sm = 0, int d = 0, string sh = "", int sl = 0)
        : Laser(d, sh, sl), soMau(sm) {}

    void nhap() override {
        Laser::nhap();
        cout << "Nhap so mau: ";
        cin >> soMau;
    }

    void hienThi() const override {
        Laser::hienThi();
        cout << "\nSo mau: " << soMau;
    }
};

int main() {
    ColorLaser cl[2];

    for (int i = 0; i < 2; i++) {
        cout << "Nhap may in thu " << i + 1 << ":";
        cl[i].nhap();
    }

    for (int i = 0; i < 2; i++) {
        cout << "\n\nMay in thu " << i + 1 << ":";
        cl[i].hienThi();
    }

    return 0;
}
