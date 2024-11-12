#include <bits/stdc++.h>
using namespace std;

// WAP to delete head of the given linked list;

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

Node* deleteHead(Node* head){

    if(head == NULL){
        return head;
    }

    Node* temp = head;
    head = head -> next;
    free(temp);

    return head;
}
