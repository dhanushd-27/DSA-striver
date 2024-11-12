#include <bits/stdc++.h>
using namespace std;

// WAP to insert node at last in the given linked list;

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

Node* insertLast(Node* head, Node* newNode){
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

Node* convertArrToList(vector<int> arr){
    int size = arr.size();
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < size; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

int main(){
    vector<int> arr = { 2, 5, 8, 10, 14 };
    Node* head = convertArrToList(arr);
    
    cout<< "Head data of the linked list"<< endl;

    // Traverse through the linked list
    Node* current = insertLast(head, new Node(33));

    while(current){
        cout<< current->data<< " ";
        current = current->next;
    }

    return 0;
}