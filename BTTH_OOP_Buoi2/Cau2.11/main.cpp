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

class Circle : public MyColor {
private:
    Point O;
    float r;
public:

    Circle(Point o = Point(), float bk = 0, int sh = 0)
    : MyColor(sh), O(o), r(bk) {}

    float tinhDienTich() const {
        return 3.14 * r * r;
    }

    void hienThi()
    {
        cout << "\nDien tich: " << tinhDienTich();
        cout << "\nTam: "; O.hienThi();
        cout << "\nban kinh r = " << r;
        hienThiMau();
        cout << endl;
    }

    bool operator >(const Circle &c) {
        return tinhDienTich() > c.tinhDienTich();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong duong tron: "; cin >> n;
    Circle *a = new Circle[n];

    for(int i = 0; i < n; i++) {
        int x, y, r;
        float c;
        cout << "\nNhap gia tri tam(x, y), ban kinh r va mau c: ";
        cin >> x >> y >> r >> c;
        a[i] = Circle(Point(x, y), r, c);
    }

    Circle max = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] > max)
            max = a[i];
    }

    cout << "\nDuong tron co dien tich lon nhat la: ";
    max.hienThi();

    return 0;
}
