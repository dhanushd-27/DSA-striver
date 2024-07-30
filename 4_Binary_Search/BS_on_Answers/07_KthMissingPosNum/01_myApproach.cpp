#include <bits/stdc++.h>
using namespace std;

int missingK(vector<int> vec, int n, int k){
    int index = 0, cnt = 0;
    int maxx = vec[n-1];

    for(int i = 0; i < maxx; i++){
        if(vec[index] == i) index++;
        else{
            if(cnt == k) return i;
            cnt++;
        }
    }

    return -1;
}

int main(){
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}

// TC: O(Maxx): In worst case the kth missing value could be an element just less then maxx
// SC: O(1)