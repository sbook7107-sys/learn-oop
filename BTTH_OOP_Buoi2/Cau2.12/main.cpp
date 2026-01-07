#include <iostream>
#include <cmath>
using namespace std;

class MyColor {
private:
    int color;
public:
    MyColor(int c = 0) : color(c) {}

    void nhapMau() {
        cout << "Nhap so hieu mau: ";
        cin >> color;
    }

    void hienThiMau() const {
        cout << "So hieu mau: " << color;
    }

    int getColor() const { return color; }
};

class Point {
private:
    float x, y;
public:
    Point(float xx = 0, float yy = 0) : x(xx), y(yy) {}

    void nhap() {
        cout << "Nhap x: "; cin >> x;
        cout << "Nhap y: "; cin >> y;
    }

    void hienThi() const {
        cout << "(" << x << ", " << y << ")";
    }

    friend float tinhKhoangCach(const Point &p1, const Point &p2);
};

float tinhKhoangCach(const Point &p1, const Point &p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

class Triangle : public MyColor {
private:
    Point A, B, C;
public:
    Triangle(Point a = Point(), Point b = Point(), Point c = Point(), int color = 0)
        : MyColor(color), A(a), B(b), C(c) {}

    float tinhChuVi() const {
        float ab = tinhKhoangCach(A, B);
        float bc = tinhKhoangCach(B, C);
        float ca = tinhKhoangCach(C, A);
        return ab + bc + ca;
    }

    float tinhDienTich() const {
        float ab = tinhKhoangCach(A, B);
        float bc = tinhKhoangCach(B, C);
        float ca = tinhKhoangCach(C, A);
        float p = (ab + bc + ca) / 2;
        return sqrt(p * (p - ab) * (p - bc) * (p - ca));
    }

    void hienThi() const {
        cout << "\nToa do cac dinh tam giac:\n";
        cout << "A"; A.hienThi();
        cout << ", B"; B.hienThi();
        cout << ", C"; C.hienThi();
        cout << endl;
        hienThiMau();
        cout << "\nChu vi: " << tinhChuVi();
        cout << "\nDien tich: " << tinhDienTich() << endl;
    }

    bool operator>(const Triangle &t) const {
        return tinhDienTich() > t.tinhDienTich();
    }
};

int main() {
    int n;
    cout << "Nhap so luong tam giac: ";
    cin >> n;

    Triangle *arr = new Triangle[n];

    for (int i = 0; i < n; i++) {
        cout << "\nTam giac thu" << i + 1 << ":";
        float x1, y1, x2, y2, x3, y3;
        int color;
        cout << "Nhap toa do dinh A (x y): "; cin >> x1 >> y1;
        cout << "Nhap toa do dinh B (x y): "; cin >> x2 >> y2;
        cout << "Nhap toa do dinh C (x y): "; cin >> x3 >> y3;
        cout << "Nhap mau: "; cin >> color;
        arr[i] = Triangle(Point(x1, y1), Point(x2, y2), Point(x3, y3), color);
    }

    for (int i = 0; i < n; i++) {
        cout << "\n--- Tam giac thu " << i + 1 << " ---";
        arr[i].hienThi();
    }

    Triangle max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    cout << "\nTam giac co dien tich lon nhat";
    max.hienThi();

    delete[] arr;
    return 0;
}
