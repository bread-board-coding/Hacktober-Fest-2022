#include <iostream>
using namespace std;

struct Node{
    int data;
    Node*left, *right;
    Node(int val){
        data = val;
    }
};

void Preorder(Node* root){
    if(!root) return;
    
    cout<<root->data<<" -> ";
    Preorder(root->left);
    Preorder(root->right);

}

void Inorder(Node* root){
    if(!root) return;
    
    Inorder(root->left);
    cout<<root->data<<" -> ";
    Inorder(root->right);
    
}

void Postorder(Node* root){
    if(!root) return;
    
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" -> ";
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    /**
     * @brief Tree -        1
     *                     / \
     *                    2   3
     *                   / \ / \                                     
     *                  4  5 6  7
     */

    cout<<"Preorder Traversal: ";
    Preorder(root);
    cout<<endl;
    cout<<"Inorder Traversal: ";
    Inorder(root);
    cout<<endl;
    cout<<"PostOrder Traversal: ";
    Postorder(root); 
    cout<<endl;
}