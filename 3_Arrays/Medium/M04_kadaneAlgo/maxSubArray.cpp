#include <bits/stdc++.h>
using namespace std;

// *Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which has the largest sum and returns its sum.

int better_approach(vector<int> arr){
    int n = arr.size();
    int sum = 0;
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = i; j < n; j++){
            // current subarray = arr[i.....j]

            //add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

int optimal_approach(vector<int> arr){
    int n = arr.size();
    int maxi = LONG_MIN; // maximum sum
    int sum = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
            
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;

}

int main(){

    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSumm = better_approach(arr);
    cout << "The maximum subarray sum is: " << maxSumm << endl;
    
    // * OPTIMAL APPROACH

    int maxSum = optimal_approach(arr);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}