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
Nguoi::Nguoi(){
	MaDinhDanh="";
	HoTen="";
}
Nguoi::~Nguoi(){
}
void Nguoi::Nhap(){
	cout<<"nhap ma dinh danh: ";
	cin.ignore();
	getline(cin,MaDinhDanh);
	cout<<"nhap ho ten: ";
	getline(cin,HoTen);
}
void Nguoi::Xuat() const {
	cout<<MaDinhDanh<<"\t"<<HoTen<<"\t";
}
class NhanVien:public Nguoi{
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
NhanVien::NhanVien():Nguoi(){
	HeSoLuong=0;
	TienPhuCap=0;
}
NhanVien::~NhanVien(){
}
void NhanVien::Nhap(){
	cout<<"nhap he so luong: ";
	cin>>HeSoLuong;
	cout<<"tien phu cap: ";
	cin>>TienPhuCap;
}
void NhanVien::Xuat() const {
	cout<<HeSoLuong<<"\t"<<TienPhuCap<<"\t"<<endl;
}
bool NhanVien::operator> (const NhanVien &b){
			return this->HeSoLuong>b.HeSoLuong or ( this->HeSoLuong==b.HeSoLuong 
			and this->TienPhuCap>b.TienPhuCap);
		}
void max_hsl(NhanVien *a,int n){
	NhanVien max;
	for(int i=0;i<n;i++)
	    if(a[i]>max)
	      max =a[i];
	max.Xuat();
}
main(){
	Nguoi t;
	t.Nhap();
	cout<<"\n In thong tin \n";
	t.Xuat();
	int n;
	cout<<"\n nhap so nhan vien: ";
	cin>>n;
	NhanVien *a = new NhanVien[n];
	for (int i=0;i<n;i++)
	a[i].Nhap();
	cout<<"\n In thong tin \n";
	for(int i=0;i<n;i++)
	a[i].Xuat();
	cout<<"\n He so luong cao nhat \n";
	max_hsl(a,n);
}
