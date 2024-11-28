#include <bits/stdc++.h>
using namespace std;

// TC - O(n * n)
int partition_alog(vector<int>& nums, int L, int R){

    int i = L + 1;
    int j = R;
    int pivot = nums[L];

    // all values greater than equal to pivot to left others to right
    while(i <= j){
        if(nums[i] < pivot && nums[j] > pivot){
            swap(nums[i], nums[j]);
            i++;
            j--;
        } 
        
        if (nums[i] >= pivot) {
            i++;
        } 
        
        if( nums[j] <= pivot) {
            j--;
        }
    }

    swap(nums[L], nums[j]);

    // pivot element is at jth pos
    return j;
}

int findKthLargest(vector<int>& nums, int k) {
    
    // Approach 1 - Sorting
    // Approach 2 - Min Heap

    // Approach 3 - Haare's Partition

    int size = nums.size();

    int L = 0;
    int R = size - 1;

    int pivot_ix = 0;

    // loop until kth largest element is found
    while(true){

        pivot_ix = partition_alog(nums, L, R);

        if(pivot_ix == k - 1) {
            break;
        } else if(pivot_ix > k - 1){
            R = pivot_ix - 1;
        } else {
            L = pivot_ix + 1;
        }
    }

    return nums[pivot_ix];
}