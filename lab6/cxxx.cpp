#include<iostream>
using namespace std;
int deQui(int i, int n)
{
	if (i == 0)
		return n;
	else
	{
		n = n*10 + i%10;
		return deQui(n/10, n);
	}
}
main(){
	int n;
	cin>>n;
	cout<<"nhap n: ";
		n = n*10 + i%10;
		return deQui(n/10, n);
}
