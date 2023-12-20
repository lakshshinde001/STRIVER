#include<bits/stdc++.h>
using namespace std;

class node{
    public : 
    int data;
    node *left, *right;

    node(int data) : data(data), left(NULL), right(NULL){}
};


node *buildTree(node *root){
    cout<<"\nInsert Data : ";
    int data; cin>>data;

    while(1){
        if()
        if(root == NULL){
            return new node(data);
        }


        if(data < root->data){
            root->left = buildTree(root->left);
        }else{
            root->right = buildTree(root->right);
        }
    }
    return root;

}

void lvlOrder(node *root){
    queue<node *> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()){
        node* temp = Q.front();
        Q.pop();

        if(temp == NULL){
            cout<<endl;

            if(!Q.empty()){
                Q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                Q.push(temp->left);
            }
            if(temp->right){
                Q.push(temp->right);
            }
        }
    }
}

node *searchBST(node *root, int target){
    while(root != NULL && root->data != target){
        root =  target < root->data ? root->left : root->right;
    }
    return root;
}

int main()
{
    // node *root = new node(100);
    // root->left = new node(34);
    // root->right = new node(120);
    // root->left->left = new node(20);
    // root->left->right = new node(40);
    // root->right->right = new node(200);
    
    // // lvlOrder(root);
    // node *found = searchBST(root,100);

    // if(found != NULL){
    //     cout<<found->data<<" found";
    // }else{
    //     cout<<" \nData not found";
    // 
    node *root = NULL;
    root = buildTree(root);
    lvlOrder(root);

    return 0;
}