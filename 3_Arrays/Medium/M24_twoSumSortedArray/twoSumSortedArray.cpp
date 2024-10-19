#include <bits/stdc++.h>
using namespace std;

// Leetcode - 167. Two Sum 2 - Input Array Is Sorted
vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;

    while(left < right){
        int sum = numbers[left] + numbers[right];
        if(sum == target){
            return {left + 1, right + 1};
        }
        else if(sum > target){
            right--;
        }
        else{
            left++;
        }
    }

    return {};
}