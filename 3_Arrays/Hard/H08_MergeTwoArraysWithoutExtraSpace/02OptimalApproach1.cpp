#include <bits/stdc++.h>
using namespace std;

// Optimal Approach 1
void merge(long long a1[], long long a2[], int n, int m){
    // It points to last element of a1
    int lastIndex = n-1;
    // It points to first element of a2
    int firstIndex = 0;

    while(a1[lastIndex] > a2[firstIndex]){
        swap(a1[lastIndex--], a2[firstIndex++]);
    }

    sort(a1, a1+n);
    sort(a2, a2+m);
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