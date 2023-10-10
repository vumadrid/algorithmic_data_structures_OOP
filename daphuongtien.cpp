#include<iostream>
#include<stdio.h>
using namespace std;
class DaPhuongTien{
	private:
		string TenGoi;
		int GiaBan;
	public:
		DaPhuongTien(string TenGoi="", int GiaBan = 0);
		~DaPhuongTien();
		void Nhap();
		void Xuat() const;
};
class SachDienTu{
	private:
		string TenGia;
		int SoTrang;
	public:
		SachDienTu();
		~SachDienTu();
		friend void operator>> (istream &is, SachDienTu &s);
		friend void operator<< (ostream &os, const SachDienTu &s);
		bool KiemTraSoLuong (int SoTrang_SoSanh) const;
};
