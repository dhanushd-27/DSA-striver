// Leetcode - 1877
// Minimize Maximum Pair Sum in Array

// TC: O(nlogn) + O(n/2)
// SC: O(1)

#include <bits/stdc++.h>
using namespace std;

int minPairSum(vector<int>& nums) {
    // Sort the given array
    sort(nums.begin(), nums.end());

    // Intialize and declare variables
    int n = nums.size();
    int i = 0, j = n - 1, maxSum = INT_MIN;

    // Maintain the max sum, Starting from the edge -> the middle
    while(i < j){
        int sum = nums[i] + nums[j];
        maxSum = max(maxSum, sum);

        // Increase i pos by 1
        i++;
        // Decrease j pos by 1
        j--;
    }
    
    return maxSum;
}