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

Node* deleteKthEle(Node* head, int val){

    if(head == NULL){
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){

        if(temp->data == val){
            prev->next = prev->next->next;
            free(temp);
        }

        prev = temp;
        temp = temp -> next;
    }

    return head;
}