// Elements in Given Array are not repeated

#include <bits/stdc++.h>
using namespace std;

int search(vector<int> a, int n, int key){
    int low = 0, high = n - 1;

    while(low <= high){    
        int mid = (low + high) / 2;
        
        // Element present at mid
        if(a[mid] == key) return mid;

        // Find the sorted half

        // Left is sorted
        if(a[low] <= a[mid]){
            // Find whether element is present or not
            if(a[low] <= key && key <= a[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        // Right is sorted
        else{
            if(a[mid] <= key && key <= a[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
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