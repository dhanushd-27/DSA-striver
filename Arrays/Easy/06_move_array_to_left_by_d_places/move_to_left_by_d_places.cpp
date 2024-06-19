#include <bits/stdc++.h>
using namespace std;

void brute_approach(vector<int> &arr, int size, int d){
    vector<int> temp(d);
    
    int i;
    if (d > size){
        d = d % size;
    }

    if(d > 0){
        /* Move values at 0 to d index from given arr to temp arr */
        
        for(i = 0; i < d; i++){
            temp[i] = arr[i];
        }

        // Move elements after dth index to starting position 0 to d
        for(i = d; i < size; i++){
            arr[i-d] = arr[i];
        }

        // store temp array values from dth + 1 index to n - 1th index
        for(i = 0; i < d; i++){
            arr[i+(size-d)] = temp[i];
        }
    }

}

// Optimal approach with respect to Space Complexity
void optimal_approach(vector<int> &arr, int size, int d){
    reverse(arr.begin() +0, arr.begin()+d);
    reverse(arr.begin() +d, arr.begin()+ size);
    reverse(arr.begin(), arr.end());
}

int main(){
    int size, d = 3;
    vector<int> arr;

    arr = {1,2,3,4,5,6,7,8};
    size = arr.size();

    cout<<"Enter the dth position:  "<<endl;
    cin>> d;

    cout<< "Using Brute Approach";
    cout<< "\n---------------------------------------------------------------\n";
    printf("Array Before Manipulation:  ");
    for(int i = 0; i < size; i++){
        cout<< arr[i]<< " ";
    }
    cout<< endl;

    brute_approach(arr, size, d);

    printf("Array After Manipulation:  ");
    for(int i = 0; i < size; i++){
        cout<< arr[i]<< " ";
    }

    arr = {1,2,3,4,5,6,7,8};
    cout<< "\n\n\n\nUsing Optimal Approach";
    cout<< "\n---------------------------------------------------------------\n";
    printf("Array Before Manipulation:  ");
    for(int i = 0; i < size; i++){
        cout<< arr[i]<< " ";
    }
    cout<< endl;

    optimal_approach(arr, size, d);

    printf("Array After Manipulation:  ");
    for(int i = 0; i < size; i++){
        cout<< arr[i]<< " ";
    }
}