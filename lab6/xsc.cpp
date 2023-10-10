#include <iostream>
using namespace std;
void mang(int a[],int n)
{  
     
	if(n>0)
    {
    	cout<<"a["<<n<<"]";
	    cin>>a[n];
		mang(a,n-1);
//		cout<<"|"<<a[n]<<"|";

	}
	
}
void In(int a[], int n) {
    if(n==0) return ;
    In(a,n-1);
    cout<<a[n]<<" ";
}
int t=0;
int tong(int a[], int n)
{   
    
	if(n>0)
	{
		t=t+a[n];
		tong(a,n-1);
	}
	return t;
}
int main()
{
    int a[100];
	int n;
	cout<<" nhap so  ";
	cin>>n;
	int i;
	
	mang(a,n);

  In(a,n);
  cout<<" tong cac gia tri cua mang la "<<tong(a,n);
}
