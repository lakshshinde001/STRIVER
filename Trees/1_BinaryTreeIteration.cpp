#include<bits/stdc++.h>
using namespace std;

class node{
    public : 
        int data;
        node *left, *right;

    node(int data ): data(data), left(NULL), right(NULL){}
};

node *buildTree(node *root){
    cout<<"\nEnter root Data :";
    int data; cin>>data;

    root = new node(data);
    queue<node *> Q;
    Q.push(root);

    while(!Q.empty()){
        node *curr = Q.front();
        Q.pop();

        cout<<"\nEnter left Data for "<<curr->data;
        int leftData; cin>>leftData;

        if(leftData != -1){
            curr->left = new node(leftData);
            Q.push(curr->left);
        }
        cout<<"\nEnter right Data for "<<curr->data;
        int rightData; cin>>rightData;

        if(rightData != -1){
            curr->right = new node(rightData);
            Q.push(curr->right);
        }
    }
    return root;
}
void lvlOrderTraversal(node *root){
    queue<node *> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()){
        node *temp = Q.front();
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
void inOrderTraversal(node *root){
    stack<node *> S;
    vector<int> v1;

    while(true){
        if(root != NULL){
            S.push(root);
            root = root->left;
        }else{
            if(S.empty())
                break;
            root = S.top();
            v1.emplace_back(root->data);
            S.pop();
            root = root->right;
        }
    }
    for(int i=0; i<v1.size(); i++){
        cout<<v1[i]<<" ";
    }
}
void preOrderTraversal(node *root){
    stack<node *> S;
    vector<int> v1;
    S.push(root);

    while(!S.empty()){
        root = S.top();
        v1.emplace_back(root->data);
        S.pop();
        if(root->right){
            S.push(root->right);
        }
        if(root->left){
            S.push(root->left);
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
        s2.push(s1.top());
        s1.pop();

        if(root->left){
            s1.push(root->left);
        }
        if(root->right){
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

int main()
{
    node *root = NULL;
    root = buildTree(root);
    // cout<<"\ninOrder : "; inOrderTraversal(root);
    // cout<<"\nPreOrder : "; preOrderTraversal(root);
    // cout<<"\npostOrder : "; postOrder(root);
    cout<<"\nLvlOrer : "; lvlOrderTraversal(root);
    return 0;
}