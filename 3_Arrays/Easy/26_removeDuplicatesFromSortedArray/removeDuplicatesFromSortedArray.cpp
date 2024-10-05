#include <bits/stdc++.h>
using namespace std;

// Leetcode - 26

int removeDuplicates(vector<int>& nums) {
    int i = 0, j = 0;
    int prev = -101;

    for(; i < nums.size(); i++){

        if(nums[i] != prev){
            nums[j] = nums[i];
            j ++;
            prev = nums[i];
        }
    }

    return j;
}

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int unqEles = removeDuplicates(nums);

    cout<< "The number of unique elements are: "<< unqEles<< endl;
}