#include<iostream>
#include<stdio.h>
using namespace std;
class DaPhuongTien
{
private:
	string TenGoi;
	int GiaBan;
public:
	DaPhuongTien(string TenGoi="", int GiaBan=0){
		this->TenGoi=TenGoi;
		this->GiaBan = GiaBan;
	}
	~DaPhuongTien(){
	}
	void Nhap(){
		cout<<"Nhap ten goi :";
		cin.ignore();
		getline(cin,TenGoi);
		cout<<"Nhap gia ban :";
		cin>>GiaBan;
	}
	void Xuat() const{
		cout<<TenGoi<<"\t"<<GiaBan<<"\t";
	}
};
class SachDienTu:public DaPhuongTien
{
private:
	string TacGia;
	int SoTrang;
public:
	SachDienTu():DaPhuongTien(){
			TacGia="";
			SoTrang=0;	
		}
	~SachDienTu(){
	}
	friend void operator>>(istream &is, SachDienTu &s){
	  s.Nhap();
	  cout<<"Nhap tac gia :";
	  is.ignore();
	  getline(is,s.TacGia);
	  cout<<"Nhap so trang :";
	  is>>s.SoTrang;
	}
	friend void operator<<(ostream &os,const SachDienTu &s){
	s.Xuat();
	os<<s.TacGia<<"\t"<<s.SoTrang<<endl;
	}
	bool KiemTraSoLuong(int SoTrang_SoSanh) const{
		return SoTrang_SoSanh>SoTrang;
	}
};
main(){
	DaPhuongTien d("Sach moi ",2000);
	cout<<"\n\t\t IN THONG TIN \n";
	d.Xuat();
	int n;
	cout<<"\n Nhap so sach :";cin>>n;
	SachDienTu*a=new SachDienTu[n];
	for(int i=0;i<n;i++)
	    cin>>a[i];
	cout<<"\n\n\t\t IN THONG TIN SACH DIEN TU \n";
	for (int i=0;i<n;i++)
	    cout<<a[i];
	int dem=0;
	for(int i=0;i<n;i++)
	    if(a[i].KiemTraSoLuong(50)==true)
	        dem++;
	if(dem){
		cout<<"\n sach co so trang < 50 \n";
		for(int i=0;i<n;i++)
		    if(a[i].KiemTraSoLuong(50)== true)
		       cout<<a[i];
    else
        cout<<"\n ko co so trang < 50 \n";
}
}
