// Leetcode - 88. Merge Sorted Arrays
/* You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively. */

#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<int>& nums1, int m, vector<int>& nums2, int n){
    
    for(int i = 0; i < n; i++){
        nums1[m + i] = nums2[i];
    }

    sort(nums1.begin(), nums1.end());
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