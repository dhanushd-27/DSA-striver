#include <bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> a){
    int sum = 0;
    int n = a.size();
    int maxi = 0;
    unordered_map<int, int> mpp;

    for(int i = 0; i < n; i++){
        sum += a[i];

        if(sum == 0){
            maxi = i+1;
        }
        else{
            if(mpp.find(sum) != mpp.end()){
                maxi = max(maxi, i - mpp[sum]);
            }
            else{
                mpp[sum] = i;
            }
        }
    }

    return maxi;
}

int main(){
    vector<int> a = {9, -3, 3, -1, 6, -5};
    cout << solve(a) << endl;

    return 0;
}