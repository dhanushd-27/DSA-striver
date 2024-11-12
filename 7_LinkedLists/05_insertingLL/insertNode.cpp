#include <bits/stdc++.h>
using namespace std;

// WAP to insert node at Kth pos in the given linked list;

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

Node* insertAtKthPos(Node* head, Node* newNode, int k){

    if(head == NULL){
        return newNode;
    }

    if(k == 1){
        return newNode->next = head;
    }
    
    Node* temp = head;
    Node* prev = NULL;
    int cnt = 0;
    while(temp != NULL){
        cnt++;

        if(cnt == k){
            prev->next = newNode;
            newNode->next = temp;
        }

        prev = temp;
        temp = temp->next;
    }

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
    Node* current = insertAtKthPos(head, new Node(33), 3);

    while(current){
        cout<< current->data<< " ";
        current = current->next;
    }

    return 0;
}