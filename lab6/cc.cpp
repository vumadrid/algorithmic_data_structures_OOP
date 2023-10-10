#include<string>
#include<iostream>
using namespace std;

string Sodaonguoc( int n)
{
   int t=n%10;
     if(n!=0)
    cout<<t<<" ";
   Sodaonguoc(n/10);
}
main(){
	int n;
	cin>>n;
	cout<<"in chuoi: ";
	Sodaonguoc(n/10);
	return 0 ;
}
