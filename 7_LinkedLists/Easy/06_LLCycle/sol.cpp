#include <bits/stdc++.h>
using namespace std;

// Leetcode 141 - LL Cycle

// TC - O(n)
// The actual reason is explained in Neetcode video - Should watch

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    
    // Slow pointer, Fast Pointer Approach
    // Floyd's Tortoise and Hare

    ListNode *slow = head;
    ListNode *fast = head;

    // if fast points to a null, return false - i.e not a loop
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        
        // if it a loop eventually they will meet
        if(slow == fast){
            return true;
        }
    }
    return false;
}
