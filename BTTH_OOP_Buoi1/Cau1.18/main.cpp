#include <iostream>

using namespace std;

class Student
{
private:
    string hoTen;
    float k1, k2, tb;
public:
    Student()
    {
        hoTen = "";
        k1=k2=tb=0;
    }

    void nhap()
    {
        cin.ignore();
        cout << "\nNhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap diem ky 1: ";
        cin >> k1;
        cout << "Nhap diem ky 2: ";
        cin >> k2;
        tb = (k1 + 2 * k2) / 3;
    }

    void in()
    {
        cout << "\nHo ten sinh vien: " << hoTen;
        cout << "\nDiem ky 1: " << k1;
        cout << "\nDiem ky 2: " << k2;
        cout << "\nDiem trung binh ca nam: " << tb;
    }

    bool kiemTra() {
        return tb >= 5;
    }
};

int main() {
    int n = 5;
    Student sv[n];
    for(int i = 0; i < n; i++)
    {
        cout << "\nNhap thong tin sinh vien thu " << i+1 << ":";
        sv[i].nhap();
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        sv[i].in();
        cout << " ";
    }

    cout << "\nDanh sach sinh vien co dtb >= 5 la: " << endl;
    for(int i = 0; i < n; i++)
    {
        if(sv[i].kiemTra()) {
            sv[i].in();
        }
    }

    return 0;
}
