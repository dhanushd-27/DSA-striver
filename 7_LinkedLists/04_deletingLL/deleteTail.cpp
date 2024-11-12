#include <bits/stdc++.h>
using namespace std;

// WAP to delete tail of the given linked list;

class Node{
    public:
        int data;
        Node* next;
    
    public:
        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }

        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* deleteTail(Node* head){
    if(head == NULL){
        return head;
    }

    if(head->next == NULL){
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    Node* temp = head;
    // Traversal to the end
    while(temp->next->next != NULL ){
        temp = temp -> next;
    }

    free(temp->next);
    temp->next = nullptr;

    return head;
}