#include <bits/stdc++.h>
using namespace std;

// TC - O(n)
// SC- O(n)

// Leetcode - 198

// use memo to avoid repeatition of same values
int t[101];

int solve(vector<int> &nums, int index, int size){
    
    if(index >= size) return 0;

    // return if the calc is already done
    if(t[index] != -1) return t[index];

    int steal = nums[index] + solve(nums, index + 2, size);
    int skip = solve(nums, index + 1, size);

    return t[index] =  max(steal, skip);
}

int rob(vector<int>& nums) {
    int size = nums.size();

    // create a set of elements with all values as -1 of size 101
    memset(t, -1, sizeof(t));
    return solve(nums, 0, size);
}