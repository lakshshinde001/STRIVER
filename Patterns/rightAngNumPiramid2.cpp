#include<iostream>
using namespace std;

void rightAngleNumberPiramid2(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;cin>>n;
    rightAngleNumberPiramid2(n);
    return 0;
}