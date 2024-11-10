#include <bits/stdc++.h>
using namespace std;

// Leetcode 901 - Online Stock Span

// TC - O(n) - could be wrong

// Learnt About Monotonic stack - 10th, Nov 2024

// Declare a stack, { {100, 1}, { 60, 1 } }
stack<pair<int, int>> st;

// StockSpanner() {
    
// }

int next(int price) {

    // Intial span is always 1
    int span = 1;

    // while stack is not empty and
    // price of top element is smaller than current price
        // add it's span to current price's span
        // remove the top element from stack
    while(!st.empty() && st.top().first <= price){
        span = span + st.top().second;
        st.pop();
    }

    // push price and span to the stack
    st.push({ price, span });

    // return span for each price
    return span;
}
