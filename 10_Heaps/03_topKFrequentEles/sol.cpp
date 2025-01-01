#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ppi;

vector<int> topKFrequent(vector<int>& nums, int k) {
    int size = nums.size();

    if(size == 1) return nums;
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq; // min heap
    unordered_map<int, int> hash;
    for(int i = 0; i < size; i++){
        hash[nums[i]]++;
    }

    for(auto ele: hash){
        pq.push({ ele.second, ele.first });

        if(pq.size() > k) pq.pop();
    }

    vector<int> res;
    while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}