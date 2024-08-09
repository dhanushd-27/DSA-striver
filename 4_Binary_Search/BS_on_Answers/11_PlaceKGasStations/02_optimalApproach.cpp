#include <bits/stdc++.h>
using namespace std;

int numberOfGasStations(long double dist, vector<int> arr){
    int cnt = 0;
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int numberInBetween = ((arr[i] - arr[i-1]) / dist);
        if((arr[i] - arr[i-1]) / dist == numberInBetween * dist){
            numberInBetween--;
        }
        cnt += numberInBetween;
    }

    return cnt;
}

long double minimiseMaxDistance(vector<int> a, int k){
    int n = a.size();

    long double low = 0;
    long double high = 0;

    for(int i = 0; i < n; i++){
        high = max(high, (long double)(a[i+1] - a[i]));
    }

    long double diff = 1e-6;

    while(high - low > diff){
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStations(mid, a);

        if(cnt > k) low = mid;
        else high = mid;
    }
    
    return high;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}