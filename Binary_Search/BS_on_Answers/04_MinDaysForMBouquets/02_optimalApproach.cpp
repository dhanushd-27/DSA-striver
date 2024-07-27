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

int minDay(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
    int n = bloomDay.size();
    if (val > n) return -1;

    int minn = *min_element(bloomDay.begin(), bloomDay.end());
    int maxi = *max_element(bloomDay.begin(), bloomDay.end());

    int low = minn, high = maxi;

    while(low <= high){
        int mid = low + ((high - low)/2);

        if(possible(bloomDay, mid, m, k)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
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