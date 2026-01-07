#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class SinhVien {
private:
    string MSV;
    string Hoten;
    int NS;
    string Lop;
    float DTB;

public:
    // Hàm bạn (friend) để dùng toán tử nhập/xuất
    friend istream& operator>>(istream& in, SinhVien& sv);
    friend ostream& operator<<(ostream& out, const SinhVien& sv);
    friend bool operator>(const SinhVien& a, const SinhVien& b);  // So sánh DTB giảm dần
    friend bool operator<(const SinhVien& a, const SinhVien& b);  // So sánh NS tăng dần

    float getDTB() const { return DTB; }
    int getNS() const { return NS; }
};

// Toán tử nhập
istream& operator>>(istream& in, SinhVien& sv) {
    cout << "Nhap MSV: ";
    getline(in, sv.MSV);
    cout << "Nhap Ho ten: ";
    getline(in, sv.Hoten);
    cout << "Nhap Nam sinh: ";
    in >> sv.NS;
    in.ignore();
    cout << "Nhap Lop: ";
    getline(in, sv.Lop);
    cout << "Nhap DTB: ";
    in >> sv.DTB;
    in.ignore();
    return in;
}

// Toán tử xuất
ostream& operator<<(ostream& out, const SinhVien& sv) {
    out << "Ma sinh vien: " << sv.MSV
        << "\nHo ten: " << sv.Hoten
        << "\nNam sinh: " << sv.NS
        << "\nLop: " << sv.Lop
        << "\nDiem trung binh: " << fixed << setprecision(2) << sv.DTB;
    return out;
}

// So sánh DTB (giảm dần)
bool operator>(const SinhVien& a, const SinhVien& b) {
    return a.DTB > b.DTB;
}

// So sánh NS (tăng dần)
bool operator<(const SinhVien& a, const SinhVien& b) {
    return a.NS < b.NS;
}

// Hàm hoán đổi
void HoanDoi(SinhVien &a, SinhVien &b) {
    SinhVien tmp = a;
    a = b;
    b = tmp;
}

// Sắp xếp theo DTB giảm dần
void SapXepDTB(SinhVien ds[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (ds[j] > ds[i])
                HoanDoi(ds[i], ds[j]);
}

// Sắp xếp theo năm sinh tăng dần
void SapXepNS(SinhVien ds[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (ds[j] < ds[i])
                HoanDoi(ds[i], ds[j]);
}

// Thống kê cảnh báo
int DemCanhBao(SinhVien ds[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (ds[i].getDTB() < 1.0)
            dem++;
    return dem;
}

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();

    SinhVien ds[100];

    cout << "\nNhap danh sach sinh vien\n";
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien thu " << i+1 << ":\n";
        cin >> ds[i];
    }

    cout << "\nDanh sach sinh vien\n";
    for (int i = 0; i < n; i++) {
        cout << ds[i] << endl;
    }

    // Sắp xếp theo ĐTB giảm dần
    SapXepDTB(ds, n);
    cout << "\nDanh sach sinh vien sau khi sap xep theo DTB giam dan la: \n";
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien thu " << i + 1 << endl;
        cout << ds[i] << endl;
    }

    // Sắp xếp theo năm sinh tăng dần
    SapXepNS(ds, n);
    cout << "\nDanh sach sinh vien sau khi sap xep theo nam sinh tang dan la: \n";
    for (int i = 0; i < n; i++) {
        cout << "Sinh vien thu " << i + 1 << endl;
        cout << ds[i] << endl;
    }

    // Cảnh báo học tập
    cout << "\nSo luong sinh vien canh bao hoc tap: " << DemCanhBao(ds, n) << endl;

    return 0;
}
