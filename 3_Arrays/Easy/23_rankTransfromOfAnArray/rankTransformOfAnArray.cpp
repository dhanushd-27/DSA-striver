#include <bits/stdc++.h>
using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
    int n = arr.size();

    if(n == 0){
    return {};
    }

    set<int> uniqueElements(arr.begin(), arr.end());

    unordered_map<int, int> ranks;
    int rank = 1;

    for(const int &ele : uniqueElements){
    ranks[ele] = rank++;
    }

    vector<int> ans;

    for(int &ele: arr){
    ans.push_back(ranks[ele]);
    }

    return ans;
}

int main(){
    vector<int> arr = {40,10,20,30};
    vector<int> ans = arrayRankTransform(arr);

    cout<< "Ranks of given Array elements are the following"<< endl;
    for(int i = 0; i < arr.size(); i++){
        cout<< arr[i]<< " "<< ans[i]<< endl;
    }
    return 0;
}