// Condition: Every other element is repeated twice except 1. return that element
// The array is sorted
#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> a){
    int n = a.size();
    if(n == 1){
        return a[0];
    }

    for(int i = 0; i < n; i++){

        if(i == 0){
            if(a[i] != a[i + 1]){
                return a[i];
            }
        }
        else if (i == n - 1){
            if(a[i] != a[i-1]){
                return a[i];
            }
        }

        else{
            if(a[i] != a[i-1] && a[i] != a[i+1]){
                return a[i];
            }
        }
    }

    return -1;
}


int main(){
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 7, 8, 8, 9, 9};
    int ans = singleNonDuplicate(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;
}