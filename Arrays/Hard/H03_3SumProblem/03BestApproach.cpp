// Two Pointer Approach

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triple(vector<int> a){
    int n = a.size();
    vector<vector<int>> ans;
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++){
        
        if(i != 0 && a[i] == a[i-1]) continue;

        int j = i + 1;
        int k = n - 1;

        while(j < k){
            int sum = a[i] + a[j] + a[k];
            if(sum > 0) k--;
            else if(sum < 0) j++;
            else{
                vector<int> temp = {a[i], a[j], a[k]};
                ans.push_back(temp);
                j++;
                k--;

                while(j < k && a[j] == a[j-1]) j--;
                while(j < k && a[k] == a[k+1]) k++; 
            }

            
        }
    }

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
