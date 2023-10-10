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
			this->SoBaoDanh =SoBaoDanh;
			this->HoTen =HoTen;
			this->DiemUuTien =DiemUuTien;
		}
		~ThiSinh(){
		}
		void nhap(){
			cout<<"Nhap so bao danh :";
			cin.ignore();
			getline(cin,SoBaoDanh);
			cout<<"Nhap ho ten :";
			getline(cin,HoTen);
			cout<<"Nhap diem uu tien :";
			cin>>DiemUuTien;
		}
		void xuat() const{
			cout<<SoBaoDanh<<"\t"<<HoTen<<"\t"<<DiemUuTien<<"\t"<<endl;
		}
};
class ThiSinhKhoiD :public ThiSinh{
	private:
		float DiemVan, DiemToan, DiemAnh;
	public:
		ThiSinhKhoiD(){
			DiemVan=0;
			DiemToan=0;
			DiemAnh=0;
		}
		~ThiSinhKhoiD(){
		}
		float TongDiem() const{
			return DiemVan+DiemToan+DiemAnh+DiemUuTien;
		}
		friend void operator>> (istream &is, ThiSinhKhoiD &s){
			s.nhap () ;
			cout<<"Nhap diem van :";
			cin.ignore();
			is>>s.DiemVan;
			cout<<"nhap diem toan: ";
			is>>s.DiemToan;
			cout<<"nhap diem anh: ";
			is>>s.DiemAnh;
		}
		friend void operator<< (ostream &os, const ThiSinhKhoiD &s){
			s.xuat () ;
			os<<s.DiemVan <<"\t"<<s.DiemToan <<"\t"<<s.DiemAnh <<"\t"<<endl;
		}

};
float maxdiem(ThiSinhKhoiD*d, int n){
			float max= d[0].TongDiem() ;
			for(int i=0;i<n;i++)
				if(max<d[i].TongDiem() )
					max=d[i].TongDiem() ;
					return max;
		}
main(){
	ThiSinh t("d12","Hoa lan",1);
	cout<<"\n\t\t THONG TIN 1 THI SINH \n";
	t.xuat();
	int n;
	cout<<"\n Nhap so luong thi sinh khoi D";
	cin>>n;
	ThiSinhKhoiD *d=new ThiSinhKhoiD[n];
	cout<<"\nNhap thong tin thi sinh khoi D\n";
	for(int i=0;i<n;i++)
		cin>>d[i];
	cout<<"\n\t\t THONG TIN THI SINH KHOI D\n";
	for(int i=0;i<n;i++){
		cout<<d[i]  ;
		cout<<"\n tong diem "<<d[i].TongDiem()<<"\n" ;
	}
	cout<<"\n\t\t THONG TIN THI SINH CO DIEM CAO NHAT \n";
	for(int i=0;i<n;i++)
	if(maxdiem(d,n)==d[i].TongDiem() ){
		cout<<d[i] ;
		cout<<"tong diem ="<<d[i].TongDiem() ;
	}
}

