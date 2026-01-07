#include <iostream>

using namespace std;

class MyDate {
private:
    int ngay, thang, nam;
public:
    MyDate() : ngay(1), thang(1), nam(1900) {}
    MyDate(int d, int m, int y) : ngay(d), thang(m), nam(y) {}

    void nhap()
    {
        cout << "\nNhap ngay: ";
        cin >> ngay;
        cout << "Nhap thang: ";
        cin >> thang;
        cout << "Nhap nam: ";
        cin >> nam;
    }

    void in()
    {
        cout << ngay << "-" << thang << "-" << nam;
    }

    bool operator>(const MyDate &m1)
    {
        if(nam != m1.nam) return nam > m1.nam;
        if(thang != m1.thang) return thang > m1.thang;
        return ngay > m1.ngay;
    }
};

void sapXepTangDan(MyDate m[], int n)
{
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(m[j] > m[j+1]) {
                MyDate tmp = m[j];
                m[j] = m[j+1];
                m[j+1] = tmp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;

    MyDate m[n];
    for(int i = 0; i < n; i++) {
        m[i].nhap();
    }

    cout << endl;

    for(int i = 0; i < n; i++) {
        m[i].in();
        cout << " ";
    }

    sapXepTangDan(m, n);
    cout << "\nDanh sach sau khi sap xep tang dan: ";
    for(int i = 0; i < n; i++) {
        m[i].in();
        cout << " ";
    }

    return 0;
}
