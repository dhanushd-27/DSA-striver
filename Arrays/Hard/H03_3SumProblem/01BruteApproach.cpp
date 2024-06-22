/* In brute approach we traverse through the array thrice i.e a[i], a[j], a[k] and make sure all three elements are unique.
* Push them into a temp array and Sort the temp array
* push the temporary array into a set to avoid duplication
* now all values of set are returned in a 2d vector */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ThreeSumProblem(vector<int> a){
    
    set<vector<int>> unq;
    int n = a.size();

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(a[i] + a[j] + a[k] == 0){
                    vector<int> temp = {a[i], a[j], a[k]};
                    sort(temp.begin(), temp.end());
                    unq.insert(temp);
                }
            }
        }
    }


    vector<vector<int>> ans(unq.begin(), unq.end());
    return ans;
}

int main(){
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = ThreeSumProblem(arr);
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