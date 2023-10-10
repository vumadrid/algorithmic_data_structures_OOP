#include<iostream>
using namespace std;

int UCLN(int A, int B) {
    if (B == 0)
        return A;
    return UCLN(B, A%B);
}
int main() {
    int A,B;
    cout<<" A= ";
    cin>>A;
    cout<<" B= ";
    cin>>B;
    
    cout << UCLN(A, B);
}
