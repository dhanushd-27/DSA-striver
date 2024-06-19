#include <bits/stdc++.h>
using namespace std;

int brute_approach(int arr[], int n){

    int max_profit = 0;
    int profit = 0;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[j] > arr[i]){
                profit = arr[j] - arr[i];
                max_profit = max(max_profit, profit);
            }
        }
    }

    return max_profit;
}

int optimal_approach(int arr[], int n){
    int maxPro = 0;
    int minPrice = INT_MAX;

    for(int i = 0; i < n; i++){
        minPrice = min(arr[i], minPrice);
        maxPro = max(maxPro, arr[i] - minPrice);
    }

    return maxPro;
}

int main(){
    int arr[] = {7,1,5,3,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxPro = brute_approach(arr, n);
    cout << "Max profit is: " << maxPro << endl;

    maxPro = optimal_approach(arr, n);
    cout << "Max profit is: " << maxPro << endl;
}