#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

int check_snt(int n) {
    for(int i=2; i<=sqrt(n); i++) {
        if(n%i==0) {
            return 0;
        }
    }
    return n>1;
}

double tich(const vector<int>&a, int n) {
    if(n==0)
        return 1;
    else{
        return a[n-1]*tich(a, n-1);
    }
}
int main()
{
    srand(time(0));

    int n;
    cout<<"Nhap so luong phan tu: ";
    cin>>n;

    cout<< "Cac phan tu trong mang: ";
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        a[i] = rand() % 101;
        cout << a[i] << " ";
    }
    cout<<endl;

    cout<< "Cac so nguyen to trong mang: ";
    for(int i=0; i<n; i++) {
        if(check_snt(a[i])) {
            cout<<a[i]<<" ";
        }
    }
    cout<<endl;

    double tbNhan = pow(tich(a,n), 1.0/n);
    cout<<"Trung binh nhan: "<< tbNhan << endl;

    return 0;
}
