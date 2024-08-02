#include <bits/stdc++.h>
using namespace std;

int partitions(vector<int> nums, int n, int sum){
    int curSum = nums[0], partitions = 1;

    for(int i = 1; i < n; i++){
        if(curSum + nums[i] <= sum){
            curSum += nums[i];
        }
        else{
            partitions++;
            curSum = nums[i];
        }
    }

    return partitions;
}

int splitArray(vector<int> nums, int k){
    int n = nums.size();

    // Impossible case i.e we can't have more partitions than the total number of elements
    if(k > n) return -1;

    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while(low <= high){
        int mid = (low + high) / 2;
        if(partitions(nums, n, mid) > k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return low;
}

// TC: O(N*logN)
// SC: O(1)

int main()
{
    vector<int> a = {10, 20, 30, 40};
    int k = 2;
    int ans = splitArray(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}