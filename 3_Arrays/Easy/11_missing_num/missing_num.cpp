#include <bits/stdc++.h>
using namespace std;

int brute_approach(vector<int> arr, int arr_size){
    // vector<int> arr = {1, 2, 4, 5};
    for(int i = 1; i <= arr_size; i++){
        int flag = 0;
        for(int j = 0; j < arr_size-1; j++){
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            return i;   
        }
    }
    return -1;
}

int better_approach(vector<int> arr, int arr_size){
    int hash[arr_size + 1] = {0};

    for(int i = 0; i < arr_size; i++){
        hash[arr[i]] = 1;
    }

    for(int j = 1; j <= arr_size; j++){
        if(hash[j] == 0){
            return j;
        }
    }

    return -1;
}

int optimal_approah_sum(vector<int> arr, int arr_size){
    int sum = 0;
    int formula_sum = (arr_size * (arr_size + 1)) / 2;

    for(int i = 0; i < arr_size-1; i++){\
        sum = sum + arr[i];
    }
    return formula_sum - sum;;
}

int optimal_approach_xor(vector<int> arr, int arr_size){
    int xor1,  xor2;

    for(int i = 0; i < arr_size - 1; i++){
        xor1 ^= arr[i];
        xor2 ^= i+1;
    }

    xor2 ^= arr_size;

    return xor1 ^ xor2;
}

int main(){
    vector<int> arr = {1, 2, 4, 5};
    
    int brute_app = brute_approach(arr, 5);
    int better_app = better_approach(arr, arr.size());
    int sum = optimal_approah_sum(arr, 5);
    int xor1 = optimal_approach_xor(arr, 5);

    cout<< brute_app<<" "<< better_app<< " "<< sum<< " "<< xor1;
    return 0;
}