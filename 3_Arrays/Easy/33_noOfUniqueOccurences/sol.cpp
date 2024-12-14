#include <bits/stdc++.h>
using namespace std;

// TC - O(2n)
// SC - O(2n)

bool uniqueOccurrences(vector<int>& arr) {
    // Approach 1 - Using hashmap and set
    // Approach 2 - Using a vector of size 2000 - [x + 1000]

    unordered_map<int, int> hash;

    for(int& x: arr){
        hash[x]++;
    }

    unordered_set<int> hashSet;

    for(auto& it: hash){
        if(hashSet.find(it.second) != hashSet.end()){
            return false;
        }
        hashSet.insert(it.second);
    }

    return true;
}
