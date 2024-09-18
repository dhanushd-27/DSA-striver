#include <bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int> nums, int k){
    int sum = 0;
    unordered_map<int, int> hashMap;
    int ans = 0;
    int n = nums.size();
    vector<int> zeroOne(n, 0);

    // convert all even number to zero and all odd number to one
    for(int i = 0;  i < n; i++){
        if(nums[i]&1){
            zeroOne[i] = 1;
        }
    }

    // Count number of subarrays with sum = k;
    
    // when sum - k == 0
    hashMap[0] = 1;

    for(int i = 0; i < n; i++){
        sum += zeroOne[i];

        int rem = sum - k;

        if(rem >= 0){
            ans += hashMap[rem];
        }

        hashMap[sum]++;
    }
    return ans;
}

int main(){
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    int k = 2;
    cout<< "Number of Nice Sub-Arrays are: "<< numberOfSubarrays(nums, k);
    return 0;
}