#include <bits/stdc++.h>
using namespace std;

// Total of four approaches

// Brute Approach - Two loops find product of all elements except self - TC - O(n^2) - SC - O(1)

// Better Approach - using divide approach
// Note - No of zeroes, product without zeroes, if noOfzeroes > 1 all values are zero

// Optimal Approach - find product of all left elements -> find product of all right elements -> return res

// TC - O(n)
// SC - O(1)

vector<int> productExceptSelf(vector<int>& nums) {
    int leftProd = 1;
    int rightProd = 1;
    int size = nums.size();

    vector<int> res(size);

    // Iterate for the left product first
    for(int i = 0; i < size; i++){
        res[i] = leftProd;
        leftProd *= nums[i];
    }

    // Iterate for the right product second
    for(int i = size-1; i >= 0; i--){
        res[i] = res[i] * rightProd;
        rightProd *= nums[i];
    }

    return res;
}