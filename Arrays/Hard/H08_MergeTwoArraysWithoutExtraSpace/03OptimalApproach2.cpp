#include <bits/stdc++.h>
using namespace std;

void swapIfGreater(long long a1[], long long a2[], int ind1, int ind2){
    if(a1[ind1] > a2[ind2]) swap(a1[ind1], a2[ind2]);
    else return;
}

void merge(long long a1[], long long a2[], int n, int m){
    int len = m+n;
    int gap = ceil((m+n)/2);

    while(gap > 0){
        int left = 0;
        int right = left + gap;

        while(right > len){
            //if both elements are in diff arrays
            if(left < n && right >= n){
                swapIfGreater(a1, a2, left, right - n);
            }
            // if both elements are in 2nd array
            else if(left >= n){
                swapIfGreater(a1, a2, left - n, right - n);
            }
            // if both elements are in 1st array
            else{
                swapIfGreater(a1, a2, left, right);
            }
            left++;
            right = left + gap;
        }

        if(gap == 1) break;
        gap = ceil(gap/2);
    }
}

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}