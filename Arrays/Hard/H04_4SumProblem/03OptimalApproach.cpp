#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> a, int target){
    //Sort
    sort(a.begin(), a.end());
    int n = a.size();
    set<vector<int>> st;

    for(int i = 0; i < n; i++){
        if(i != 0 && a[i] == a[i - 1]) continue;
        for(int j = i+1; j < n; j++){
            if(j > i+1 && a[j] == a[j-1]) continue;
            int k = j+1;
            int l = n-1;

            while(k < l){
                long long sum = a[i] + a[j];
                sum += a[k];
                sum += a[l];

                if(sum > target) l--;
                else if(sum < target) k++;
                else{
                    vector<int> temp = {a[i], a[j], a[k], a[l]};
                    st.insert(temp);
                    k++, l--;

                    while(k < l && a[k] == a[k-1]) k++;
                    while(k < l && a[l] == a[l-1]) l--;
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
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