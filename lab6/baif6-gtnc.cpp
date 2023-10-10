#include<iostream>
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
void in(int a[],int n)
{
	if(n>0)
	{
		cout<<a[n]<<" ";
     	in(a,n-1);
	}
	
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
//	for(i=0;i<=n;i++)
//	{
//		cout<<"a["<<n<<"] =";
//		cout<<a[i]<<"  ";
//		
//	}

  in(a,n);
  cout<<" tong cac gia tri cua mang la "<<tong(a,n);
}
