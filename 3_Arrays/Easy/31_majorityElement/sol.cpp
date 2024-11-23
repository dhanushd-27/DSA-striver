#include <bits/stdc++.h>
using namespace std;

// Leetcode 169 - Majority Element

// TC - O(n)
// SC - O(1)

int majorityElement(vector<int>& nums) {
    
    // Boyer Moore's Voting Algorithm

    int candidate = nums[0];
    int vote = 1;
    int size = nums.size();

    for(int i = 1; i < size; i++){
        if(nums[i] == candidate) vote++;
        else if(vote == 0){
            candidate = nums[i];
        }
        else{
            vote--;
        }
    }

    return candidate;
}