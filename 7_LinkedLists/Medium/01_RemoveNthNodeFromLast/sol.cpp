#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {

    // in case LL contains only one element
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    
    int size = 0;
    ListNode* traverse = head;

    // Find LL Size - could be a diff function for readability
    while(traverse != NULL){
        size++;
        traverse = traverse->next;
    }

    // if the node to be deleted is head;
    if(size == n){
        ListNode* temp = head->next;
        delete(head);
        return temp;
    }

    // else
    int nodePos = size - n;

    ListNode* prev = NULL;
    ListNode* curr = head;

    while(nodePos != 0 && curr != NULL && curr->next != NULL){
        prev = curr;
        curr = curr->next;
        nodePos--;
    }

    prev->next = curr->next;
    delete(curr);

    return head;
}