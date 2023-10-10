#include<iostream>
#include<stdio.h>
using namespace std;
class DaPhuongTien{
	private:
		string TenGoi;
		int GiaBan;
	public:
		DaPhuongTien(string TenGoi="", int GiaBan = 0){
			this->TenGoi=TenGoi;
			this->GiaBan=GiaBan;
		}
		~DaPhuongTien(){
			
		}
		void Nhap(){
			cout<<"nhap ten goi: ";
			cin.ignore();
			getline(cin,TenGoi);
			cout<<"nhap gia ban: ";
			cin>>GiaBan;
		}
		void Xuat() const{
			cout<<TenGoi<<"\t"<<GiaBan<<"\t";
		}
};
class SachDienTu:public DaPhuongTien{
	private:
		string TenGia;
		int SoTrang;
	public:
		SachDienTu():DaPhuongTien(){
			TenGia = "";
			SoTrang = 0;
		}
		~SachDienTu(){
			
		}
		friend void operator>> (istream &is, SachDienTu &s){
			s.Nhap();
			cout<<"nhap ten gia: ";
			is.ignore();
			getline(is,s.TenGia);
			cout<<"nhap so trang: ";
			is>>s.SoTrang;
		}
		friend void operator<< (ostream &os, const SachDienTu &s){
			s.Xuat();
			os<<s.TenGia<<"\t"<<s.SoTrang<<endl;
		}
		bool KiemTraSoLuong (int SoTrang_SoSach) const{
			return SoTrang < SoTrang_SoSach;
	}
};
main(){
	DaPhuongTien h("laptop",2500);
	cout<<"\n In thong tin \n";
	h.Xuat();
	int n;
	cout<<"nhap n doi tuong: ";
	cin>>n;
	SachDienTu *a =new SachDienTu[n];
	for(int i=0;i<n;i++){
			cout<<" nhap thong tin da phuong tien "<<i<<endl;
			cin>>a[i];}
	cout<<"\n In thong tin \n ";
	for(int i=0;i<n;i++)
	   cout<<a[i];
	int dem=0;
    for(int i=0;i<n;i++)
          if(a[i].KiemTraSoLuong(50)==true)
               dem++;
    if(dem){
    	cout<<"\n so trang < 50 \n";
    for(int i=0;i<n;i++)
          if(a[i].KiemTraSoLuong(50)==true)
              cout<<a[i];
	}
	else
	     cout<<"so trang nho 50";
}
