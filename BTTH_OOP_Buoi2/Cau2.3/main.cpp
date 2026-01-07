#include <iostream>

using namespace std;

class SV {
private:
    string lop;
    string hoTen;
public:
    SV(string l = "", string ht = "") : lop(l), hoTen(ht) {}
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

class SVSP : public SV{
private:
    float dTB;
    string hocBong;
public:
    SVSP(float dtb = 0, string hb = "", string l = "", string ht = "")
    : SV(l, ht), dTB(dtb), hocBong(hb) {}

    void nhap()
    {
        SV::nhap();
        cout << "\nNhap diem trung binh: ";
        cin >> dTB;
        cin.ignore();
        cout << "\nNhap thong tin hoc bong: ";
        getline(cin, hocBong);
    }

    void hienThi()
    {
        SV::hienThi();
        cout << "\nDiem trung binh: " << dTB;
        cout << "\nHoc bong: " << hocBong;
    }
};

class SVCN : public SVSP {
private:
    double hocPhi;
public:
    SVCN(double hp = 0, float dtb = 0, string hb = "", string l = "", string ht = "")
    : SVSP(dtb, hb, l, ht), hocPhi(hp) {}

    void nhap()
    {
        SVSP::nhap();
        cout << "\nNhap hoc phi: ";
        cin >> hocPhi;
    }

    void hienThi()
    {
        SVSP::hienThi();
        cout << "\nHoc phi: " << hocPhi;
    }
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

    cout << "\nThong tin 3 doi tuong sau khi nhap";
    for(int i = 0; i < n; i++) {
        cout << "\nDoi tuong thu " << i + 1 << ":";
        a[i]->hienThi();
    }

    return 0;
}
