// Two Pointer Approach
// Given an array arr consisting of only 0's and 1's in random order. Modify the array in-place to segregate 0s onto the left side and 1s onto the right side of the array.

#include <bits/stdc++.h>
using namespace std;

void segregate0and1(vector<int> &arr) {
    int left = 0;
    int right = arr.size() - 1;

    while(left < right){
        while(arr[left] != 1 && left < right) left++;

        while(arr[right] != 0 && left < right) right--;

        if(left < right){
            arr[left] = 0;
            arr[right] = 1;
            left++;
            right--;
        }
    }
}

int main(){
    vector<int> arr = {0, 0, 1, 1, 0};

    cout<< "Elements before segregation: "<< endl;
    for(int i = 0; i < arr.size(); i++) cout<< arr[i]<< " ";

    segregate0and1(arr);

    cout<< endl<< "Elements after segregation: "<< endl;
    for(int i = 0; i < arr.size(); i++) cout<< arr[i]<< " ";
}