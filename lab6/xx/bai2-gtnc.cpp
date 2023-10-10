#include<iostream>
using namespace std;

int In(int n)
{
	
	cout<<n<<" ";
	if(n==1)
	  return 1;
	else
	  return( In(n-2) );
}
int main()
{
	int n;
	cout<<" nhap n : ";
	cin>>n;
	if(n%2==0)
	   n=n-1;
//	cout<<In;
	In(n);
}
