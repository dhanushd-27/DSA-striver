#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> squaresOfNums;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        squaresOfNums.push_back(nums[i] * nums[i]);
    }

    sort(squaresOfNums.begin(), squaresOfNums.end());

    return squaresOfNums;
}

int main(){
    vector<int> nums = {-4,-1,0,3,10};
    int n = nums.size();
    vector<int> ans = sortedSquares(nums);

    cout<< "Sorted Squares elements";
    for(int i = 0; i < n; i++){
        cout<< ans[i]<< " ";
    }
    cout<< endl;
}