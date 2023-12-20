#include<iostream>
#include<queue>
using namespace std;

class node{
    public :
    int data;
    node *left, *right;

    node(int data ): data(data), left(NULL), right(NULL){}
};


node* insertIntoBST(node *root, int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }

    if(root->data > data){
        root->left = insertIntoBST(root->left, data);

    }else{
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void takeInput(node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}
void levelordertraversal(node *root){
    queue<node *>Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()){
        node * temp = Q.front();
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

int main()
{
    node * root = NULL;
    cout<<"\nEnter data : ";
    takeInput(root);
    levelordertraversal(root);

    return 0;
}


