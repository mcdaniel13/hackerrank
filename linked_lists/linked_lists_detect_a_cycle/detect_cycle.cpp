// author: Moongee Cho
// date: 03/01/2019
// Problem URL: https://www.hackerrank.com/challenges/ctci-linked-list-cycle/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=linked-lists
/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
    struct Node {
        int data;
        struct Node* next;
    }
*/
#include <set>

bool has_cycle(Node* head) {
    Node* temp = head;
    set<Node*> addressSet;
    set<Node*>::iterator it;

    while(temp != NULL) {
        it = addressSet.find(temp);
        if(it != addressSet.end())
            return true;
        else {
            addressSet.insert(temp);
            temp = temp->next;
        }
    }

    return false;
}