// Leetcode - 88. Merge Sorted Arrays
/* You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively. */

#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<int>& nums1, int m, vector<int>& nums2, int n){

    // In Case of No Extra space to be used we can use this method to reduce the SC
    int p = m - 1;
    int q = n - 1;
    int r = nums1.size() - 1;

    while(r >= 0){
        if(q < 0){
            break;
        }

        if(p >= 0 && nums1[p] >= nums2[q]){
            nums1[r--] = nums1[p--];
        }
        else{
            nums1[r--] = nums2[q--];
        }
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