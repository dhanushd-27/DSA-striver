#include <bits/stdc++.h>
using namespace std;

int countTotalHrs(vector<int> piles, int rate){
    int n = piles.size();
    int totalHrs = 0;
    for(int i = 0; i < n; i++){
        totalHrs += ceil((double) piles[i] / (double) rate);
    }
    return totalHrs;
}

int minEatingSpeed(vector<int> piles, int h){
    int maxi = *max_element(piles.begin(), piles.end());

    for(int i = 1; i <= maxi; i++){
        int totalHrs = countTotalHrs(piles, i);

        if(totalHrs <= h){
            return i;
        }
    }

    return -1;
}

int main(){
    vector<int> piles = {7, 15, 6, 3};
    int h = 8;
    int ans = minEatingSpeed(piles, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}