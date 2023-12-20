#include<iostream>
using namespace std;

class stack{
    public :
        int *arr;
        int top;
        int size;

    stack(int size) : size(size){
        top = -1;
        arr = new int[size];
    }
    bool isEmpty(){
        return top == -1;
    }

    int push(int data){
        if(top == size){
            cout<<"\nStack Overflows...";
            return 0;
        }
        top++;
        arr[top] = data;
        return top;
    }
    int pop(){
        if(top == -1){
            cout<<"\nStack is Empty...Nothing here to delete ";
            return 0;
        }
        int popped = arr[top];
        top--;
        return popped;
    }
};
int main(){
    stack s(5);

    while(true){

        cout<<"\n----------------Stack Operations--------------";
        cout<<"\n   1.---------Push------------";
        cout<<"\n   2.---------Pop-------------";
        cout<<"\n   3.---------Display---------";
        cout<<"\n   4.---------Exit------------";

        cout<<"\nEnter your choice : ";
        int choice; cin>>choice;

        switch (choice){
            case 1 : cout<<"\nEnter data to be inserted : ";
                     int data; cin>>data;
                     cout<<s.push(data)<<" Inserted...Succeesfully : ";
                     break;
            case 2 : cout<<s.pop()<<" Deleted Successfully..."; break;
            case 3 : 
                     if(s.isEmpty()){
                        cout<<"\nStack is Empty...";
                     }
                     while(!s.isEmpty()){
                        cout<<s.pop()<<endl;
                     }; break;
            case 4 : cout<<"\nExiting the Program..."; return 0;
        }
    }
    
    return 0;
}