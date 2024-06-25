// Select the smallest element and send it in the beginning

#include <bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n){
    for(int i = 0; i < n; i++){
        int mini = i;
        for(int j = i + 1; j < n; j++){
            if(a[mini] > a[j]) mini = j;
        }
        int temp = a[i];
        a[i] = a[mini];
        a[mini] = temp;
    }
}

int main(){
    int arr[] = {13,46,24,52,20,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before selection sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    selectionSort(arr, n);
    
    cout << "After selection sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}