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

    bool operator>(Student s)
    {
        return tb > s.tb;
    }
    friend void sapXepGiamDanDTB(Student sv[], int n);
};

void sapXepGiamDanDTB(Student sv[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(sv[j].tb > sv[i].tb) {
                float tmp = sv[j].tb;
                sv[j].tb = sv[i].tb;
                sv[i].tb = tmp;
            }
        }
    }
}

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
    }

    sapXepGiamDanDTB(sv, n);
    cout << "\nDanh sach sau khi sap xep giam dan theo diem trung binh la: " << endl;
    for(int i = 0; i < n; i++)
    {
        sv[i].in();
    }

    return 0;
}
