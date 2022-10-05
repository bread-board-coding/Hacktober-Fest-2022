#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* left, *right;
    Node(int val){
        data = val;
    }
};

int heightOfBT(Node* root){
    if(root == NULL) return 0;
    int lr = 1 + heightOfBT(root->left);
    int Rr = 1 + heightOfBT(root->right);

    return max(lr, Rr);
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);

    /**
     * @brief Tree -        1
     *                     / \
     *                    2   3
     *                   / \ / \                                     
     *                  4  5 6  7
     *                      /
     *                     8                        
     */

    cout<<"Height of Binary Tree is: "<<heightOfBT(root);
    cout<<endl;
}