#include <bits/stdc++.h>
using namespace std;

// WAP to insert node at head in the given linked list;

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

Node* insertHead(Node* head, Node* newNode){
    return newNode->next = head;
}