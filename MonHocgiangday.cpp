#include<iostream>
#include<stdio.h>
using namespace std;
class MonHoc{
	private:
		string MaMon, TenMon;
	protected:
		int SoTinChi;
	public:
		MonHoc(string MaMon="",string TenMon="",int SoTinChi=0){
			this->MaMon=MaMon;
			this->TenMon=TenMon;
			this->SoTinChi=SoTinChi;
		}
		~MonHoc(){
		}
		void Nhap(){
			cout<<"nhap ma mon: ";
			cin.ignore();
			getline(cin, MaMon);
			cout<<"nhap ten mon: ";
			getline(cin,TenMon);
			cout<<"nhap so tin chi: ";
			cin>>SoTinChi;
		}
		void Xuat() const{
			cout<<MaMon<<"\t "<<TenMon<<"\t "<<SoTinChi;
		}
};
class GiangDay:public MonHoc{
	private:
		string MaGiangVien, MaLop;
		int SoTietDaDay;
	public:
		GiangDay():MonHoc(){
			MaGiangVien="";
			MaLop="";
			SoTietDaDay=0;
		}
		~GiangDay(){
		}
		void Nhap(){
			MonHoc::Nhap();
			cout<<"nhap ma giang vien: ";
			cin.ignore();
			getline(cin,MaGiangVien);
			cout<<"nhap ma lop: ";
			getline(cin,MaLop);
			cout<<"nhap so tiet da day: ";
			cin>>SoTietDaDay;
		}
		void Xuat() const{
			MonHoc::Xuat();
			cout<<MaGiangVien<<"\t "<<MaLop<<"\t "<<SoTietDaDay<<endl;
		}
		int SoTietConLai() const{
			return SoTinChi*20-SoTietDaDay;
		}
};
void SapXep(GiangDay *a, int n){
	GiangDay tg;
	for(int i=0;i<n-1;i++)
	for(int j=i+1;j<n;j++)
	    if(a[i].SoTietConLai()<a[j].SoTietConLai()){
	    	tg=a[i];
	    	a[i]=a[j];
	    	a[j]=tg;
		}
}
main(){
	MonHoc t;
	t.Nhap();
	cout<<"\n In thong tin \n";
	t.Xuat();
	int n;
	cout<<"\n nhap n= ";
	cin>>n;
	GiangDay *a = new GiangDay[n];
	cout<<"\n nhap thong tin mon hoc \n";
	for(int i=0;i<n;i++)
	   a[i].Nhap();
	cout<<"\n In thong tin \n";
	for(int i=0;i<n;i++){
	   a[i].Xuat();
	   cout<<a[i].SoTietConLai()<<endl;
        }
    SapXep(a,n);
    cout<<"\n In thong tin sap xep giam \n";
	for(int i=0;i<n;i++){
	   a[i].Xuat();
	   cout<<a[i].SoTietConLai()<<endl;
         }
}
