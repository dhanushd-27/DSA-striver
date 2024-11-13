#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// TC - O(n)
// SC - O(1)

// Steps
/*
    * Two pointer - curr, prev
    * total three nodes - curr, prev, nxt
    * repeat until curr != null
    * store curr -> next in nxt node - used to move forward
    * now point curr -> next to prev
    * move prev to curr pos
    * move curr to nxt pos
*/

ListNode* reverseList(ListNode* head) {

    // Two pointer approach - prev, current
    ListNode* prev = NULL;
    ListNode* curr = head;

    while(curr != NULL){
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return prev;
}