#include <iostream>
#include <string>
uisng namespace std;

class SinhVien {
private:
    int mSV;
    string hoTen;
    int namSinh;
    string lop;
    float diemTB;
public:
    SinhVien(int mSV, string hoTen, int namSinh, string lop, float diemTB);
    void nhap();
    void xuat();

};
