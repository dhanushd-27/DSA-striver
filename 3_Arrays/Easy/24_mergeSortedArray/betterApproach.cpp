// Leetcode - 88. Merge Sorted Arrays
/* You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively. */

#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<int>& nums1, int m, vector<int>& nums2, int n){
    vector<int> combinedArray(m+n, 0);

    for(int i = 0; i < m; i++){
        combinedArray[i] = nums1[i];
    }

    for(int j = 0; j < n; j++){
        combinedArray[m + j] = nums2[j];
    }

    sort(combinedArray.begin(), combinedArray.end());

    for(int k = 0; k < m + n; k++){
        nums1[k] = combinedArray[k];
    }
}

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    int m = 3, n = 3;

    mergeSort(nums1, m, nums2, n);

    cout<< "The Merge Sorted Array is: ";
    for(int i = 0; i < m+n; i++){
        cout<< nums1[i]<< " ";
    }

    cout<< endl;
    
    return 0;
}