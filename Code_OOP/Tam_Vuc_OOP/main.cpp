#include <iostream>

using namespace std;

class PhanSo{
private:
    int tu, mau;
public:
    void nhap();
    int getTu();
    int getMau();
};
void PhanSo::nhap() {
    cin>>this->tu;
    cin>>this->mau;
}
void xuatPhanSo(PhanSo p) {
    cout << p.getTu();
    cout << p.getMau();
}
int PhanSo::getTu() {
    return tu;
}
int PhanSo::getMau() {
    return mau;
}
int main()
{
    PhanSo a;
    a.nhap();
    xuatPhanSo(a);
    return 0;
}
