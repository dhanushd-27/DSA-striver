#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int> nums, int k){
        int n = nums.size();
        int res = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = 1;

        for (int i = 0; i < n; i++) 
        {
            sum += nums[i];
            int rem = sum % k;

            if (rem < 0) {
                rem += k;
            }

            res += mp[rem];

            mp[rem]++;
        }

        return res;
}

int main(){
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;
    cout<<"There are "<< subarraysDivByK(nums, k)<< " subarrays with a sum divisible by k = "<< k<< endl;

    return 0;
}