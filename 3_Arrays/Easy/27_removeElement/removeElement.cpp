// Leetcode 27

#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int k = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] != val){
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main(){
    vector<int> nums = {3};
    int val = 3;

    cout<< "Before "<< endl;
    for(auto it: nums) cout<< it;

    int res = removeElement(nums, val);

    cout<< endl<< "After "<< endl;
    for(auto it: nums) cout<< it;
    cout<< endl;
    return 0;
}