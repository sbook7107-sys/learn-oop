#include <iostream>
#include <cmath>
using namespace std;

class SoPhuc {
private:
    double thuc;
    double ao;

public:
    void nhap();
    void xuat();
};
    // Nhập số phức
     void SoPhuc::nhap() {
        cout << "Nhap phan thuc: ";
        cin >> thuc;
        cout << "Nhap phan ao: ";
        cin >> ao;
    }

    // Xuất số phức
    void SoPhuc:: xuat() {
        if (ao >= 0) cout << thuc << " + " << ao << "i";
        else cout << thuc << " - " << -ao << "i";
    }

    int getThuc() {
        return thuc;
    }

//    // Tính module
//    double module() {
//        return sqrt(thuc * thuc + ao * ao);
//    }
//
//    // Toán tử cộng
//    SoPhuc cong(SoPhuc& sp) {
//        SoPhuc kq;
//        kq.thuc = thuc + sp.thuc;
//        kq.ao   = ao + sp.ao;
//        return kq;
//    }
//
//    // Toán tử trừ
//    SoPhuc tru(SoPhuc& sp) {
//        SoPhuc kq;
//        kq.thuc = thuc - sp.thuc;
//        kq.ao   = ao - sp.ao;
//        return kq;
//    }
//
//    // Toán tử nhân
//    SoPhuc nhan(SoPhuc& sp) {
//        SoPhuc kq;
//        kq.thuc = thuc * sp.thuc - ao * sp.ao;
//        kq.ao   = thuc * sp.ao + ao * sp.thuc;
//        return kq;
//    }
//
//    // Toán tử chia
//    SoPhuc chia(SoPhuc& sp) {
//        SoPhuc kq;
//        double mau = sp.thuc * sp.thuc + sp.ao * sp.ao;
//        if (mau == 0)
//        {
//            cout << "Loi\n";
//        }
//        kq.thuc = (thuc * sp.thuc + ao * sp.ao) / mau;
//        kq.ao   = (ao * sp.thuc - thuc * sp.ao) / mau;
//        return kq;
//    }
//
//    // So sánh theo module
//    bool laBang(SoPhuc& sp) {
//        return fabs(module() - sp.module()) < 1e-9;
//    }
//    bool laBeHon(SoPhuc& sp) {
//        return module() < sp.module();
//    }
//    bool laLonHon(SoPhuc& sp) {
//        return module() > sp.module();
//    }

int main() {
    SoPhuc a, b;
    cout << "Nhap so phuc a:\n";
    a.nhap();
    cout << "Nhap so phuc b:\n";
    b.nhap();

    cout << "\nSo phuc a = "; a.xuat();
    cout << "\nSo phuc b = "; b.xuat();

//    cout << "\n\nPhep cong: "; (a.cong(b).xuat());
//    cout << "\nPhep tru: "; (a.tru(b).xuat());
//    cout << "\nPhep nhan: "; (a.nhan(b).xuat());
//    cout << "\nPhep chia: "; (a.chia(b).xuat());
//
//    cout << "\n\nSo sanh theo module: ";
//    if (a.laBang(b)) cout << "a = b\n";
//    else if (a.laBeHon(b)) cout << "a < b\n";
//    else cout << "a > b\n";
//
//    cout << "\nModule cua a = " << a.module();
//    cout << "\nModule cua b = " << b.module() << endl;

    return 0;
}


