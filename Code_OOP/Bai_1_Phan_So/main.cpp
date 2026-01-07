#include <iostream>
#define ll long long
using namespace std;

class PhanSo{
private:
    int tuSo;
    int mauSo;
public:
    PhanSo();
    PhanSo(int tu, int mau);

    int layTu() const;
    int layMau() const;
    void ganTu(int tu);
    void ganMau(int mau);

    void nhap();
    void xuat();

    PhanSo nghichDao() const;
    void rutGon();

    PhanSo cong(PhanSo& p);
    PhanSo tru(PhanSo& p);
    PhanSo nhan(PhanSo& p);
    PhanSo chia(PhanSo& p);

    int soSanh(PhanSo& p);
};

PhanSo::PhanSo() {
    tuSo = 0;
    mauSo = 1;
}

PhanSo::PhanSo(int tu, int mau) {
    tuSo = tu;
    if(mau == 0)
        mauSo = 1;
    else
        mauSo = mau;
}

int myAbs(int x) {
    if(x < 0)
        return -x;
    else
        return x;
}

int gcd(int a, int b) {
    a = myAbs(a);
    b = myAbs(b);

    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int PhanSo::layTu() const{
    return tuSo;
}

int PhanSo::layMau() const{
    return mauSo;
}

void PhanSo::ganTu(int tu) {
    tuSo = tu;
}

void PhanSo::ganMau(int mau) {
    if(mau != 0)
        mauSo = mau;
    else
        cout << "Loi";
        mauSo = 1;
}

void PhanSo::nhap() {
    cout << "\nNhap tu so: ";
    cin >> tuSo;
    do{
        cout << "\nNhap mau so: ";
        cin >> mauSo;
        if(mauSo == 0)
            cout << "\nMau so phai khac khong. Vui long nhap lai.";
    }while(mauSo == 0);
}

void PhanSo::xuat() {
    cout << tuSo << "/" << mauSo;
}

PhanSo PhanSo::nghichDao() const{
    if(tuSo == 0) {
        return PhanSo(0, 1);
    }
    return PhanSo(mauSo, tuSo);
}

void PhanSo::rutGon() {
    if(tuSo == 0) {
        mauSo = 1;
        return;
    }
    int ucln = gcd(tuSo, mauSo);
    tuSo /= ucln;
    mauSo /= ucln;

    if(mauSo < 0) {
        tuSo = -tuSo;
        mauSo = -mauSo;
    }
}

PhanSo PhanSo::cong(PhanSo &p) {
    int tu = tuSo * p.mauSo + p.tuSo * mauSo;
    int mau = mauSo * p.mauSo;
    PhanSo ketQua(tu, mau);
    ketQua.rutGon();
    return ketQua;
}
PhanSo PhanSo::tru(PhanSo &p) {
    int tu = tuSo * p.mauSo - p.tuSo * mauSo;
    int mau = mauSo * p.mauSo;
    PhanSo ketQua(tu, mau);
    ketQua.rutGon();
    return ketQua;
}
PhanSo PhanSo::nhan(PhanSo &p) {
    int tu = tuSo * p.tuSo;
    int mau = mauSo * p.mauSo;
    PhanSo ketQua(tu, mau);
    ketQua.rutGon();
    return ketQua;
}
PhanSo PhanSo::chia(PhanSo &p) {
    if(p.tuSo == 0)
        return PhanSo(0, 1);
    PhanSo psNghichDao = p.nghichDao();
    return this->nhan(psNghichDao);
}
int PhanSo::soSanh(PhanSo &p) {
    ll hieu = (ll)tuSo * p.mauSo - (ll)p.tuSo * mauSo;

    if(hieu > 0)
        return 1;
    else if(hieu < 0)
        return -1;
    else
        return 0;
}

int main()
{
    PhanSo ps1, ps2, ketQua;

    ps1.nhap();
    ps1.rutGon();
    ps1.xuat();

    ps2.nhap();
    ps2.rutGon();
    ps2.xuat();
    cout << endl;

    ketQua = ps1.cong(ps2);
    ketQua.xuat();
    cout << endl;

    ketQua = ps1.tru(ps2);
    ketQua.xuat();
    cout << endl;

    ketQua = ps1.nhan(ps2);
    ketQua.xuat();
    cout << endl;

    ketQua = ps1.chia(ps2);
    ketQua.xuat();
    cout << endl;

    int ss = ps1.soSanh(ps2);
    if(ss > 0) {
        ps1.xuat(); cout << ">"; ps2.xuat();
    }
    else if(ss < 0) {
        ps1.xuat(); cout << "<"; ps2.xuat();
    }
    else {
        ps1.xuat(); cout << "="; ps2.xuat();
    }
    cout << endl;

    PhanSo ps1NghichDao = ps1.nghichDao();
    cout << "\nNghich dao cua ps1 la: ";
    ps1NghichDao.xuat();
    PhanSo ps2NghichDao = ps2.nghichDao();
    cout << "\nNghich dao cua ps2 la: ";
    ps2NghichDao.xuat();

    return 0;
}
