#include<iostream>
using namespace std;
void In(int i, int n){
if(i>n)
return;
cout<<i<<" ";
In(i+2,n);
}
main(){
	int n;
	cin>>n;
	cout<<"nhap n: ";
	In(1,n);
	return 0;
}
