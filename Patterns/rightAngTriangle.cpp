#include<iostream>
using namespace std;

void rightAngledTriangle(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;cin>>n;
    rightAngledTriangle(n);
    return 0;
}