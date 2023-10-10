#include<iostream>
#include<stdio.h>
using namespace std;
class DaPhuongTien{
	private:
		string TenGoi;
		int GiaBan;
	public:
		DaPhuongTien(string TenGoi="",int GiaBan=0){
			this->TenGoi=TenGoi;
			this->GiaBan=GiaBan;
		}
		~DaPhuongTien(){
		}
		void Nhap(){
			cout<<"nhap ten goi: ";
			cin.ignore();
			getline(cin, TenGoi);
			cout<<"nhap gia ban: ";
			cin>>GiaBan;
		}
		void Xuat() const{
			cout<<TenGoi<<"\t "<<GiaBan<<"\t ";
		}
};
class Video:public DaPhuongTien{
	private:
		string DaoDien;
		int ThoiLuong;
	public:
		Video():DaPhuongTien(){
			DaoDien="";
			ThoiLuong=0;
		}
		~Video(){
			
		}
		friend void operator>>(istream &is, Video &s){
			s.Nhap();
			cout<<"nhap dao dien: ";
			cin.ignore();
			getline(is,s.DaoDien);
			cout<<"nhap thoi luong: ";
			is>>s.ThoiLuong;
		}
		friend void operator<<(ostream &os, const Video &s){
			s.Xuat();
			os<<s.DaoDien<<"\t"<<s.ThoiLuong<<"\t "<<endl;
		}
		bool KiemTra (string DaoDien_SoSanh) const{
			if(DaoDien==DaoDien_SoSanh)
			    return true;
			return false;
		}
};
main(){
	DaPhuongTien t;
	t.Nhap();
	cout<<"\n In thong tin \n";
	t.Xuat();
	int n;
	cout<<"\n nhap n= ";
	cin>>n;
	Video *a = new Video[n];
	for(int i=0;i<n;i++){
			cout<<"\n nhap thong tin video \n";
	      cin>>a[i];
	  }
	cout<<"\n In thong tin \n";
	for(int i=0;i<n;i++)
	      cout<<a[i];
	int dem=0;
    for(int i=0;i<n;i++)
          if(a[i].KiemTra("Le Khanh")==true)
               dem++;
    if(dem){
    	cout<<"\n in thong tin phim dao dien le khanh thuc hien \n";
    for(int i=0;i<n;i++)
          if(a[i].KiemTra("Le Khanh")==true)
              cout<<a[i];
	}
	else
	     cout<<"in thong tin phim dao dien le khanh thuc hien";
}
