/*
Câu 2.3: a. Xây dựng một lớp SV để mô tả các sinh viên trong một Khoa của một Trường Đại học, lớp SV gồm các
thành phần sau:
- Lop: Mô tả lớp học của sinh viên.
- Hoten: Mô tả họ tên của sinh viên.
- Hàm thiết lập.
- Hàm huỷ bỏ.
- Hàm hiển thị thông tin về một SV.
b. Xây dựng một lớp SVSP để mô tả các sinh viên thuộc hệ sư phạm. Lớp được kế thừa từ lớp SV và bổ sung thêm
các thành phần sau:
- Dtb: Mô tả điểm trung bình của sinh viên.
- Hocbong: Mô tả học bổng của sinh viên.
- Hàm thiết lập.
- Hàm hiển thị thông tin về một SVSP.
c. Xây dựng một lớp SVCN để mô tả các sinh viên thuộc hệ cử nhân. Lớp được kế thừa từ lớp SVSP và bổ sung thêm
các thành phần sau:
- Hocphi: Mô tả học phí của sinh viên cử nhân.
- Hàm thiết lập.
- Hàm hiển thị thông tin về một SVCN.
*/

#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string lop;
    string hoTen;
public:
    SinhVien(string lop, string hoTen);
    ~SinhVien() {}
    void hienThi();
    string getLop() {return lop;}
    string getHoTen() {return hoTen;}
};

SinhVien::SinhVien(string lop, string hoTen) {
    this->lop = lop;
    this->hoTen = hoTen;
}

void SinhVien::hienThi() {
    cout << "Ho ten: " << hoTen;
    cout << "\nLop: " << lop;
}

class SinhVienSP:public SinhVien {
private:
    float diemTB;
    string hocBong;
public:
    SinhVienSP(string lop, string hoTen, float diemTB, string hocBong);
    ~SinhVienSP() {}
    void hienThi();
    float getDiemTB() {return diemTB;}
    string getHocBong() {return hocBong;}
};

SinhVienSP::SinhVienSP(string lop, string hoTen, float diemTB, string hocBong)
:SinhVien(lop, hoTen)
{
    this->diemTB = diemTB;
    this->hocBong = hocBong;
}

void SinhVienSP::hienThi() {
    cout << "\nHo ten: " << getHoTen();
    cout << "\nLop: " << getLop();
    cout << "\nDiem trung binh: " << diemTB;
    cout << "\nHoc bong: " << hocBong;
}

class SinhVienCN:public SinhVienSP {
private:
    string hocPhi;
public:
    SinhVienCN(string lop, string hoTen, float diemTB, string hocBong, string hocPhi);
    ~SinhVienCN() {}
    void hienThi();
};

SinhVienCN::SinhVienCN(string lop, string hoTen, float diemTB, string hocBong, string hocPhi)
:SinhVienSP(lop, hoTen, diemTB, hocBong)
{
    this->hocPhi = hocPhi;
}

void SinhVienCN::hienThi() {
    cout << "\nHo ten: " << getHoTen();
    cout << "\nLop: " << getLop();
    cout << "\nDiem trung binh: " << getDiemTB();
    cout << "\nHoc bong: " << getHocBong();
    cout << "\nHoc phi: " << hocPhi;
}

int main()
{
    SinhVien sv1("KTPM1", "Nguyen Van A");
    sv1.hienThi();

    SinhVienSP svsp1("SPToan", "Le Thi B", 8.5, "2.000.000 VND");
    svsp1.hienThi();

    SinhVienCN svcn1("CNTT1", "Tran Van C", 7.8, "1.000.000 VND", "5.000.000 VND");
    svcn1.hienThi();

    return 0;
}
