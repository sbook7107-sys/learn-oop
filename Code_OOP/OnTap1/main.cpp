#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

/*
// Bài 3.1
// Xây dựng lớp phân số
class PhanSo {
private:
    int tuSo;
    int mauSo;

    int gcd(int a, int b) {
        if(b==0) return a;
        return gcd(b, a%b);
    }

    // Hàm rút gọn
    void rutGon() {
        int g = gcd(tuSo, mauSo);
        tuSo /= g;
        mauSo /= g;
        if (mauSo < 0) {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }

public:
    // Hàm khởi tạo
    PhanSo(int tu = 0, int mau = 1) {
        tuSo = tu;
        mauSo = (mau == 0 ? 1 : mau);
        rutGon();
    }

    // Hàm nhập
    void nhap() {
        cout << "Nhap tu so: "; cin >> tuSo;
        cout << "Nhap mau so: "; cin >> mauSo;
        if (mauSo == 0) mauSo = 1;
        rutGon();
    }

    // Hàm xuất
    void xuat() {
        if (mauSo == 1) cout << tuSo;
        else cout << tuSo << "/" << mauSo;
    }

    // Getter, Setter
    int getTu() { return tuSo; }
    int getMau() { return mauSo; }
    void setTu(int tu) { tuSo = tu; rutGon(); }
    void setMau(int mau) { if (mau != 0) mauSo = mau; rutGon(); }

    // Hàm swap
    void mySwap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    // Hàm nghịch đảo
    void nghichDao() {
        if (tuSo != 0) mySwap(tuSo, mauSo);
        rutGon();
    }

    // Toán tử cộng, trừ, nhân, chia
    PhanSo cong(PhanSo &b) {
        return PhanSo(tuSo * b.mauSo + b.tuSo * mauSo, mauSo * b.mauSo);
    }

    PhanSo operator-(PhanSo b) {
        return PhanSo(tuSo * b.mauSo - b.tuSo * mauSo, mauSo * b.mauSo);
    }

    PhanSo operator*(PhanSo b) {
        return PhanSo(tuSo * b.tuSo, mauSo * b.mauSo);
    }

    PhanSo operator/(PhanSo b) {
        return PhanSo(tuSo * b.mauSo, mauSo * b.tuSo);
    }

    // So sánh
    bool operator==(PhanSo b) {
        return tuSo == b.tuSo && mauSo == b.mauSo;
    }

    bool operator<(PhanSo b) {
        return (1LL * tuSo * b.mauSo) < (1LL * b.tuSo * mauSo);
    }

    bool operator>(PhanSo b) {
        return (1LL * tuSo * b.mauSo) > (1LL * b.tuSo * mauSo);
    }
};

int main() {
    PhanSo a, b;
    cout << "Nhap phan so a:\n"; a.nhap();
    cout << "Nhap phan so b:\n"; b.nhap();

    cout << "\nPhan so a = "; a.xuat();
    cout << "\nPhan so b = "; b.xuat();

        cout << "\n\na + b = "; (a.cong(b)).xuat();
    cout << "\na - b = "; (a - b).xuat();
    cout << "\na * b = "; (a * b).xuat();
    cout << "\na / b = "; (a / b).xuat();

    cout << "\n\nSo sanh a va b:\n";
    if (a == b) cout << "a = b\n";
    else if (a < b) cout << "a < b\n";
    else cout << "a > b\n";

    cout << "\nNghich dao a = "; a.nghichDao(); a.xuat();
    cout << endl;

    return 0;
}
*/

/*
//Bài 3.2: Xây dựng số phức
#include <iostream>
#include <cmath>
using namespace std;

class SoPhuc {
private:
    double thuc; // phần thực
    double ao;   // phần ảo

public:
    // Constructor mặc định
    SoPhuc(double t = 0, double a = 0) {
        thuc = t;
        ao = a;
    }

    // Nhập số phức
    void nhap() {
        cout << "Nhap phan thuc: ";
        cin >> thuc;
        cout << "Nhap phan ao: ";
        cin >> ao;
    }

    // Xuất số phức
    void xuat() const {
        if (ao >= 0) cout << thuc << " + " << ao << "i";
        else cout << thuc << " - " << -ao << "i";
    }

    // Getter
    double getThuc() const { return thuc; }
    double getAo() const { return ao; }

    // Setter
    void setThuc(double t) { thuc = t; }
    void setAo(double a) { ao = a; }

    // Tính module
    double module() const {
        return sqrt(thuc * thuc + ao * ao);
    }

    // Toán tử cộng
    SoPhuc operator+(const SoPhuc& sp) const {
        return SoPhuc(thuc + sp.thuc, ao + sp.ao);
    }

    // Toán tử trừ
    SoPhuc operator-(const SoPhuc& sp) const {
        return SoPhuc(thuc - sp.thuc, ao - sp.ao);
    }

    // Toán tử nhân
    SoPhuc operator*(const SoPhuc& sp) const {
        return SoPhuc(thuc * sp.thuc - ao * sp.ao,
                      thuc * sp.ao + ao * sp.thuc);
    }

    // Toán tử chia
    SoPhuc operator/(const SoPhuc& sp) const {
        double mau = sp.thuc * sp.thuc + sp.ao * sp.ao;
        if (mau == 0) {
            throw runtime_error("Loi: chia cho 0!");
        }
        return SoPhuc((thuc * sp.thuc + ao * sp.ao) / mau,
                      (ao * sp.thuc - thuc * sp.ao) / mau);
    }

    // So sánh theo module
    bool operator==(const SoPhuc& sp) const {
        return fabs(module() - sp.module()) < 1e-9;
    }
    bool operator<(const SoPhuc& sp) const {
        return module() < sp.module();
    }
    bool operator>(const SoPhuc& sp) const {
        return module() > sp.module();
    }
};

// ================== MAIN ===================
int main() {
    SoPhuc a, b;
    cout << "Nhap so phuc a:\n";
    a.nhap();
    cout << "Nhap so phuc b:\n";
    b.nhap();

    cout << "\nSo phuc a = "; a.xuat();
    cout << "\nSo phuc b = "; b.xuat();

    cout << "\n\nPhep cong: "; (a + b).xuat();
    cout << "\nPhep tru: "; (a - b).xuat();
    cout << "\nPhep nhan: "; (a * b).xuat();
    cout << "\nPhep chia: "; (a / b).xuat();

    cout << "\n\nSo sanh theo module: ";
    if (a == b) cout << "a = b\n";
    else if (a < b) cout << "a < b\n";
    else cout << "a > b\n";

    cout << "\nModule cua a = " << a.module();
    cout << "\nModule cua b = " << b.module() << endl;

    return 0;
}
*/


// Bài 3.2
/*
class SoPhuc {
private:
    double thuc;  // phần thực
    double ao;    // phần ảo
public:
    // --- Constructor ---
    SoPhuc(double t = 0, double a = 0) : thuc(t), ao(a) {}

    // --- Nhập & Xuất ---
    void nhap() {
        cout << "Nhap phan thuc: ";
        cin >> thuc;
        cout << "Nhap phan ao: ";
        cin >> ao;
    }

    void xuat() const {
        if (ao >= 0)
            cout << thuc << " + " << ao << "i";
        else
            cout << thuc << " - " << -ao << "i";
    }

    // --- Getter ---
    double getThuc() const { return thuc; }
    double getAo() const { return ao; }

    // --- Setter ---
    void setThuc(double t) { thuc = t; }
    void setAo(double a) { ao = a; }

    // --- Module ---
    double module() const {
        return sqrt(thuc * thuc + ao * ao);
    }

    // --- Nạp chồng toán tử ---
    SoPhuc operator+(const SoPhuc& other) const {
        return SoPhuc(thuc + other.thuc, ao + other.ao);
    }

    SoPhuc operator-(const SoPhuc& other) const {
        return SoPhuc(thuc - other.thuc, ao - other.ao);
    }

    SoPhuc operator*(const SoPhuc& other) const {
        return SoPhuc(thuc * other.thuc - ao * other.ao,
                      thuc * other.ao + ao * other.thuc);
    }

    SoPhuc operator/(const SoPhuc& other) const {
        double mau = other.thuc * other.thuc + other.ao * other.ao;
        return SoPhuc((thuc * other.thuc + ao * other.ao) / mau,
                      (ao * other.thuc - thuc * other.ao) / mau);
    }

    // So sánh dựa theo module
    bool operator==(const SoPhuc& other) const {
        return (thuc == other.thuc && ao == other.ao);
    }

    bool operator!=(const SoPhuc& other) const {
        return !(*this == other);
    }

    bool operator<(const SoPhuc& other) const {
        return this->module() < other.module();
    }

    bool operator>(const SoPhuc& other) const {
        return this->module() > other.module();
    }
};

int main() {
    SoPhuc a, b;
    cout << "Nhap so phuc a:\n";
    a.nhap();
    cout << "Nhap so phuc b:\n";
    b.nhap();

    cout << "\nSo phuc a = "; a.xuat();
    cout << "\nSo phuc b = "; b.xuat();

    cout << "\n\nTong a + b = "; (a + b).xuat();
    cout << "\nHieu a - b = "; (a - b).xuat();
    cout << "\nTich a * b = "; (a * b).xuat();
    cout << "\nThuong a / b = "; (a / b).xuat();

    cout << "\n\nModule a = " << a.module();
    cout << "\nModule b = " << b.module();

    cout << "\n\nSo sanh: ";
    if (a > b) cout << "a lon hon b";
    else if (a < b) cout << "a nho hon b";
    else cout << "a bang b";

    cout << endl;
    return 0;
}
*/

//Bài 3.3
/*

class DonThuc {
private:
    double heSo;
    int soMu;

public:
    // --- Constructor ---
    DonThuc(double hs = 0, int sm = 0) : heSo(hs), soMu(sm) {}

    // --- Nhập & Xuất ---
    void nhap() {
        cout << "Nhap he so: ";
        cin >> heSo;
        cout << "Nhap so mu: ";
        cin >> soMu;
    }

    void xuat() const {
        if (soMu == 0) cout << heSo;
        else if (soMu == 1) cout << heSo << "x";
        else cout << heSo << "x^" << soMu;
    }

    // --- Getter ---
    double getHeSo() const { return heSo; }
    int getSoMu() const { return soMu; }

    // --- Setter ---
    void setHeSo(double hs) { heSo = hs; }
    void setSoMu(int sm) { soMu = sm; }

    // --- Tính giá trị tại x ---
    double giaTri(double x) const {
        return heSo * pow(x, soMu);
    }

    // --- Đạo hàm ---
    DonThuc daoHam() const {
        if (soMu == 0) return DonThuc(0, 0);
        return DonThuc(heSo * soMu, soMu - 1);
    }

    // --- Nguyên hàm ---
    DonThuc nguyenHam() const {
        return DonThuc(heSo / (soMu + 1), soMu + 1);
    }

    // --- Nạp chồng toán tử ---
    // Cộng, trừ: chỉ hợp lệ nếu cùng số mũ
    DonThuc operator+(const DonThuc& other) const {
        if (soMu != other.soMu) {
            cerr << "Khong the cong hai don thuc khac bac!\n";
            return *this;
        }
        return DonThuc(heSo + other.heSo, soMu);
    }

    DonThuc operator-(const DonThuc& other) const {
        if (soMu != other.soMu) {
            cerr << "Khong the tru hai don thuc khac bac!\n";
            return *this;
        }
        return DonThuc(heSo - other.heSo, soMu);
    }

    // Nhân, chia: bình thường
    DonThuc operator*(const DonThuc& other) const {
        return DonThuc(heSo * other.heSo, soMu + other.soMu);
    }

    DonThuc operator/(const DonThuc& other) const {
        if (other.heSo == 0) {
            cerr << "Loi: Khong the chia cho don thuc co he so = 0!\n";
            return *this;
        }
        return DonThuc(heSo / other.heSo, soMu - other.soMu);
    }

    // So sánh: chỉ hợp lệ khi cùng số mũ
    bool operator==(const DonThuc& other) const {
        return (soMu == other.soMu && heSo == other.heSo);
    }

    bool operator!=(const DonThuc& other) const {
        return !(*this == other);
    }

    bool operator>(const DonThuc& other) const {
        if (soMu != other.soMu) {
            cerr << "Khong the so sanh don thuc khac bac!\n";
            return false;
        }
        return heSo > other.heSo;
    }

    bool operator<(const DonThuc& other) const {
        if (soMu != other.soMu) {
            cerr << "Khong the so sanh don thuc khac bac!\n";
            return false;
        }
        return heSo < other.heSo;
    }
};

int main() {
    DonThuc a, b;
    cout << "Nhap don thuc a:\n";
    a.nhap();
    cout << "Nhap don thuc b:\n";
    b.nhap();

    cout << "\nDon thuc a = "; a.xuat();
    cout << "\nDon thuc b = "; b.xuat();

    cout << "\n\nGia tri a tai x=2: " << a.giaTri(2);
    cout << "\nDao ham cua a: "; a.daoHam().xuat();
    cout << "\nNguyen ham cua a: "; a.nguyenHam().xuat();

    cout << "\n\nTong a+b = "; (a + b).xuat();
    cout << "\nHieu a-b = "; (a - b).xuat();
    cout << "\nTich a*b = "; (a * b).xuat();
    cout << "\nThuong a/b = "; (a / b).xuat();

    cout << "\n\nSo sanh: ";
    if (a == b) cout << "a bang b";
    else if (a > b) cout << "a lon hon b";
    else if (a < b) cout << "a nho hon b";
    cout << endl;

    return 0;
}
*/

//Bài 3.4
/*

class HocSinh {
private:
    string hoTen;
    double diemVan;
    double diemToan;

public:
    // --- Constructor ---
    HocSinh(string ten = "", double van = 0, double toan = 0)
        : hoTen(ten), diemVan(van), diemToan(toan) {}

    // --- Nhập & Xuất ---
    void nhap() {
        cin.ignore(); // bỏ ký tự xuống dòng còn sót lại
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap diem Van: ";
        cin >> diemVan;
        cout << "Nhap diem Toan: ";
        cin >> diemToan;
    }

    void xuat() const {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Diem Van: " << diemVan << endl;
        cout << "Diem Toan: " << diemToan << endl;
        cout << "Diem TB: " << tinhDTB() << endl;
        cout << "Xep loai: " << xepLoai() << endl;
    }

    // --- Getter ---
    string getHoTen() const { return hoTen; }
    double getDiemVan() const { return diemVan; }
    double getDiemToan() const { return diemToan; }

    // --- Setter ---
    void setHoTen(string ten) { hoTen = ten; }
    void setDiemVan(double van) { diemVan = van; }
    void setDiemToan(double toan) { diemToan = toan; }

    // --- Điểm trung bình ---
    double tinhDTB() const {
        return (diemVan + diemToan) / 2.0;
    }

    // --- Xếp loại ---
    string xepLoai() const {
        double dtb = tinhDTB();
        if (dtb >= 8.0) return "Gioi";
        else if (dtb >= 7.0) return "Kha";
        else if (dtb >= 5.0) return "Trung binh";
        else return "Yeu";
    }
};

int main() {
    HocSinh hs;
    cout << "Nhap thong tin hoc sinh:\n";
    hs.nhap();

    cout << "\nThong tin vua nhap:\n";
    hs.xuat();

    return 0;
}
*/

//Bài 3.5
/*

class Mang {
private:
    int *arr;
    int n;

public:
    // --- Constructor & Destructor ---
    Mang(int size = 0) {
        n = size;
        if (n > 0) arr = new int[n];
        else arr = nullptr;
    }

    ~Mang() {
        delete[] arr;
    }

    // --- Nhập mảng ---
    void nhap() {
        cout << "Nhap so phan tu: ";
        cin >> n;
        delete[] arr;
        arr = new int[n];
        cout << "Nhap " << n << " phan tu:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    // --- Xuất mảng ---
    void xuat() const {
        cout << "Mang: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // --- Lấy kích thước mảng ---
    int getSize() const {
        return n;
    }

    // --- Lấy phần tử tại vị trí ---
    int getAt(int index) const {
        if (index < 0 || index >= n) {
            cerr << "Vi tri khong hop le!\n";
            return -1;
        }
        return arr[index];
    }

    // --- Gán giá trị cho phần tử tại vị trí ---
    void setAt(int index, int value) {
        if (index < 0 || index >= n) {
            cerr << "Vi tri khong hop le!\n";
            return;
        }
        arr[index] = value;
    }

    // --- Tìm phần tử ---
    int find(int value) const {
        for (int i = 0; i < n; i++) {
            if (arr[i] == value) return i; // trả về vị trí đầu tiên
        }
        return -1; // không tìm thấy
    }

    // --- Sắp xếp tăng ---
    void sortAsc() {
        sort(arr, arr + n);
    }

    // --- Sắp xếp giảm ---
    void sortDesc() {
        sort(arr, arr + n, greater<int>());
    }
};

int main() {
    Mang m;
    m.nhap();
    m.xuat();

    cout << "Kich thuoc mang = " << m.getSize() << endl;

    int pos;
    cout << "Nhap vi tri can lay phan tu: ";
    cin >> pos;
    cout << "Phan tu tai vi tri " << pos << " = " << m.getAt(pos) << endl;

    int value;
    cout << "Nhap vi tri va gia tri moi: ";
    cin >> pos >> value;
    m.setAt(pos, value);
    m.xuat();

    cout << "Nhap phan tu can tim: ";
    cin >> value;
    int idx = m.find(value);
    if (idx != -1) cout << "Tim thay tai vi tri " << idx << endl;
    else cout << "Khong tim thay!\n";

    cout << "\nSap xep tang dan:\n";
    m.sortAsc();
    m.xuat();

    cout << "\nSap xep giam dan:\n";
    m.sortDesc();
    m.xuat();

    return 0;
}
*/
