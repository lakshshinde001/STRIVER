#include<iostream>
using namespace std;

void invertedRightPiramid(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;cin>>n;
    invertedRightPiramid(n);
    return 0;
}