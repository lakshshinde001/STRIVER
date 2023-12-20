#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class node{
	public :
		int data;
		node *left, *right;
	
	node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};
//	node *buildTree(node *root){
//		cout<<"\nEnter data : ";
//		int data; cin>>data;
//		
//		root = new node(data);
//		
//		if(data == -1){
//			return NULL;
//		}
//		cout<<"\nEnter left data for "<<data;
//		root->left = buildTree(root->left);
//		cout<<"\nEnter right data for "<<data;
//		root->right = buildTree(root->right);
//		
//		return root;
//	}
void lvlOrder(node *root){
		if(root == NULL){
			return;
		}
		queue<node *> q;
		vector<int> ans;
		q.push(root);
		q.push(NULL);
		
		while(!q.empty()){
			node *temp = q.front();
			q.pop();
			
			if(temp == NULL){
				cout<<endl;
				if(!q.empty()){
					q.push(NULL);
				}
			}else{
				cout<<temp->data<<" ";
				if(temp->left){
					q.push(temp->left);
				}
				if(temp->right){
					q.push(temp->right);
				}
			}
		}
	}
	void inOrder(node *root){
		if(root == NULL){
			return;
		}
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
	void preOrder(node *root){
		if(root == NULL){
			return;
		}
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
	void postOrder(node *root){
		if(root == NULL){
			return;
		}
		preOrder(root->left);
		preOrder(root->right);
		cout<<root->data<<" ";
	}

int main(){
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
//	lvlOrder(root);
	inOrder(root); cout<<endl;
	preOrder(root); cout<<endl;
	postOrder(root); cout<<endl;
	return 0;
}
