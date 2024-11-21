#include <bits/stdc++.h>
using namespace std;

// TC - O(2^n)
// SC - O(n) - Recursive stack space

void printSubsetOfSumK(int index, vector<int> subset, int sum, vector<int> &nums, int size, int k){
    if(index == size){
        if(sum == k){
            int n = subset.size();
            for(int i = 0; i < n; i++){
                cout<< subset[i]<< " ";
            }
            cout<< endl;
        }
        return;
    }

    subset.push_back(nums[index]);
    printSubsetOfSumK(index+1, subset, sum+nums[index], nums, size, k);
    subset.pop_back();
    printSubsetOfSumK(index+1, subset, sum, nums, size, k);
}

void findSubsetsOfSumK(vector<int>& nums, int k) {
    
    vector<int> subset;
    vector<vector<int>> res;
    int size = nums.size();
    int sum = 0;

    printSubsetOfSumK(0, subset, sum, nums, size, k);

    return;
}

// Count number of sequences
int countSubsets(int index, int sum, vector<int> &nums, int size, int k){
    if(index == size){
        if(sum == k){
            return 1;
        }
        return 0;
    }

    int l = countSubsets(index+1, sum+nums[index], nums, size, k);

    int r = countSubsets(index+1, sum, nums, size, k);

    return l + r;
}

int main(){
    vector<int> nums = { 5, 3, 2, 4, 1, 6 };
    findSubsetsOfSumK(nums, 9);
    cout<< endl<< endl;
    int res = countSubsets(0, 0, nums, nums.size(), 9);
    cout<< "Number of subsets are: "<< res<< endl;
}
