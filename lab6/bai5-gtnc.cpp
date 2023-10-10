#include <iostream>
using namespace std;

void In(int a[100], int n) {
    if(n==0) return ;
    In(a,n-1);
    cout<<a[n-1]<<" ";
}

int main() {
    int n;
    int a[100];
    cout<<"nhap n = ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout<<"nhap a["<<i<<"] = ";
        cin >> a[i];
    }
    In(a, n);
    return 0;
}
