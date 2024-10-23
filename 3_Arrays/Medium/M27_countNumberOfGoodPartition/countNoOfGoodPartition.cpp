#include <bits/stdc++.h>
using namespace std;

// TC: O(n) + O(n)
// SC: O(m) m is the number of different elements

int M = 1e9 + 7;
int numberOfGoodPartitions(vector<int>& nums) {

    // Keep a note of last occurences of all elements
    unordered_map<int, int> hash;
    int n = nums.size();

    // O(n);
    for(int i = 0; i < n; i++){
        hash[nums[i]] = i;
    }

    // Intialize j and point j to last occurence of nums[i] value
    int i = 0;
    int j = max(0, hash[nums[0]]);
    int result = 1;

    // Loop through the array
    while(i < n){

        // If i moves ahead of j, it means we have a new partition
        if(i > j){
            // mod 1e9 + 7 because the result value might cross INT_MAX 
            result = (result*2) % M;
        }

        // if the current number doesn't have any further occurences the j position should be the same
        j = max(j, hash[nums[i]]);
        i++;
    }
    return result;
}