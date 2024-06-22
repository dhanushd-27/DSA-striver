// Using Hashing

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triple(vector<int> &a){
    set<vector<int>> st;
    int n = a.size();

    for(int i = 0; i < n; i++){
        set<int> hash;
        for(int j = i+1; j < n; j++){
            int third = -(a[i] + a[j]);

            if(hash.find(third) != hash.end()){
                vector<int> temp = {a[i], a[j] , third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hash.insert(a[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans; 
}

int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = triple(arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}