#include <bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    int count =0;
    int n = nums.size();
    for(int i=0 ;i< n ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(nums[i]==nums[j])
            count++;
        }
    } 
    return count;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 3};
    cout << "Number of good pairs: " << numIdenticalPairs(nums) << endl;
    return 0;
}