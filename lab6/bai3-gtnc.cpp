#include<iostream>
using namespace std;
int In(int n)
{
	cout<<n<<" ";
	if(n==0)
	  return 0;
	else
	  return( In(n-2) );
}
int main()
{
	int n;
	cout<<" nhap n : ";
	cin>>n;
	if(n%2==1)
	   n=n-1;
	In(n);
}
