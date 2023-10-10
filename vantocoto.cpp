#include<iostream>
#include<stdio.h>
using namespace std;
class PhuongTienGiaoThong{
	private:
		string HangSanXuat, TenPhuongTien;
	protected:
		float VanTocToiDa;
	public:
		PhuongTienGiaoThong(){
			HangSanXuat=" ";
			TenPhuongTien=" ";
			VanTocToiDa=0;
		}
		~PhuongTienGiaoThong(){
		}
		void Nhap(){
			cout<<"nhap hang san xuat: ";
			cin.ignore();
			getline(cin,HangSanXuat);
			cout<<"nhap ten phuong tien: ";
			getline(cin,TenPhuongTien);
			cout<<"nhap van toc toi da: ";
			cin>>VanTocToiDa;
		}
		void Xuat(){
			cout<<HangSanXuat<<"\t "<<TenPhuongTien<<"\t "<<VanTocToiDa<<"\t ";
		}
};
class Oto:public PhuongTienGiaoThong{
	private:
		int SoBanh;
	public:
		Oto():PhuongTienGiaoThong(){
			SoBanh = 0;
		}
		~Oto(){
		}
		void Nhap(){
			PhuongTienGiaoThong::Nhap();
			cout<<"nhap so banh: ";
			cin>>SoBanh;
		}
		void Xuat(){
			PhuongTienGiaoThong::Xuat();
			cout<<SoBanh<<endl;
		}
		float VanTocCoSo() const{
			return VanTocToiDa/SoBanh;
		}
		bool operator < (const Oto &b) const{
			return this->VanTocCoSo() < b.VanTocCoSo();
		}
};
min_VanTocCoSo(Oto *a,int n){
	Oto min=a[0];
	for(int i=0;i<n;i++)
	    if(a[i]<min)
	        min=a[i];
	cout<<"\n oto co van toc co so nho nhat \n";
	for(int i=0;i<n;i++)
	     if(min.VanTocCoSo()==a[i].VanTocCoSo()){
		      a[i].Xuat();
	          cout<<"Van toc co so: "<<min.VanTocCoSo()<<endl;
     }
}
main(){
	PhuongTienGiaoThong t;
	t.Nhap();
	cout<<"\n In thong tin \n";
	t.Xuat();
	int n;
	cout<<"\n nhap n= \n ";
	cin>>n;
	Oto *a = new Oto[n];
	for(int i=0;i<n;i++)
		a[i].Nhap();
	cout<<"\n In thong tin \n";
	for(int i=0;i<n;i++)
	  a[i].Xuat();
	min_VanTocCoSo(a,n);
}
