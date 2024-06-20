#include <bits/stdc++.h>
using namespace std;

// Better Approach includes Hashing
vector<int> majorEles(vector<int> a){
    unordered_map<int, int> hash;
    vector<int> ls;
    int n = a.size();

    for(int i = 0; i < n; i++){
        hash[a[i]] += 1;

        if(hash[a[i]] > int(n/3)){
            ls.push_back(a[i]);
        }
    }

    return ls;

}

int main(){
    cout<< "Majority Elements N/3\n";
    cout<< "-------------------------------\n";

    vector<int> res;
    vector<int> arr = {1, 2, 4, 1, 3, 2, 1, 2};

    res = majorEles(arr);
    cout<< "Majority elements are: ";
    for(auto it: res){
        cout<< it<< " ";
    }
}