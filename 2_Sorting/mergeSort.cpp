#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int low, int mid, int high){
    vector<int> temp;

    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high){

        if(a[left] <= a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(a[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(a[right]);
        right++;
    }

    for(int i = low; i <= high; i++){
        a[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &a, int low, int high){
    if(low >= high) return;

    int mid = (low + high) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid+1, high);
    merge(a, low, mid, high);
}

int main(){
    vector<int> arr = {13,46,24,52,20,9};
    int n = arr.size();
    cout << "Before selection sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    int low = 0;
    int high = n-1;
    mergeSort(arr, low, high);
    
    cout << "After selection sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}