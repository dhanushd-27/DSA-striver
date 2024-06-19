#include <bits/stdc++.h>
using namespace std;

void move_to_left_by_one(vector<int> &arr, int size){
    int temp;

    temp = arr[0];
    for(int i = 1; i < size; i++){
        arr[i-1] = arr[i];
    }
    arr[size-1] = temp;

    // Time Complexity: O(N)
    // Space Complexity: O(1)(i.e for extra space used)
}

int main(){
    int size; vector<int> arr;

    arr = {1,2,3,4,5};
    size = arr.size();

    printf("Array Before manipulation:  ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    move_to_left_by_one(arr, size);

    printf("Array After manipulation:  ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}