#include <bits/stdc++.h>
using namespace std;

// Given an array arr consisting of only 0's and 1's in random order. Modify the array in-place to segregate 0s onto the left side and 1s onto the right side of the array.

void segregate0and1(vector<int> &arr) {
    // code here
    int cnt = 0;
    //Count number of 0's
    for(int i = 0; i < arr.size(); i ++){
        if(arr[i] == 0) cnt++;
    }
    
    for(int i = 0; i < cnt; i ++) arr[i] = 0;
    
    for(int i = cnt; i < arr.size(); i ++) arr[i] = 1;
    
    // TC: O(N) + 0(N)
    // SC: O(1)
}

int main(){
    vector<int> arr = {0, 0, 1, 1, 0};

    cout<< "Elements before segregation: "<< endl;
    for(int i = 0; i < arr.size(); i++) cout<< arr[i]<< " ";

    segregate0and1(arr);

    cout<< endl<< "Elements after segregation: "<< endl;
    for(int i = 0; i < arr.size(); i++) cout<< arr[i]<< " ";
}