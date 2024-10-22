// Leetcode 1498
// Number of subsequences that satisfy the given condition

// TC : O(N) + O(N) + O(NLogN)
//      Pre computing + Actual Loop to solve answer + Sorting given array
// SC : O(N)
//      Space to store pre computing power values

#include <bits/stdc++.h>
using namespace std;

int M = 1e9 + 7;
int numSubseq(vector<int>& nums, int target) {
    int result = 0;
    int n = nums.size();
    vector<int> power(n);
    power[0] = 1;

    // Pre Compute powers from 0 to n;
    for(int i = 1; i < n; i++){
        power[i] = (power[i - 1] * 2) % M;
    }

    // Sort the Given array
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = n-1;

    // Apply the actual story points;
    while(left <= right){ // The middle element can be a answer therefore l <= r

        if(nums[left] + nums[right] <= target){
            // All the sub sequences including the current min & max will be included in the answer
            int diff = right - left;
            result = ((result % M) + power[diff]) % M;
            left++;
        }
        else{
            // The sum of min + max exceeds the target hence every sub sequence including current min & max will be not added to the answer
            right--;
        }
    }

    return result;
}