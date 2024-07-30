#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a){
    int n = a.size();

    vector<int> ans;
    int rem = -1;
    int miss = -1;
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(i == a[j]){
                cnt++;
            }
        }
        if(cnt == 2){
            rem = i;
        }
        else if(cnt == 0){
            miss = i;
        }

        if(rem != -1 && miss != -1) break;
    }

    return ans = {rem, miss};
}

int main(){
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
        << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}