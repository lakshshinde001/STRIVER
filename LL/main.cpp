
/*

1. Operations of Singly Linked List 

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
	~Node(){
		cout<<"\n"<<this->data<<" Deleted";
	}
};
	static int count = 0;
	void insertAtFront(Node* &head, Node* &tail, int data);
	void insertAtEnd(Node* &head, Node* &tail, int data){
		if(head == NULL){
			Node *newNode = new Node(data);
			head = tail = newNode;
			count++;
			return;
		}
		Node *newNode = new Node(data);
		count++;
		tail->next = newNode;
		tail = newNode;
	}
	void insertAtPosition(Node* &head, Node* &tail, int data, int pos){
		if(head == NULL){
			Node *newNode = new Node(data);
			head = tail = newNode; 
			count++;
			return;
		}
		if(pos == 1){
			insertAtFront(head, tail, data);
			return;
		}
		Node *newNode = new Node(data);
		count++;
		Node *temp = head;
		int i = 1;
		while(i < pos-1){
			temp = temp->next;
			i++;
		}
		Node *prev = temp;
		Node *next = prev->next;
		
		newNode->next = next;
		prev->next = newNode;
	}
	void insertAtFront(Node* &head, Node* &tail, int data){
		if(head == NULL){
			Node *newNode = new Node(data);
			head = tail = newNode;
			count++;
			return;
		}
		Node *newNode = new Node(data);
		count++;
		newNode->next = head;
		head = newNode;
	}
	void display(Node* &head){
		if(head == NULL){
			cout<<"\nList is empty....";
			return;
		}
		Node *temp = head;
		while(temp != NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
	}
	void deleteAtFront(Node* &head){
		if(head == NULL){
			cout<<"\nList is Empty ";
			return;
		}
		Node *temp = head;
		head = temp->next;
		temp->next = NULL;
		delete temp;
	}
	void deleteAtEnd(Node* &head, Node* &tail){
		if(head == NULL){
			cout<<"\nList is Already Empty....";
			return;
		}
		Node *temp = head;
		while(temp->next != tail){
			temp = temp->next;
		}
		tail = temp;
		Node *next = temp->next;
		temp->next = NULL;
		delete next;
	}
	void deleteAtPosition(Node* &head, Node *tail, int pos){
		if(head == NULL){
			cout<<"List is empty...";
			return;
		}
		if(pos == 1){
			deleteAtFront(head);
			return;
		}
		Node *temp = head;
		int i = 1;
		while( i < pos-1){
			temp = temp->next;
			i++;
		}
		Node *prev = temp;
		temp = temp->next;
		prev->next = temp->next;
		temp->next = NULL;
		delete temp;
	}
	void reverse(Node* &head){
		Node *prev = NULL;
		Node *curr = head;
		Node *nextNode = NULL;
		
		while(curr != NULL){
			nextNode = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextNode;
		}
		head = prev;
		display(head);
	}
	void countt(){
		cout<<"\nCount : "<<count;
	}
	void search(Node * &head, int key){
		if(head == NULL){
			cout<<"\nList is Empty";
			return;
		}
		Node *temp = head;
		while(temp != NULL){
			if(temp->data == key){
				cout<<"\nKey found ";
			}else {
				cout<<"\nKey Not found ";
			}
			temp = temp->next;
		}
	}
int main(){	
	Node *head = NULL;
	Node *tail = NULL;
	
	while(1){
		cout<<"\n----------------Singly Linked list -----------------";
		cout<<"\n----------------1) InsertFront     -----------------";
		cout<<"\n----------------2) InsertEnd       -----------------";
		cout<<"\n----------------3) InsertPosition  -----------------";
		cout<<"\n----------------4) DeleteFront     -----------------";
		cout<<"\n----------------5) DeletePosition  -----------------";
		cout<<"\n----------------6) DeleteEnd       -----------------";
		cout<<"\n----------------7) Display         -----------------";
		cout<<"\n----------------8) Reverse         -----------------";
		cout<<"\n----------------9) Count           -----------------";
		cout<<"\n----------------10) Search         -----------------";
		cout<<"\n----------------11) Exit           -----------------";
		
		cout<<"\nEnter your choice : ";
		int choice; cin>>choice;
		
		switch(choice){
			case 1 : cout<<"\nEnter Element to be Inserted : ";
					 int data; cin>>data;
					 insertAtFront(head, tail, data);
					 break;
			case 2 : cout<<"\nEnter Element to be Inserted : ";
					 cin>>data; 
					 insertAtEnd(head, tail, data);
					 break;
			case 3 : cout<<"\nEnter Element to be Inserted : ";
					 cin>>data;
					 cout<<"\nEnter position of the Element : ";
					 int pos; cin>>pos;
					 insertAtPosition(head, tail, data, pos);
					 break;
			case 4 : deleteAtFront(head); break;
			case 5 : cout<<"\nEnter Position : "; 
					 cin>>pos; 
					 deleteAtPosition(head, tail, pos);
					 break;
			case 6 : deleteAtEnd(head, tail); break;
			case 7 : display(head); break;
			case 8 : reverse(head); break;
			case 9 : 
					cout<<"\nCount : "<<count; 
					break;
			case 10 : cout<<"\nEnter Element to be Searched : ";
					  cin>>data;
					  search(head, data); break;
			case 11 : break; 
			default : cout<<"\nInvalid Choice : "; 
		}
	}
	
	
	return 0;
}
*/

/*
Operations on Double Linked List 


#include<iostream>
using namespace std;

class Node{
	public : 
		int data; 
		Node *prev; 
		Node *next; 
		
	Node(int data){
		this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}
};

void insertAtFront(Node* &head, Node* &tail, int data){
	if(head == NULL){
		Node *newNode = new Node(data);
		head = tail = newNode;
		return;
	}
	Node *newNode = new Node(data);
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
}
void insertAtEnd(Node* &head, Node* &tail, int data){
	if(head == NULL){
		Node *newNode = new Node(data);
		head = tail = newNode;
		return;
	}
	Node *newNode = new Node(data);
	Node *temp = head;
	while(temp != tail){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	tail = newNode;
}

void display(Node* &head){
	if(head == NULL){
		cout<<"\nLL is empty...";
		return;
	}
	Node *temp = head;
	while(temp != NULL){
		cout<<temp->data<<"<->";
		temp = temp->next;
	}
}
int main(){
	
	Node *head = NULL;
	Node *tail = NULL;
	
	insertAtFront(head, tail, 10);
	insertAtEnd(head, tail, 20);
	insertAtEnd(head, tail, 30);
	display(head);
	
	return 0;
}


*/

// Polynomial addition and Evaluation 

#include<iostream>
using namespace std;

int main(){
	
	return 0;
}
