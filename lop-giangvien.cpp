#include<iostream>
#include<stdio.h>
using namespace std;
class Giangvien{
	private:
		string Magiangvien, Tengiangvien;
	protected:
		string Bomon;
	public:
		Giangvien(){
			Magiangvien="";
			Tengiangvien="";
			Bomon="";
		}
		~Giangvien(){
			
		}
		void nhap(){
			cout<<"nhap ma giang vien :";cin.ignore();
			getline(cin,Magiangvien);
			cout<<"nhap ten giang vien :";
			getline(cin,Tengiangvien);
			cout<<"nhap bo mon :";
			getline(cin,Bomon);
		}
		void xuat() const{
			cout<<Magiangvien<<"\t"<<Tengiangvien<<"\t"<<Bomon;
		}
};

class Giangday:public Giangvien{
	private:
		string Mamon;
		string Malop;
	    int Sotinchi;
	public:
		Giangday(){
			Mamon="";
			Malop="";
			Sotinchi=0;
		}
		~Giangday(){
		}
		friend void operator>>(istream &is, Giangday &s){
			s.nhap() ;
			cout<<"nhap ma mon :";
			is.ignore();
		    getline(cin,s.Mamon);
			cout<<"nhap ma lop :";
			getline(cin,s.Malop );
			cout<<"nhap so tin chi :";
			is>>s.Sotinchi ;
		}
		friend void operator<<(ostream &os, const Giangday &s){
			s.xuat() ;
		    os<<"\t"<<s.Mamon <<"\t"<<s.Malop <<"\t"<<s.Sotinchi <<endl;
		}
		bool Kiemtra(string Bomon_Sosanh) const{
			if (Bomon==Bomon_Sosanh)
		    return true;
		return false;
		}
};
main(){
	Giangvien g;
	g.nhap() ;
	cout<<"\n\t\t IN THONG TIN 1 GIANG VIEN\n";
	g.xuat() ;
	int n;
	cout<<"\nnhap so giang day ";
	cin>>n;
	Giangday *a=new Giangday[n];
	for(int i=0;i<n;i++)
	    cin>>a[i];
	cout<<"\n\t\t IN THONG TIN GIANG DAY \n";
	for(int i=0;i<n;i++)
	    cout<<a[i];
	int dem=0;
	for(int i=0;i<n;i++)
	    if(a[i].Kiemtra("Cnpm") ){
	    	 dem++;
		}
	if(dem){
		cout<<"thong tin giang day bo mon CNPM";
		for(int i=0;i<n;i++)
		if(a[i].Kiemtra("Cnpm") )
		    cout<<a[i];
	else 
	    cout<<" khong thong tin giang day";
	}
}
