// Elements in Given Array are not repeated

#include <bits/stdc++.h>
using namespace std;

int search(vector<int> a, int n, int key){
    for(int i = 0; i < n; i++){
        if(a[i] == key) return i;
    }

    return -1;
}

int main(){
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    int ans = search(arr, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    
    return 0;
}