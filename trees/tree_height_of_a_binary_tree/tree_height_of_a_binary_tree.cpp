// author: Moongee Cho
// date: 02/28/2019

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if(root == NULL) {
            return new Node(data);
        } else {
            Node* cur;
            if(data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            } else {
                cur = insert(root->right, data);
                root->right = cur;
            }
            
            return root;
        }
    }
    
    /*The tree node has data, left child and right child
     class Node {
     int data;
     Node* left;
     Node* right;
     };
     
     */
    int findChild(Node* node) {
        int leftRank = 0;
        int rightRank = 0;
        if(node->left != NULL) {
            leftRank++;
            leftRank += findChild(node->left);
        }
        
        if(node->right != NULL) {
            rightRank++;
            rightRank += findChild(node->right);
            findChild(node->right);
        }
        
        return max(leftRank, rightRank);
    }
    
    int height(Node* root) {
        int leftRank = 0;
        int rightRank = 0;
        if(root->left != NULL) {
            leftRank++;
            leftRank += findChild(root->left);
        }
        
        if(root->right != NULL) {
            rightRank++;
            rightRank += findChild(root->right);
        }
        
        return max(leftRank, rightRank);
    }
};
