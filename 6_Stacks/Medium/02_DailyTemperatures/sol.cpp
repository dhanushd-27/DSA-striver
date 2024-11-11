#include <bits/stdc++.h>
using namespace std;

// Leetcode 739 - Daily Temperatures

// TC - O(n) ~ O(2n)
// SC- (1)

vector<int> dailyTemperatures(vector<int>& temperatures) {
    // Store temperatures and thier index in a stack

    //Size of temperatures array
    int size = temperatures.size();

    //Intialize a stack
    stack<pair<int, int>> st;

    //Intialize and declare a vector with all zeroes;
    vector<int> ans(size, 0);

    // Iterate through each element of temperature
    for(int i = 0; i < size; i++){

        // if the current element is greater than top element of stack pop it
        while(!st.empty() && st.top().first < temperatures[i]){

            //Compare the difference of position in current element and top element of stack
            int topIndex = st.top().second;
            ans[topIndex] = i - topIndex;
            st.pop();

            // continue until one of the condition fails
        }

        st.push( {temperatures[i], i} );
    }

    return ans;
}