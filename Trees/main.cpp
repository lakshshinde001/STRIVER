#include<bits/stdc++.h>
using namespace std;

class node{
    public :
        int data;
        node *left, *right;

    node(int data) : data(data), left(NULL), right(NULL){}
};

node *buildTree(node *root){
    cout<<"\nEnter Data : ";
    int data; cin>>data;

    root = new node(data);
    
    if(data == -1){
        return NULL;
    }
    cout<<"\nEnter left element for "<<data;
    root->left = buildTree(root->left);
    cout<<"\nEnter right Element for "<<data;
    root->right = buildTree(root->right);

    return root;
}
 
void inOrder(node *root){
    stack<node * > Q;
    vector<int> v1;

    while(true){
        if(root != NULL){
            Q.push(root);
            root = root->left;
        }else{
            if(Q.empty())
                break;
            root = Q.top();
            v1.emplace_back(root->data);
            Q.pop();
            root = root->right;
        }

    }
    for(int i=0; i<v1.size(); i++){
        cout<<v1[i]<<" ";
    }
}

void preOrder(node *root){
    stack<node *> s;
    vector<int> v1;

    s.push(root);
    while(!s.empty()){
        node *topNode = s.top();
        v1.emplace_back(topNode->data);
        s.pop();

        if(topNode->right != NULL){
            s.push(topNode->right);
        }
        if(topNode->left != NULL){
            s.push(topNode->left);
        }
    }
    for(int i=0; i<v1.size(); i++){
        cout<<v1[i]<<" ";
    }
}
void postOrder(node *root){
    stack<node *> s1;
    stack<node *> s2;
    vector<int> v1;

    s1.push(root);

    while(!s1.empty()){
        root = s1.top();
        
        s1.pop();
        s2.push(root);

        if(root->left != NULL){
            s1.push(root->left);
        }
        if(root->right != NULL){
            s1.push(root->right);
        }
    }
    while(!s2.empty()){
        v1.emplace_back(s2.top()->data);
        s2.pop();
    }
    for(int i=0; i<v1.size(); i++){
        cout<<v1[i]<<" ";
    }
}
void lvlOrderTraversal(node *root){
    queue<node *> s;
    s.push(root);
    s.push(NULL);

    while(!s.empty()){
        node *temp = s.front();
        s.pop();

        if(temp == NULL){
            cout<<endl;

            if(!s.empty()){
                s.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                s.push(temp->left);
            }
            if(temp->right){
                s.push(temp->right);
            }
        }
    }
}

int main(){

    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // node *root = NULL;
    // root = buildTree(root);

    cout<<"\nInorder =";inOrder(root);
    cout<<"\nPreorder =";preOrder(root);
    cout<<"\nPostOrder ="; postOrder(root);
    cout<<"\nLvlOrder = "; 
    cout<<endl;
    lvlOrderTraversal(root);

    return 0;
}