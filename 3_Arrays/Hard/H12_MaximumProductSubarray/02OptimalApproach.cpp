#include <bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int> a){
    int n = a.size();
    int prefix = 1;
    int suffix = 1;
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;

        prefix = prefix * a[i];
        suffix = suffix * a[n - 1 - i];
        maxi = max(maxi, max(prefix, suffix));
    }

    return maxi;
}

int main(){
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}