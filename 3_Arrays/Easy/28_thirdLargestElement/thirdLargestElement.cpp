#include <bits/stdc++.h>
using namespace std;

// Leetcode 414

int thirdMax(vector<int>& nums) {
    int n = nums.size();
    long max = LONG_MIN;
    long secondMax = LONG_MIN;
    long thirdMax = LONG_MIN;

    for(int i = 0; i < n; i++){
        if(nums[i] > max){
            thirdMax = secondMax;
            secondMax = max;
            max = nums[i];
        }

        else if(nums[i] > secondMax && nums[i] < max){
            thirdMax = secondMax;
            secondMax = nums[i];
        }

        else if(nums[i] > thirdMax && nums[i] < secondMax){
            thirdMax = nums[i];
        }
    }

    if(n < 3 || thirdMax < INT_MIN){
        return max;
    }
    else{
        return thirdMax;
    }
}
int main(){
    vector<int> nums = {2, 1, 44, 33, 66, 12, 99, 32}; // Op - 44

    int res = thirdMax(nums);

    cout<< "Third Max element of given array is :"<< res<< endl;
    return 0;
}