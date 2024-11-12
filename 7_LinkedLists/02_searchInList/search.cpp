#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)

// Node of a Linked List
class Node{
    public: 
        int data;
        Node* next;

    public:
        Node(int data1, Node* next1) {
            data = data1;
            next = next1;
        }

    public:
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

bool searchKey(int n, struct Node* head, int key) {
    
    Node* mover = head;

    for(int i = 0; i < n; i++){
        if(mover->data == key) return true;
        
        mover = mover->next;
    }

    return false;
}

// Return head of the linked list
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
    cout<< head->data<< " "<< endl;

    // Traverse through the linked list
    Node* current = head;

    while(current){
        cout<< current->data<< " ";
        current = current->next;
    }

    return 0;
}