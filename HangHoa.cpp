#include<iostream>
#include<stdio.h>
using namespace std;
class HangHoa{
	private:
		string MaHang, TenHang;
	public:
		HangHoa(string MaHang="",string TenHang=""){
			this->MaHang=MaHang;
			this->TenHang=TenHang;
		}
		~HangHoa(){
		}
		void Nhap(){
			cout<<"nhap ma hang: ";
			cin.ignore();
			getline(cin,MaHang);
			cout<<"nhap ten hang: ";
			getline(cin,TenHang);
		}
		void Xuat() const{
			cout<<MaHang<<"\t"<<TenHang<<"\t";
		}
};
class MayTinh:public HangHoa{
	private:
		string NhaSanXuat;
		int NamSanXuat, GiaBanNiemYet;
	public:
		static float TiLeChietKhau;
	public:
		MayTinh(){
			NhaSanXuat="";
			NamSanXuat=0;
			GiaBanNiemYet=0;
		}
		~MayTinh(){
		}
		void Nhap(){
			HangHoa::Nhap();
			cout<<"Nha san xuat: ";
			cin.ignore();
			getline(cin,NhaSanXuat);
			cout<<"Nam san xuat: ";
			cin>>NamSanXuat;
			cout<<"Gia ban niem yet: ";
			cin>>GiaBanNiemYet;
		}
		void Xuat() const{
			cout<<NhaSanXuat<<"\t"<<NamSanXuat<<"\t"<<GiaBanNiemYet<<endl;
		}
		float GiaNhap() const{
			return GiaBanNiemYet - GiaBanNiemYet*TiLeChietKhau;
		}
};
float MayTinh::TiLeChietKhau = 0.2;
void min_GiaNhap(MayTinh *a,int n){
	float min=a[0].GiaNhap();
	for(int i=0;i<n;i++)
	        if(min>a[i].GiaNhap())
	                min = a[i].GiaNhap();
	cout<<"\n Gia nhap thap nhat: "<<min;
}
main(){
	HangHoa t("N12","Laptop");
	cout<<"\n In thong tin \n";
	t.Xuat();
	int n;
	cout<<"\n nhap n=";
	cin>>n;
	MayTinh *a = new MayTinh[n];
	for(int i=0;i<n;i++){
	    cout<<" nhap thong tin may tinh "<<i<<endl;
	    a[i].Nhap();
	}
	cout<<"\n In thong tin \n";
	for(int i=0;i<n;i++)
	    a[i].Xuat();
	min_GiaNhap(a,n);
}
