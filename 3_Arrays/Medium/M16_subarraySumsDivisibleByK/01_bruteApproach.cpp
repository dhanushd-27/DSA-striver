#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int> nums, int k){
    int n = nums.size();
    int count = 0;
    int psum[n];

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += nums[j];

            if(sum % k == 0){
                count++;
            }
        }
    }

    return count;
}

int main(){
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;
    cout<<"There are "<< subarraysDivByK(nums, k)<< " subarrays with a sum divisible by k = "<< k<< endl;

    return 0;
}