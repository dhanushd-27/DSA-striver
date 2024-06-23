#include <bits/stdc++.h>
using namespace std;

// This is brute approach where we use extra space to solve the problem i.e a3
void merge(long long a1[], long long a2[], int n, int m){
    long long a3[m+n];

    int len = m + n;
    int left = 0;
    int right = 0; 
    int index = 0;

    // Add all elements in order to a3
    while(left < n && right < m){
        if(a1[left] <= a2[right]){
            a3[index++] = a1[left++];
        }
        else{
            a3[index++] = a2[right++];
        }
    }

    while(left < n){
        a3[index++] = a1[left++];
    }

    while(right < m){
        a3[index++] = a2[right++];
    }

    //Now Add elements in order from a3 to a1 and a2 respectively
    index = 0;
    while(index < len){
        if(index < n){
            a1[index] = a3[index];
            index++;
        }
        else{
            a2[index - n] = a3[index];
            index++;
        }
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