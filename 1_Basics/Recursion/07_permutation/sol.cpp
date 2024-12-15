#include <bits/stdc++.h>
using namespace std;

unordered_set<int> st;
vector<vector<int>> res;
int n;

void solve(vector<int>& temp, vector<int>& nums){

    // if the temp is filled, push it in the result
    if(temp.size() == n){
        res.push_back(temp);
        return;
    }

    for(int i = 0; i < n; i++){

        // Make sure element is not present
        if(st.find(nums[i]) == st.end()){
            // Add element
            temp.push_back(nums[i]);
            st.insert(nums[i]);

            // Explore
            solve(temp, nums);

            // Remove element
            temp.pop_back();
            st.erase(nums[i]);
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    n = nums.size();

    vector<int> temp;

    solve(temp, nums);

    return res;
}