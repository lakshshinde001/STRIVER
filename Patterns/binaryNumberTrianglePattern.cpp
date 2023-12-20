#include<iostream>
using namespace std;

void pattern(int n){

    int start = 1;
    for(int i=0; i<n; i++){

        if(i%2 == 0){
            start = 1;
        }
        if(i%2 != 0){
            start = 0;
        }
        for(int j=0; j<=i; j++){
            cout<<start;
            start = 1 - start;
        }
        cout<<endl;
    }
}

int main()
{
    pattern(4);
    return 0;
}