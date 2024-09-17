#include <bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int> nums, int k){
    int countSubarrays = 0;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        int countOdd = 0;
        for(int j = i; j < n; j++){
            if(nums[j] % 2 == 1) countOdd++;
            if(countOdd == k) countSubarrays++;
        }
    }

    return countSubarrays;
}

int main(){
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout<< "Number of Nice Sub-Arrays are: "<< numberOfSubarrays(nums, k);
    return 0;
}