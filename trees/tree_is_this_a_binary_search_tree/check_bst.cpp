// author: Moongee Cho
// date: 02/28/2019

#include<iostream>

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.
 
 The Node struct is defined as follows:
 struct Node {
 int data;
 Node* left;
 Node* right;
 }
 */

bool checkBST(Node *root, int max, int min) {
    if(root == NULL)
        return true;
    
    if(root->data >= max)
        return false;
    
    if(root->data <= min)
        return false;
    
    return checkBST(root->left, root->data, min) && checkBST(root->right, max, root->data);
}


bool checkBST(Node *root) {
    return checkBST(root, 10000, -1);
}
