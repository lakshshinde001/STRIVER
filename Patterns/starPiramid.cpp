#include<iostream>
using namespace std;

void pattern(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            cout<<" ";
        }
        for(int k=0; k<=i; k++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main()
{
    int n; cin>>n;

    pattern(n);
    return 0;
}