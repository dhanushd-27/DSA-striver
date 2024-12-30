#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> &arr, int k) {
    // code here
    priority_queue<int> maxHeap;
    int size = arr.size();
    for(int i = 0; i < size; i++){
        maxHeap.push(arr[i]);
        if(maxHeap.size() > k) maxHeap.pop();
    }
    
    return maxHeap.top();
}

