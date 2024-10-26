// Leetcode 962

// TC: O(n)
// SC: O(n)

#include <bits/stdc++.h>
using namespace std;

int maxWidthRamp(vector<int>& nums) {
    // brute approach

    // int ans = -1;
    // int n = nums.size();

    // for(int i = 0; i < n; i++){
    //     for(int j = i + 1; j < n; j++){
    //         if(nums[j] >= nums[i]){
    //             ans = max(ans, j - i);
    //         }
    //     }
    // }

    // if(ans == -1) return 0;
    // return ans;

    // optimal approach

    int n = nums.size();

    vector<int> maxHashMap(n);

    maxHashMap[n - 1] = nums[n - 1];

    for(int i = n - 2; i >= 0; i--){
        maxHashMap[i] = max(maxHashMap[i+1], nums[i]);
    }

    int ramp = 0;
    int i = 0;
    int j = 0;

    while(j < n){

        while(i < j && nums[i] > maxHashMap[j]) {
            i++;
        }

        ramp = max(ramp, j - i);
        j++;
    }

    return ramp;
}