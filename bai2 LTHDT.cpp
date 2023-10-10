#include<iostream>
#include<stdio.h>
using namespace std;
class ThiSinh{
	private:
		string SoBaoDanh;
		string HoTen;
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
			getline(cin, SoBaoDanh);
			cout<<"nhap ho ten: ";
			getline(cin, HoTen);
			cout<<"diem uu tien: ";
			cin>>DiemUuTien;
		}
		void Xuat() const{
			cout<<SoBaoDanh<<"\t"<<HoTen<<"\t"<<DiemUuTien<<"\t";
		}
};
class ThiSinhKhoiA:public ThiSinh{
	private:
		float DiemToan, DiemLy, DiemHoa;
	public:
		ThiSinhKhoiA(){
            DiemToan=0;
            DiemLy=0;
            DiemHoa=0;
		}
		~ThiSinhKhoiA(){
			
		}
		void Nhap(){
			ThiSinh::Nhap();
			cout<<"Diem toan: ";
			cin>>DiemToan;
			cout<<"Diem Ly: ";
			cin>>DiemLy;
			cout<<"Diem Hoa: ";
			cin>>DiemHoa;
		}
		void Xuat() const{
			ThiSinh::Xuat();
			cout<<DiemToan<<"\t"<<DiemLy<<"\t"<<DiemHoa<<endl;
		}
		float TongDiem() const{
			return DiemToan+DiemLy+DiemHoa+DiemUuTien;
		}
		bool XetTuyen() const{
			if(TongDiem()>=24.25)
			          return true;
			return false;
		}
};
main(){
	ThiSinh t("M333","Le Tuan Vu",2);
	cout<<"\n in thong tin \n";
	t.Xuat();
	int n;
	cout<<"nhap so thi sinh: ";
	cin>>n;
	ThiSinhKhoiA *a = new ThiSinhKhoiA[n];
	cout<<"\n nhap thong tin thi sinh khoi a \n";
	for(int i=0;i<n;i++)
	    a[i].Nhap();
	cout<<"\n in thong tin \n";
	for (int i=0;i<n;i++){
	    a[i].Xuat();
	    cout<<a[i].TongDiem()<<endl;
	}
	cout<<"\n danh sach trung tuyen \n";
	for (int i=0;i<n;i++)
	    if(a[i].XetTuyen()){
	    	a[i].Xuat();
	    cout<<a[i].TongDiem()<<endl;
		}
}
