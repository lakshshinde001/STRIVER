/*
Implement stack using array 

#include<iostream>
using namespace std;

class stack{
	public : 
	static const int max = 6;
	int arr[max];
	int Top;
	
	stack(){
		Top = -1;
	}
	bool isEmpty(){
		return Top == -1;
	}
	bool isFull(){
		return Top == max - 1;
	}
	void push(int value){
		if(isFull()){
			cout<<"\nStack is Full, can't insert";
			return;
		}
		Top++;
		arr[Top] = value;
	}
	int pop(){
		if(isEmpty()){
			cout<<"\nStack is Empty.. can't delete ";
		}
		int data = arr[Top];
		Top--;
		return data;
	}
	int getTop(){
		if(isEmpty()){
			cout<<"\nStack is Emtpy..";
		}
		return arr[Top];	
	}
	
};           
int main(){
	
	stack s;
	
	s.push(10);
	s.push(20);
	s.push(30);
	s.pop();
	cout<<s.getTop();
	cout<<s.isFull();
	
//	while(!s.isEmpty()){
//		cout<<s.pop()<<endl;
//	}
	
	
	return 0;
}
*/

//Implement stack using Linked List

#include<iostream>
using namespace std;

class Node{
	public :
		int data;
		Node *next;
		
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

class stack{
	public :
		Node* Top;
		
	stack(){
		this->Top = NULL;
	}
	
	bool isEmpty(){
		return Top == NULL;
	}

	
	void push(int  value){
		Node *newNode = new Node(value);
		newNode->next = Top;
		Top = newNode;	
	}
	int pop(){
		if(isEmpty()){
			cout<<"\nCan't Delete";
		}
		int data = Top->data;
		Node *temp = Top;
		Top = Top->next;
		delete temp;
		return data;
	}
	int getTop(){
		return Top->data;
	}
};

int main(){
	stack s; 
	s.push(10);
	s.push(20);
	s.push(30);
	s.pop();
	cout<<s.getTop();
	
	return 0;
}






