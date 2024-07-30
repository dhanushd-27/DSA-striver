#include <bits/stdc++.h>
using namespace std;

void brute_approach(vector<int> arr){
    sort(arr.begin(), arr.end());
    printf("The max element is %d\n", *(arr.end() - 1));
}

void optimal_approach(vector<int> arr){
    int max = *arr.begin(); //v[0]
    for(int i: arr){
        if (max < i){                
            max = i;
        }
    }
    cout<<max<<endl;
}

int main(){

    vector<int> v = {20, 10, 50, 40, 70};
    // Sort the given arr and print the last element
    brute_approach(v);

    // Optimal Approach
    // Iterate through the array and compare each value with max val
    // let max be first element and swap if you find a bigger ele than current max
    optimal_approach(v);
    return 0;
}