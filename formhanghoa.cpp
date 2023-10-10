#include<iostream>
#include<stdio.h>
using namespace std;
class HangHoa{
	private:
		string MaHang, TenHang;
	public:
		HangHoa(string MaHang="",string TenHang="");
		~HangHoa();
		void Nhap();
		void Xuat() const;
};
class MaTinh{
	private:
		string NhaSanXuat;
		int NamSanXuat, GiaBanNiemYet;
	public:
		static float TiLeChietKhau;
	public:
		MayTinh();
		~MayTinh();
		void Nhap();
		void xuat() const;
		float GiaNhap() const;
};
