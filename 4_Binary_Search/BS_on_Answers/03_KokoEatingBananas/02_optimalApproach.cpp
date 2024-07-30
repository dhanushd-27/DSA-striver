// Using Binary search
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
    int low = 1, high = maxi;

    while(low <= high){
        int mid = (low+high)/2;

        // if tno of hrs is lesser than h
        if(countTotalHrs(piles, mid) <= h) high = mid - 1;
        // if no of hrs is more than h
        else low = mid + 1;
    }
    return low;
}

int main(){
    vector<int> piles = {7, 15, 6, 3, 12};
    int h = 8;
    int ans = minEatingSpeed(piles, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}