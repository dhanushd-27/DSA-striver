#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> a, int k){
    int n = a.size();
    int low = 0, high = n - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(a[mid] == k) return true;

        if(a[mid] == a[low] && a[mid] == a[high]){
            low++;
            high--;
            continue;
        }

        if(a[low] <= a[mid]){
            if(a[low] <= k && k <= a[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            if(a[mid] <= k && k <= a[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
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
