#include <iostream>
#include <string>
using namespace std;

class SV {
protected:
    string lop;
    string hoTen;
public:
    SV() : lop(""), hoTen("") {}
    SV(string l, string ht) : lop(l), hoTen(ht) {}
    virtual ~SV() {}

    virtual void nhap() {
        cin.ignore();
        cout << "\nNhap lop: ";
        getline(cin, lop);
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
    }

    virtual void hienThi() const {
        cout << "\nLop: " << lop;
        cout << "\nHo ten: " << hoTen;
    }
};

class SVTC : public SV {
protected:
    long hocPhi;
public:
    SVTC() : SV(), hocPhi(0) {}
    SVTC(long hp, string l, string ht) : SV(l, ht), hocPhi(hp) {}

    void nhap() override {
        SV::nhap();
        cout << "Nhap hoc phi: ";
        cin >> hocPhi;
    }

    void hienThi() const override {
        SV::hienThi();
        cout << "\nHoc phi: " << hocPhi;
    }

    long getHocPhi() const { return hocPhi; }

    bool operator>(const SVTC &other) const {
        return this->hocPhi > other.hocPhi;
    }
};

class SVCN : public SVTC {
private:
    float dTB;
    string hocBong;
public:
    SVCN() : SVTC(), dTB(0), hocBong("") {}
    SVCN(float dtb, string hb, long hp, string l, string ht)
        : SVTC(hp, l, ht), dTB(dtb), hocBong(hb) {}

    void nhap() override {
        SVTC::nhap();
        cout << "Nhap diem trung binh: ";
        cin >> dTB;
        cin.ignore();
        cout << "Nhap hoc bong: ";
        getline(cin, hocBong);
    }

    void hienThi() const override {
        SVTC::hienThi();
        cout << "\nDiem trung binh: " << dTB;
        cout << "\nHoc bong: " << hocBong;
    }
};

int main() {
    const int n = 5;
    SVCN *ds[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap sinh vien thu " << i + 1 << ":\n";
        ds[i] = new SVCN();
        ds[i]->nhap();
    }

    for (int i = 0; i < n; i++) {
        cout << "\n\nSinh vien thu " << i + 1 << ":";
        ds[i]->hienThi();
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!(*(ds[i]) > *(ds[j]))) {
                swap(ds[i], ds[j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "\n\nSinh vien thu " << i + 1 << ":";
        ds[i]->hienThi();
    }

    for (int i = 0; i < n; i++)
        delete ds[i];

    return 0;
}
