// Find the maximum possible minimum distance

#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> stalls, int cows, int dist){
    int n = stalls.size();
    int cntCows = 1, last = stalls[0];

    for(int i = 1; i < n; i++){
        if(stalls[1] - last >= dist){
            cntCows++;
            last = stalls[i];
        }

        if(cntCows >= cows) return true;
    }

    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); //size of array
    //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int limit = stalls[n - 1] - stalls[0];
    for (int i = 1; i <= limit; i++) {
        if (possible(stalls, k, i) == false) {
            return (i - 1);
        }
    }
    return limit;
}

int main(){
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}