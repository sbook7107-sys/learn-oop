#include <iostream>

using namespace std;

class Printer {
private:
    string name;
    int soLuong;
public:
    Printer(string n = "", int sl = 0) : name(n), soLuong(sl) {}

    int nhapKho(int q) {return soLuong += q;}

    void xuatKho(int q)
    {
        if(q <= soLuong) soLuong -= q;
        else
            cout << "\nSo luong khong hop le";
    }

    void nhap()
    {
        cin.ignore();
        cout << "\nNhap ten may in: ";
        getline(cin, name);
        cout << "\nNhap so luong: ";
        cin >> soLuong;
    }

    void hienThi()
    {
        cout << "\nTen may in: " << name;
        cout << "\nSo luong: " << soLuong;
    }

};

class Laser : public Printer {
private:
    int dPI;
public:
    Laser(int dpi = 0, string n = "", int sl = 0)
    : Printer(n, sl), dPI(dpi) {}

    void nhap()
    {
        Printer::nhap();
        cout << "\nNhap dpi: ";
        cin >> dPI;
    }

    void hienTHi()
    {
        Printer::hienThi();
        cout << "\nDPI: " << dPI;
    }

};

class ColorPrinter : public Printer {
private:
    string color;
public:
    ColorPrinter(string mau = "", string n = "", int sl = 0)
    : Printer(n, sl), color(mau) {}

    void nhap()
    {
        cin.ignore();
        cout << "\nNhap mau: ";
        getline(cin, color);
    }

    void hienThi()
    {
        cout << "\nMau: " << color;
    }
};

class ColorLaser : public Laser, public ColorPrinter {
private:
    string moTa;
public:
    ColorLaser(string mt = "", int dpi = 0, string n = "", int sl = 0, string mau = "")
    : Laser(dpi, n, sl), ColorPrinter(mau, n, sl), moTa(mt) {}
    void nhap()
    {
        Laser::nhap();
        ColorPrinter::nhap();
        cout << "\nNhap mo ta: ";
        getline(cin, moTa);
    }

    void hienThi()
    {
        Laser::hienThi();
        ColorPrinter::hienThi();
        cout << "\nMo ta: " << moTa;
    }
};

int main()
{
    ColorLaser c[3];

    cout << "\nNhap thong tin 3 doi tuong may in";
    for(int i = 0; i < 3; i++) {
        cin.ignore();
        cout << "\nNhap may in thu " << i + 1 << ":";
        c[i].nhap();
    }

    cout << "\nThong tin 3 doi tuong may in sau khi nhap";
    for(int i = 0; i < 3; i++) {
        cout << "\nThong tin may in thu " << i + 1 << ":";
        c[i].hienThi();
    }

    return 0;
}
