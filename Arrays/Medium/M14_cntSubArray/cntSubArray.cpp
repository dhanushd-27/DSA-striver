#include <bits/stdc++.h>
using namespace std;

//Refer striver's DSA Sheet for Brute and Better approach
int optimalApproach(vector<int> A, int sum){
    int n = A.size();
    int preSum = 0;
    int cnt = 0;

    map<int, int> mpp;
    mpp[0] = 1;
    for(int i = 0; i < n; i++){
        preSum += A[i];
        int rem = preSum - sum;
        cnt += mpp[rem];
        mpp[preSum] += 1;
    }
    return cnt;
}
int main(){
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = optimalApproach(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}