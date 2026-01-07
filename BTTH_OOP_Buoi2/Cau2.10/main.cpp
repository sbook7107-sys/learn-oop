#include <iostream>
#include <cmath>
using namespace std;

class MyColor {
private:
    int color;
public:
    MyColor(int sh = 0) : color(sh) {}

    void nhapMau()
    {
        cout << "\nNhap so hieu mau: ";
        cin >> color;
    }

    void hienThiMau()
    {
        cout << "\nSo hieu mau la: " << color;
    }
};

class Point {
private:
    int x, y;
public:
    Point(int tdx = 0, int tdy = 0) : x(tdx), y(tdy) {}

    void nhap()
    {
        cout << "\nNhap x: "; cin >> x;
        cout << "\nNhap y: "; cin >> y;
    }

    void hienThi()
    {
        cout << "\nThong tin toa do";
        cout << "(" << x << ", " << y << ")";
    }

    friend float tinhKhoangCach(Point &p1, Point &p2);
};

float tinhKhoangCach(Point &p1, Point &p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

class Line : public MyColor {
private:
    Point A, B;
public:
    void nhap()
    {
        cout << "\nNhap diem A: "; A.nhap();
        cout << "\nNhap diem B: "; B.nhap();
        nhapMau();
    }

    void hienThi()
    {
        cout << " "; A.hienThi();
        cout << " "; B.hienThi();
        cout << "\nMau: "; hienThiMau();
        cout << "\nChieu dai: " << tinhKhoangCach(A, B) << endl;
        cout << endl;
    }
};

int main()
{
    Line l;
    cout << "Nhap thong tin";
    l.nhap();
    cout << "\nThong tin sau khi nhap";
    l.hienThi();

    return 0;
}
