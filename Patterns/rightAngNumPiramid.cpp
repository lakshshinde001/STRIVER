#include<iostream>
using namespace std;

void rightAngledNumberPiramid(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;cin>>n;
    rightAngledNumberPiramid(n);
    return 0;
}