#include<iostream>
using namespace std;

void rectangularStar(int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main()
{
    int N;
    cout<<"\nEnter how many rows you want..";
    cin>>N;
    rectangularStar(N);
    return 0;
}