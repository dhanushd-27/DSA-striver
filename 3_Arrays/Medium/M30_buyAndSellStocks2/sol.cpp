#include <bits/stdc++.h>
using namespace std;

// TC - O(n)
// SC - O(1)

int maxProfit(vector<int>& prices) {
    int size = prices.size();
    int profit = 0;

    // just sell the stock if it is greater than yesterday
    for(int i = 1; i < size; i++){
        if(prices[i] > prices[i-1]){
            profit += (prices[i] - prices[i - 1]);
        }
    }

    return profit;
}