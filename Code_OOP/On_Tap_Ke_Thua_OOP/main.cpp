#include<iostream>
#include <string>
using namespace std;

class GiaoVien{
	private:
		string hoTen;
		float heSoLuong;
		int soNgayNghi;
	public:
		GiaoVien(string hoTen, float heSoLuong,int soNgayNghi);
		void hienThi();
		float tinhLuong();
		string getHoTen() {return hoTen;}
		float getHeSoLuong() {return heSoLuong;}
		int getSoNgayNghi() {return soNgayNghi;}
};

class GiaoVienCN:public GiaoVien{
	private:
		string lopCN;
	public:
		GiaoVienCN(string hoTen, float heSoLuong,int soNgayNghi,string lopCN);
		void hienThi();
		float tinhLuong();
};

GiaoVien::GiaoVien(string hoTen, float heSoLuong,int soNgayNghi)
{
	this->hoTen = hoTen;
	this->heSoLuong = heSoLuong;
	this->soNgayNghi = soNgayNghi;
}

void GiaoVien::hienThi(){
	cout << "Ho ten: " << hoTen << endl;
	cout << "He so luong: " << heSoLuong << endl;
	cout << "So ngay nghi: " << soNgayNghi << endl;
	cout << "Luong: " << tinhLuong() << endl;
}

float GiaoVien::tinhLuong(){
	return heSoLuong * 23450 - soNgayNghi * 10000;
}

GiaoVienCN::GiaoVienCN(string hoTen, float heSoLuong,int soNgayNghi,string lopCN)
:GiaoVien(hoTen, heSoLuong, soNgayNghi)
{
	this->lopCN = lopCN;
}

void GiaoVienCN::hienThi(){
	cout << "\nHo ten: " << getHoTen() << endl;
	cout << "He so luong: " << getHeSoLuong() << endl;
	cout << "So ngay nghi: " << getSoNgayNghi() << endl;
	cout << "Lop chu nhiem: " << lopCN << endl;
	cout << "Luong: " << tinhLuong() << endl;
}

float GiaoVienCN::tinhLuong(){
	return GiaoVien::tinhLuong() + 50000;
}

int main(){
	GiaoVien a("Dung", 3.0, 1);
	a.hienThi();
	GiaoVienCN b("Phuc", 3.0, 2, "12A5");
	b.hienThi();
}
