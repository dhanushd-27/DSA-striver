/*
You are given 'N’ roses and you are also given an array 'arr'  where 'arr[i]'  denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.
*/

#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int>& bloomDay, int Day, int m, int k){
    int n = bloomDay.size();
    int bouquets = 0, cnt = 0;

    for(int i = 0; i < n; i++){
        if(bloomDay[i] <= Day) cnt++;

        else{
            bouquets += cnt/k;
            cnt = 0;
        }
    }

    bouquets += cnt/k;
    return bouquets >= m;
}

int minDay(vector<int> bloomDay, int k, int m){
    // The impossible case
    long long val = k * m;
    int n = bloomDay.size();
    if(val > n) return -1;

    int minn = *min_element(bloomDay.begin(), bloomDay.end());
    int maxx = *max_element(bloomDay.begin(), bloomDay.end());

    for(int Day = minn; Day <= maxx; Day++){
        if(possible(bloomDay, Day, m, k)) return Day;
    }
    return -1;
}

int main(){
    vector<int> bloomDay = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = minDay(bloomDay, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}