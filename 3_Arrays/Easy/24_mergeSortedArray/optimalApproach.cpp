// Leetcode - 88. Merge Sorted Arrays
/* You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively. */

#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<int>& nums1, int m, vector<int>& nums2, int n){
    vector<int> res(m+n, 0);

    int i = 0, left = 0, right = 0;

    while(left < m && right < n){
        if(nums1[left] <= nums2[right]){
            res[i] = nums1[left];
            left++;
            i++;
        }
        else{
            res[i] = nums2[right];
            right++;
            i++;
        }
    }

    while(left < m){
        res[i++] = nums1[left++];
    }

    while(right < n){
        res[i++] = nums2[right++];
    }

    for(int i = 0; i < m+n; i++){
        nums1[i] = res[i];
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