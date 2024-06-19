#include <bits/stdc++.h>
using namespace std;

// using double traversal
int brute_approach(vector<int> arr, int size){
    int num = 0;
    int cnt = 0;
    for (int i = 0; i < size; i++){
        num = arr[i];
        cnt = 0;
        for (int j = 0; j < size; j++){
            if (num == arr[j])
                cnt++;
        }
        if (cnt == 1){
            return num;
        }
    }
}

// using hashing
int better_approach_1(vector<int> arr, int size){
    
    // Find the max element in the given arr
    int maxi = 0;
    for (int i = 0; i < size; i++){
        maxi = max(maxi, arr[i]);
    }

    // Declare an array hash with size of max(arr) + 1, and all values as
    vector<int> hash(maxi + 1, 0);

    // Count the number occurences of each number arr[i]
    for (int i = 0; i < size; i ++){
        hash[arr[i]]++;
    }

    // Traverse through all elements of hash if an ele = 1, return i
    for (int i = 0; i < size; i++){
        if (hash[arr[i]] = 1)
            return arr[i];
    }

    // TC: O(3N) 
    // SC: O(hash.size())
    return -1;
}

// using mapping
int better_approach_2(vector<int> arr, int size){
    map<int, int> mpp;

    for(int i = 0; i < size; i++){
        mpp[arr[i]] += 1;
    }

    for(int i = 0; i < size; i++){
        if(mpp[arr[i]] == 1){
            return arr[i];
        }
    }

    return -1;
}

int getSingleElement(vector<int> &arr) {
    //size of the array:
    int n = arr.size();

    // XOR all the elements:
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}

int main(){
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = 0;

    ans = brute_approach(arr, arr.size());
    cout << "The single element by brute approach is: " << ans << endl;
    ans = better_approach_1(arr, arr.size());
    cout << "The single element by 1st better approach is: " << ans << endl;
    ans = better_approach_2(arr, arr.size());
    cout << "The single element by 2nd better approach is: " << ans << endl;
    ans = getSingleElement(arr);
    cout << "The single element by optimal approach is: " << ans << endl;
    return 0;
}