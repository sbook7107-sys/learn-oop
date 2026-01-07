
// phan so
#include<iostream>
using namespace std;
class PhanSo{
    private:
        int tuSo, mauSo;
    public:
        void nhap();
        void xuat();
        PhanSo rutGon();
        PhanSo cong(PhanSo p1);
        PhanSo tru(PhanSo p1);


};
int UCLN(int a, int b){
    while(a!=b){
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}
/*void PhanSo::rutGon(){
    int ucln=UCLN(tuSo, mauSo);
    tuSo=tuSo/ucln;
    mauSo=mauSo/ucln;
    cout<<"\nPhan so trong rut gon: ";
    this->xuat();
}
*/
PhanSo PhanSo::rutGon(){
    int ucln=UCLN(tuSo, mauSo);
    tuSo=tuSo/ucln;
    mauSo=mauSo/ucln;
    cout<<"\nPhan so trong rut gon: ";
    this->xuat();
    return *this;
}
void PhanSo::nhap(){
    cout<<"Nhap tu so: ";
    cin>>tuSo;
    do{
        cout<<"Nhap mau so: ";
        cin>>mauSo;
    }while(mauSo==0);
}
void PhanSo::xuat(){
    if(tuSo==0)
        cout<<"0";
    else if(mauSo==1)
        cout<<tuSo;
    else if(mauSo==tuSo)
        cout<<"1";
    else
        cout<<tuSo<<"/"<<mauSo;
}
PhanSo PhanSo::cong(PhanSo p1) {
    PhanSo kq;
    kq.tuSo = tuSo*p1.mauSo+mauSo*p1.tuSo;
    kq.mauSo = mauSo*p1.mauSo;
    return kq.rutGon();
}
PhanSo PhanSo::tru(PhanSo p1) {
    PhanSo kq;
    kq.tuSo = tuSo*p1.mauSo-mauSo*p1.tuSo;
    kq.mauSo = mauSo*p1.mauSo;
    return kq.rutGon();
}
int main(){
    PhanSo a;
    a.nhap();
    cout<<"a truoc khi rut gon: ";
    a.xuat();
    a.rutGon();
    cout<<"\na sau khi rut gon: ";
    a.xuat();
    PhanSo b;
    cout << endl;
    b.nhap();
    cout << "\na + b = ";

    a.cong(b);
    cout << "\na - b = ";
    a.tru(b);
    return 0;
}
