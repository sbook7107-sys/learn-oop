#include <iostream>

using namespace std;

class MyColor {
private:
    int color;
public:
    MyColor(int sh = 0) : color(sh) {}

    void nhap()
    {
        cout << "\nNhap so hieu mau: ";
        cin >> color;
    }

    void hienThiColor()
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

    void tinhTien(int dx, int dy)
    {
        x += dx;
        y += dy;
    }
};

class Triangle : public MyColor {
private:
    Point A, B, C;
public:
    Triangle(Point X, Point Y, Point Z, int k)
    : MyColor(k), A(X), B(Y), C(Z) {}

    void tinhTien(int dx, int dy)
    {
        A.tinhTien(dx, dy);
        B.tinhTien(dx, dy);
        C.tinhTien(dx, dy);
    }

    void hienThi()
    {
        cout << " "; A.hienThi();
        cout << " "; B.hienThi();
        cout << " "; C.hienThi();
        cout << "\nMau: "; hienThiColor();
        cout << endl;
    }
};

int main()
{
    int x1, x2, x3, y1, y2, y3, dx, dy, k;

    cout << "Nhap A, B, C: ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << "\nNhap dx, dy: ";
    cin >> dx >> dy;
    cout << "\nNhap k: ";
    cin >> k;

    Triangle T(Point (x1, y1), Point(x2, y2), Point(x3, y3), k);
    cout << "\nToa do cac diem truoc tinh tien: "; T.hienThi();
    T.tinhTien(dx, dy);
    cout << "\nToa do cac diem sau tinh tien: "; T.hienThi ();

    return 0;
}
