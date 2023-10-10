#include<iostream>
#include<stdio.h>
using namespace std;
class ThiSinh{
	private:
		string SoBaoDanh, HoTen;
	protected:
		float DiemUuTien;
	public:
		ThiSinh(string SoBaoDanh="", string HoTen="", float DiemUuTien=0){
			this->SoBaoDanh=SoBaoDanh;
			this->HoTen=HoTen;
			this->DiemUuTien=DiemUuTien;
		}
		~ThiSinh(){
		}
		void Nhap(){
			cout<<"nhap so bao danh: ";
			cin.ignore();
			getline(cin,SoBaoDanh);
			cout<<"nhap ho ten: ";
			getline(cin,HoTen);
			cout<<"nhap diem uu tien: ";
			cin>> DiemUuTien;
			}
		void Xuat() const{
			cout<<SoBaoDanh<<"\t"<<HoTen<<"\t"<<DiemUuTien<<"\t";
		}
};

 class ThiSinhKhoiC:public ThiSinh{
	private:
		float DiemVan, DiemSu, DiemDia;
	public:
		ThiSinhKhoiC(){
			DiemVan=0;
			DiemSu=0;
			DiemDia=0;
		}
		~ThiSinhKhoiC(){
		}
		float TongDiem() const{
			return DiemVan + DiemSu + DiemDia + DiemUuTien;
		}
		friend void operator>>(istream &is, ThiSinhKhoiC &s){
			s.Nhap();
			cout<<"Nhap diem van: ";
			is>>s.DiemVan;
			cout<<"Nhap diem su: ";
			is>>s.DiemSu;
			cout<<"nhap diem dia: ";
			is>>s.DiemDia;
		}
		friend void operator<< (ostream &os, const ThiSinhKhoiC &s){
			s.Xuat();
			os<<s.DiemVan<<"\t"<<s.DiemSu<<"\t"<<s.DiemDia<<"\t"<<endl;
		}
};
main(){
	ThiSinh t("m222","Mai Lan",2);
	cout<<"\n In thong tin \n";
	t.Xuat();
	int n;
	cout<<"nhap n doi tuong thi sinh khoi c: ";
	cin>>n;
	ThiSinhKhoiC *a= new ThiSinhKhoiC[n];
	cout<<"\n nhap thong tin thi sinh khoi c \n";
	for(int i=0; i<n; i++)
	a[i].Nhap();
	cout<<"\n in thong tin \n";
	for (int i=0;i<n;i++){
	    a[i].Xuat();
	    cout<<a[i].TongDiem()<<endl;
	}
	
}
