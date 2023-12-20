#include<iostream>
#include<queue>
using namespace std;

class Node{
    public :
    int data;
    Node *left;
    Node* right;

    Node(int data) : data(data), left(NULL), right(NULL){}

};

Node *buildTree(Node* root){
    cout<<"\nEnter the data : ";
    int data; 
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"\nInsert Data for inserting left of "<<data;
    root->left = buildTree(root->left);
    cout<<"\nInsert Data for inserting right of "<<data;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(Node *root){
    queue<Node *> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()){
        Node *temp = Q.front();
        Q.pop();

        if(temp == NULL){
            cout<<endl;

            if(!Q.empty()){ 
                Q.push(NULL);
            }
        }
        else{
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
void inOrder(Node *root){
    // base case 
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void preOrder(Node *root){
    // base case 
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node *root){
    // base case 
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    Node * root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    cout<<"\n"<<"LevelOrder = ";levelOrderTraversal(root);
    cout<<"\n"<<"Inorder = "; inOrder(root);
    cout<<"\n"<<"Preorder = "; preOrder(root);
    cout<<"\n"<<"Postrder = "; postOrder(root);

    // Node *root = NULL;
    // buildFromLvlOrder(root);
    // levelOrderTraversal(root);
    return 0;
}