#include <bits/stdc++.h>
using namespace std;

void brute_approach(vector<int> &arr, int size){
// Declare Temporary Array
    vector<int> temp;

// Insert all non zero values in temporary array
    for(int i: arr){
        if(i != 0){
            temp.push_back(i);
        }
    }

// Size of Temporary Array
    int t_size = temp.size();

// Insert all non zeros ele's in temp to orginal array
    int j = 0;
    for(int i: temp){
        arr[j] = i;
        j++;
    }

// Insert zero's at the end
    for(int i = t_size; i < size; i++){
        arr[i] = 0;
    }
}

void optimal_approach(vector<int> &arr, int size){
    // Appraoch used is 2 pointer approach
    int i, j;

    j = -1;

    for(int k = 0; k < size; k++){
        if(arr[k] == 0){
            j = k;
            break;
        }
    }

    for(int i = j+1; i < size; i++){
        if(arr[i] != 0){
            arr[j] = arr[i];
            arr[i] = 0;
            j++;
        }
    }
}

int main(){
    vector<int> arr = {1, 0, 2, 3, 0, 0, 4, 0};
    brute_approach(arr, 8);
    for(int i: arr){
        cout<<i<< " ";
    }

    cout<< endl;

    arr = {1, 0, 2, 3, 0, 0, 4, 0};

    optimal_approach(arr, 8);
    for(int i: arr){
        cout<<i<< " ";
    }
}