#include<iostream>
using namespace std;

void pattern(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" ";
        }
        for(int k=1; k<=i*2-1; k++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            cout<<" ";
        }
        for(int k=0; k<n*2-i*2-1; k++){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main()
{
    pattern(5);
    return 0;
}