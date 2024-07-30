#include <bits/stdc++.h>
using namespace std;

/* Search for the index of the target value in the array

    If the value is present in the array, then return its index.
    Otherwise, determine the index where it would be inserted in the array
    while maintaining the sorted order.
*/
int searchInsert(vector<int> a, int x){
    int n = a.size();
    int low = 0, high = n-1;
    int ans = n;

    while(low <= high){
        int mid = (low + high) / 2;

        if(a[mid] >= x){
            ans = mid;
            high = mid - 1;
        }

        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 4, 7};
    int x = 6;
    int ind = searchInsert(arr, x);
    cout << "The index is: " << ind << "\n";
    return 0;
}