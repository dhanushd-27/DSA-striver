#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a){
    int n = a.size();
    int hashMap[n + 1] = {0};

    for(int i = 0; i < n; i++){
        hashMap[a[i]]++;
    }

    int repeating = -1, miss = -1;
    for(int i = 1; i <= n; i++){
        if(hashMap[i] == 2){
            repeating = i;
        }
        else if(hashMap[i] == 0){
            miss = i;
        }

        if(repeating != -1 && miss != -1) break;
    }

    return {repeating, miss};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
        << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}
