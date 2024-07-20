#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> a){
    int n = a.size();

    int low = 1, high = n - 2;

    if(a[0] != a[1]) return a[0];

    if(a[n-1] != a[n-2]) return a[n-1];

    while(low <= high){
        int mid = (low + high) / 2;

        if(a[mid] != a[mid + 1] && a[mid] != a[mid - 1]){
            return a[mid];
        }

        if ((mid % 2 == 1 && a[mid] == a[mid - 1])
                || (mid % 2 == 0 && a[mid] == a[mid + 1])) {
            //eliminate the left half:
            low = mid + 1;
        }

        else{
            high = mid - 1;
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