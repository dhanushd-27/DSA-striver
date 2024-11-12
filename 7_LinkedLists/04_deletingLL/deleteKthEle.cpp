#include <bits/stdc++.h>
using namespace std;

// WAP to delete Kth element of the given linked list;

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

Node* deleteKthEle(Node* head, int k){

    if(head == NULL){
        return head;
    }

    if(k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    int cnt = 1; 
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        cnt++;

        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
        }

        prev = temp;
        temp = temp -> next;
    }

    return head;
}