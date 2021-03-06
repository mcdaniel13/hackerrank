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
    
    Node *lca(Node *root, int v1, int v2) {
        if(v1 > v2) {
            int temp = v1;
            v1 = v2;
            v2 = temp;
        }
        
        if(root->data < v2 && root->data > v1) {
            return root;
        } else if(root->data < v1 && root->data < v2) {
            return lca(root->right, v1, v2);
        } else if(root->data > v1 && root->data > v2) {
            return lca(root->left, v1, v2);
        }
        
        return root;
    }
    
};
