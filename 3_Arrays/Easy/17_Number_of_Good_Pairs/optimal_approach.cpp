#include <bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int> nums){
    int maxi = *max_element(nums.begin(), nums.end());
    vector<int> freq(maxi+1, 0);
    int n = nums.size();

    for(int i = 0; i < n; i++){
        freq[nums[i]]++;
    }

    int totalCnt = 0;

    for(auto count: freq){
        totalCnt += (count * (count - 1)) / 2;
    }

    return totalCnt;
}

int main(){
    vector<int> nums = {1, 2, 3, 1, 1, 3};
    cout << "Number of good pairs: " << numIdenticalPairs(nums) << endl;
    return 0;
}