#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// TC - O(n)
// SC - O(1)

// Key to solve recursive prob
// Break down the recursive problem into sub problems
// Have a break point

ListNode* reverseList(ListNode* head) {

    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNode* last = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return last;
}