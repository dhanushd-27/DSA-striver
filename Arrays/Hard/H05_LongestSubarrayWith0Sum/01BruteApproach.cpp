#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> a){
    int maxLen = 0;
    int n = a.size();
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            
            sum += a[j];
            if(sum == 0){
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    return maxLen;
}

int main(){
    vector<int> a = {9, -3, 3, -1, 6, -5};
    cout << solve(a) << endl;

    return 0;
}