// The Logic is: The index of the lowest no is the number of time the array has been rotated

#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> a){
    int n = a.size();
    int low = 0, high = n - 1;

    // Stores Index of the minimum value
    int ind = -1;
    // Stores minimum value
    int ans = INT_MAX;

    while(low <= high){
        int mid = (low + high) / 2;

        if(a[low] <= a[mid]){
            if(a[low] < ans){
                ans = a[low];
                ind = low;
            }
            low = mid + 1;
        }
        else{
            if(a[mid] < ans){
                ans = a[mid];
                ind = mid;
            }
            high = mid - 1;
        }
    }

    return ind;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findKRotation(arr);
    cout << "The array is rotated " << ans << " times.\n";
    return 0;
}