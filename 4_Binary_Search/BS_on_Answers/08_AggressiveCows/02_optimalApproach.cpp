// Optimal Approach of solving it is by using Binary Search

#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int>& stalls, int dist, int cows){
    int cntCows = 1;
    int last = stalls[0];
    int n = stalls.size();

    for(int i = 0; i < n; i++){
        if(stalls[i] - last >= dist){
            cntCows++;
            last = stalls[i];
        }

        if(cntCows >= cows) return true;
    }

    return false;
}

int aggressiveCows(vector<int>& stalls, int cows){
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());

    int limit = stalls[n-1] - stalls[0];

    int low = 1, high = limit;

    while(low <= high){
        int mid = (low + high) / 2;

        if(possible(stalls, mid, cows)){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return high;
}

int main(){
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}