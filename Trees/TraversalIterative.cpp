#include<bits/stdc++.h>
using namespace std;

class Node {
    public :
        int data;
        Node *left, *right;
    Node(int data ): data(data), left(NULL), right(NULL){}
};

void inOrder(Node *root){
    stack<Node *> stackk;
    vector<int> inorderr;

    while(true){
        if(root != NULL){
            stackk.push(root);
            root = root->left;
        }else{
            if(stackk.empty())
                break;
            root = stackk.top();
            inorderr.emplace_back(root->data);
            stackk.pop();
            root = root->right;
        }
    }
    for(int i=0; i<inorderr.size(); i++){
        cout<<inorderr[i]<<" ";
    }

}

void preOrderTraversal(Node *root){
    queue<Node *> Q;
    vector<int> vectorr;

    while(true){
        if(root != NULL){
            Q.push(root);
            root = root->left;
        }else{
            if(Q.empty())
                break;
            root = Q.front();
            vectorr.emplace_back(root->data);
            Q.pop();
            root = root->right;
        }
    }
    for(int i=0; i<vectorr.size(); i++){
        cout<<vectorr[i]<<" ";
    }
}
void postOrder(Node *root){
   stack<Node *> s1;
   stack<Node *> s2;
   vector<int> post;

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
    post.emplace_back(s2.top()->data);
    s2.pop();
   }
   for(int i=0; i<post.size(); i++){
        cout<<post[i]<<" ";
   }
}
int main(){
    Node *root = new Node(10);
    root->left = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(8);
    root->right = new Node(4);
    // root->right->left = new Node(2);
    root->right->right = new Node(7);

    cout<<"\nInOrderTraversal = ";inOrder(root);
    cout<<"\nPreOrderTraversal = ";preOrderTraversal(root);
    cout<<"\nPostOrderTraversal = ";postOrder(root);
    return 0;
}