#include <bits/stdc++.h>
using namespace std;

// Leetcode 20 - Valid Parenthesis - Solved using stack - tricky approach

// TC - O(n)
// SC - O(n)

bool isValid(string s) {

    // Declare a stack
    stack<char> st;

    // Iterate through the string
    for(char ch: s){

        // if ch is a opening bracket, push the corresponding closing bracket into the stack
        if(ch == '(')
            st.push(')');
        else if(ch == '{')
            st.push('}');
        else if(ch == '['){
            st.push(']');
        }
        
        /* 1) the other case could be the ch is a closing bracket and therefore
            the stack is empty 
            
            2) the other case could be the ch is a closing bracket which is not same 
            stack.top
            
            therefore return false;
        */

        else if( st.empty() || st.top() != ch )
            return false;

        // st.top == ch
        else
            st.pop();
    }

    // if stack is empty return true else return false;
    return st.empty();
}