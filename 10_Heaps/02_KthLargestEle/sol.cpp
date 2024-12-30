#include <bits/stdc++.h>
using namespace std;

vector<int> kLargest(vector<int>& arr, int k) {
    // code here
    priority_queue<int, vector<int>, greater<int>> pq;
    int size = arr.size();
    
    for(int i = 0; i < size; i++){
        pq.push(arr[i]);
        
        if(pq.size() > k){
            pq.pop();
        }
    }
    
    vector<int> res;
    
    while(pq.size() > 0){
        res.push_back(pq.top());
        pq.pop();
    }
    
    reverse(res.begin(), res.end());
    return res;
}