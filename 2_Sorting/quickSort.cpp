#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int low, int high){
    int pivot = a[low];
    int start = low;
    int end = high;

    while(start < end){
        while(a[start] <= pivot && start < high){
            start++;
        }

        while(a[end] > pivot && end > low){
            end--;
        }

        if(start < end){
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }

    int temp = a[low];
    a[low] = a[end];
    a[end] = temp;
    return end;
}

void quickSort(vector<int> &a, int low, int high){
    if(low < high){
        int partitionIndex = partition(a, low, high);
        quickSort(a, low, partitionIndex - 1);
        quickSort(a, partitionIndex + 1, high);
    }
    return;
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
    quickSort(arr, low, high);
    
    cout << "After selection sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}