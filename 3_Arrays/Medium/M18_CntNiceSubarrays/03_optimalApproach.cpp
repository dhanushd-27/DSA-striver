// Sliding Window

#include <bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int> nums, int k){
    int n = nums.size();
    int ans = 0, cnt = 0;
    int l = 0, r = 0;
    int odd = 0;

    while(r < n){
        if(nums[r]&1){
            odd++;
            cnt = 0;
        }

        while(odd == k){
            ++cnt;
            odd -= nums[l++]&1;
        }

        ans += cnt;
        r++;
    }
    return ans;
}

int main(){
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    int k = 2;
    cout<< "Number of Nice Sub-Arrays are: "<< numberOfSubarrays(nums, k);
    return 0;
}