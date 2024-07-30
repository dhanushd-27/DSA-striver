#include <bits/stdc++.h>
using namespace std;

// find the total no of days to ship all weights with given capacity cap
bool findDays(vector<int>& weights, int cap, int days){
    int needDay = 1;
    int n = weights.size();
    int curCap = 0;

    for(int i = 0; i < n; i++){
        if(curCap + weights[i] <= cap){
            curCap += weights[i];
        }
        else{
            needDay++;
            curCap = weights[i];
        }
    }

    return needDay <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    // accumulate(first_index, last_index, initial value of sum);
    int high = accumulate(weights.begin(), weights.end(), 0);

    for(int Day = low; Day <= high; Day++){
        if(findDays(weights, Day, days)){
            return Day;
        }
    }

    return -1;
}

int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = shipWithinDays(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}