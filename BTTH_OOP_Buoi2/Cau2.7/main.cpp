#include <iostream>
#include <string>
using namespace std;

class SV {
private:
    string lop;
    string hoTen;
public:
    SV() {lop = ""; hoTen = "";}
    SV(string l, string ht) : lop(l), hoTen(ht) {}
    ~SV() {}

    void nhap()
    {
        cin.ignore();
        cout << "\nNhap lop: ";
        getline(cin, lop);
        cout << "\nNhap ho ten: ";
        getline(cin, hoTen);
    }

    void hienThi()
    {
        cout << "\nLop: " << lop;
        cout << "\nHo ten: " << hoTen;
    }
};

class SVTC : public SV {
private:
    double hocPhi;
public:
    SVTC() : SV() {hocPhi = 0;}
    SVTC(double hp, string l, string ht)
    : SV(l, ht), hocPhi(hp) {}

    void nhap()
    {
        SV::nhap();
        cout << "\nNhap hoc phi: ";
        cin >> hocPhi;
    }

    void hienThi()
    {
        SV::hienThi();
        cout << "\nHoc phi: " << hocPhi;
    }
};


class SVCN : public SVTC{
private:
    float dTB;
    string hocBong;
public:
    SVCN(float dtb = 0, string hb = "", string l = "", string ht = "", double hp = 0)
    : SVTC(hp, l, ht), dTB(dtb), hocBong(hb) {}

    void nhap()
    {
        SVTC::nhap();
        cout << "\nNhap diem trung binh: ";
        cin >> dTB;
        cin.ignore();
        cout << "\nNhap thong tin hoc bong: ";
        getline(cin, hocBong);
    }

    void hienThi()
    {
        SVTC::hienThi();
        cout << "\nDiem trung binh: " << dTB;
        cout << "\nHoc bong: " << hocBong;
    }

    float getDiemTB() const {return dTB;}
};


int main()
{
    const int n = 3;
    SVCN *a[n];

    cout << "\nNhap thong tin 3 doi tuong";
    for(int i = 0; i < n; i++) {
        cout << "\nNhap doi tuong thu " << i + 1 << ":";
        a[i] = new SVCN();
        a[i]->nhap();
    }

    cout << "\nThong tin 3 doi tuong truoc khi sap xep";
    for(int i = 0; i < n; i++) {
        cout << "\nDoi tuong thu " << i + 1 << ":";
        a[i]->hienThi();
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i]->getDiemTB() < a[j]->getDiemTB())
                swap(a[i], a[j]);
        }
    }


    cout << "\nThong tin 3 doi tuong sau khi sap xep";
    for(int i = 0; i < n; i++) {
        cout << "\nDoi tuong thu " << i + 1 << ":";
        a[i]->hienThi();
    }

    return 0;
}
