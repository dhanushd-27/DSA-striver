#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
int main(){
    vector<int> arr = {1, 2, 3, 4, 5};

    for(int i = 1; i < arr.size();  i++){
        if(arr[i] < arr[i-1]){
            cout<<"False! It is not a sorted array";
            return 0;
        }
    }
    printf("True it is a sorted array");
}