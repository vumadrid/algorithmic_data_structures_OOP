#include<iostream>
#include<stdio.h>
using namespace std;
class Nguoi{
	private:
		string MaDinhDanh, HoTen;
	protected:
		int NamSinh;
	public:
		Nguoi();
		~Nguoi();
		void Nhap();
		void Xuat() const;
};
class NhanVien{
	private:
		float HeSoLuong;
		int TienPhuCap;
	public:
		NhanVien();
		~NhanVien();
		void Nhap();
		void Xuat() const;
		bool operator> (const NhanVien &b);
};

