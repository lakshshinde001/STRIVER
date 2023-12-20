#include<iostream>
using namespace std;

void printt(int n){
    for(int i =n; i>0; i--){
        for(int j=n; j>0; j--){
            for(int k=i; k>0; k--){
                cout<<j<<" ";
            }
        }
        cout<<"$";
    }
}
int main()
{
    printt(3);
    return 0;
}