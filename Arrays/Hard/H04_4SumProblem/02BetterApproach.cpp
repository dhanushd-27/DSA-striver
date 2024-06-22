#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> a, int target){
    int n = a.size();
    set<vector<int>> st;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            set<int> hashSet = {};

            for(int k = j+1; k < n; k++){
                int rem = target-(a[i] + a[j] + a[k]);
                if( hashSet.find(rem) != hashSet.end()){
                    vector<int> temp = {a[i], a[j], a[k], rem};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(a[k]);
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main(){
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}