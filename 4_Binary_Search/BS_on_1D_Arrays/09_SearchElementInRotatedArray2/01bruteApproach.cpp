// Elements in given array are repeated

#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> a, int k){
    int n = a.size();
    for(int i = 0; i < n; i++){
        if(a[i] == k) return true;
    }

    return false;
}

int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;
    bool ans = search(arr, k);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";
    return 0;
}