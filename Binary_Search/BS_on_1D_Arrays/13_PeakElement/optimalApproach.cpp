// Peak element: For a given array, find the peak element in the array. Peak element is one which is greater than both, left and right
// Return the index of the peak element

#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> arr){
    int n = arr.size();

    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;

    int low = 1, high = n-2;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
            return mid;
        }

        if(arr[mid] > arr[mid - 1]) low = mid + 1;
        else high = mid - 1;
    }

    return -1;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 1};
    int ind = findPeakElement(arr);
    cout<< "The index of the peak element is: "<< ind<< endl;
    return 0;
}