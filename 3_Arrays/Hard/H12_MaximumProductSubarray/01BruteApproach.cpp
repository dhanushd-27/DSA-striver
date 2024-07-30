#include <bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int> a){
    int n = a.size();
    int result = INT_MIN;
    for(int i = 0; i < n; i++){
        int p = 1;
        for(int j = i; j < n; j++){
            p *= a[j];
            result = max(result, p);
        }
    }

    return result;
}

int main(){
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}