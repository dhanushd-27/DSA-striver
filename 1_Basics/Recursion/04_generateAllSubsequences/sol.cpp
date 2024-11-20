#include <bits/stdc++.h>
using namespace std;

// TC - O(2^n)
// SC - O(n) - Recursive stack space

void getAllSubsets(int index, vector<int> subset, vector<vector<int>> &res, vector<int> &nums, int size){
    if(index == size){
        res.push_back(subset);
        return;
    }

    subset.push_back(nums[index]);
    getAllSubsets(index+1, subset, res, nums, size);
    subset.pop_back();
    getAllSubsets(index+1, subset, res, nums, size);
}

vector<vector<int>> subsets(vector<int>& nums) {
    
    vector<int> subset;
    vector<vector<int>> res;
    int size = nums.size();

    getAllSubsets(0, subset, res, nums, size);

    return res;
}