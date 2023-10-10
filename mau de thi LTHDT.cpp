#include<iostream>
#include<stdio.h>
using namespace std;
class GiangVien{
	private:
		string MaGiangVien;
		string TenGiangVien;
	protected:
		string BoMon;
	public:
		GiangVien(){
			MaGiangVien="";
			TenGiangVien="";
			BoMon="";	
		}
		~GiangVien(){
		}
		void Nhap(){
			cout<<"nhap ma giang vien: ";cin.ignore();
			getline(cin, MaGiangVien);
			cout<<"Nhap ten giang vien: ";
			getline(cin, TenGiangVien);
			cout<<"Nhap bo mon: ";
			getline(cin, BoMon);
		}
		void Xuat() const{
		cout<<MaGiangVien<<"\t"<<TenGiangVien<<"\t"<<BoMon<<"\t";
		}
};

class GiangDay:public GiangVien{
	
	private:
		string MaMon;
		string MaLop;
		int SoTinChi;
	public:
		GiangDay():GiangVien(){
		MaMon="";
		MaLop="";
		SoTinChi=0;
		}
		~GiangDay(){
			
		}

		friend void operator>>(istream &is, GiangDay &s){
		   s.Nhap();
		   cout<<"Nhap ma mon: ";
		   is.ignore();
		   getline(is, s.MaMon);
		   cout<<"Nhap ma lop:";
		   getline(is, s.MaLop);
		   cout<<"So Tin chi: ";
		   cin>>s.SoTinChi;
		}
		friend void operator<<(ostream &os, const GiangDay &s){
			s.Xuat();
			os<<s.MaMon<<"\t"<<s.MaLop<<"\t"<<s.SoTinChi<<"\t"<<endl;
		}
		bool KiemTra (string BoMon_SoSanh) const{
			if(BoMon==BoMon_SoSanh)
			return true;
		return false;
		}
};
main(){
	GiangVien g;
	g.Nhap();
	cout<<"\n In thong tin \n";
	g.Xuat();
	int n;
	cout<<"Nhap n=";
	cin>>n;
	GiangDay *a = new GiangDay[n];
	cout<<"\n Nhap thong tin giangday \n";
	for (int i=0;i<n;i++)
	    cin>>a[i];
	cout<<"\n In thong tin \n";
	for (int i=0;i<n;i++)
	    cout<<a[i];
	 int dem=0;
	for (int i=0;i<n;i++)
	        if(a[i].KiemTra("cong nghe phan mem")){
	        	dem++;
			}
	if(dem){
		cout<<"\n thong tin giang day bo mon cnpm \n";
		for (int i=0;i<n;i++)
	        if(a[i].KiemTra("cong nghe phan mem")){
	        	cout<<a[i];
	}

	else
	    cout<<"\n khong co doi tuong giang day thuoc cnpm ";
}
}
