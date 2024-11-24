#include <bits/stdc++.h>
using namespace std;

// TC - O(n)
// SC - O(1)

bool containsDuplicate(vector<int>& nums) {

    // declare unordered set to store unique elements
    unordered_set<int> set;
    int size = nums.size();

    for(int i = 0; i < size; i++){
        if(set.find(nums[i]) != set.end()){
            return true;
        }

        // insert the element if above condition is not true
        set.insert(nums[i]);
    }

    return false;
}