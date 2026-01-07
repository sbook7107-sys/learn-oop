#include <iostream>
#include <cstring>

using namespace std;

struct CongNhan{
    string ten;
    int namSinh;
    int gioLam;
};

typedef struct CongNhan cn;

//Hàm nhập công nhân
void nhap(CongNhan cn[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Cong nhan thu: " << i << endl;
        cout << "Ten: ";
        cin.ignore();
        getline(cin, cn[i].ten);

        cout << "Nam sinh: ";
        cin >> cn[i].namSinh;

        cout << "Gio lam: ";
        cin >> cn[i].gioLam;
    }
}

//Hàm in công nhân được khen thưởng
void khenThuong(CongNhan cn[], int n) {
    bool found = false; //Đặt biến cở để kiểm tra
    bool first = true;
    cout << "Liet ke danh ten cac cong nhan duoc khen thuong: ";
    for(int i = 0; i < n; i++) {
        if(cn[i].gioLam > 40) {
            if(!first) cout << ", ";
            cout << cn[i].ten;
            first = false;
            found = true;
        }
    }
    if(!found) cout << "\nKhong co cong nhan nao duoc khen thuong!";
}

//Hàm sắp xếp công nhân theo giờ làm giảm dần
void sapXep(CongNhan cn[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(cn[i].gioLam < cn[j].gioLam) {
                CongNhan temp = cn[i];
                cn[i] = cn[j];
                cn[j] = temp;
            }
        }
    }
}

//Hàm in danh sách công nhân sau khi sắp xếp
void inDanhSachSauSapXep(CongNhan cn[], int n) {
    cout << "\n ==== Danh sach cong nhan sau khi sap xep ==== \n";
    for(int i = 0; i < n; i++) {
        cout << "Cong nhan thu " << i;
        cout << "\nTen: " << cn[i].ten;
        cout << "\nNam sinh: " << cn[i].namSinh;
        cout << "\nGio lam: " << cn[i].gioLam << endl;
    }
}

int main() {
    int n;
    cout << "Nhap so luong cong nhan: ";
    cin >> n;

    CongNhan cn[n];
    nhap(cn, n);
    khenThuong(cn, n);
    sapXep(cn, n);
    inDanhSachSauSapXep(cn, n);

    return 0;
}
