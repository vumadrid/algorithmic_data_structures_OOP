#include<iostream>
#include<string.h>
using namespace std;
int Inchuoi(char s[]){
	int n=strlen(s);
		for(int i=n-1;i>=0;i--){
		cout<<s[i];
	}
}
void InChuoiDQ(char s[], int i){
	if(i<0)
	return;
	cout<<s[i];
	InChuoiDQ(s,i-1);
}
main(){
	char s[100];
	cout<<"Nhap chuoi: ";
	gets(s);
	int n=strlen(s);
    InChuoiDQ(s,n-1);
}
