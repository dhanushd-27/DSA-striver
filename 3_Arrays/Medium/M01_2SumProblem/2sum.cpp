#include <bits/stdc++.h>
using namespace std;

string brute_approach(vector<int> arr, int k){
    int size = arr.size();

    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(arr[i] + arr[j] == k){
                printf("The array elements which sums up to %d are: %d and %d.\n", k, arr[i], arr[j]);
                return "Yes";
            }
        }
    }
    return "No";
}

string better_approach(vector<int> arr, int k){
    int size = arr.size();
    map<int, int> mpp;

    for(int i = 0; i < size; i++){

        int rem = k - arr[i];

        if(mpp.find(rem) != mpp.end()){
            printf("The array elements that sums up to %d are: %d and %d.\n", k, rem, arr[i]);
            return "Yes";
        }

        mpp[arr[i]] = i;
    }

    return "No";
}


string optimal_approach(vector<int> arr, int k){
    int size = arr.size();
    int sum = 0;
    int left = 0, right = size - 1;

    sort(arr.begin(), arr.end());
    while(left < right){
        sum = arr[left] + arr[right];

        if(sum == k){
            printf("The elements that sums up to %d are: %d and %d\n", k, arr[left], arr[right]);
            return "Yes";
        }
        else if(sum > k){
            right--;
        }
        else
            left++;
    }

    return "No";
}

int main(){
    vector<int> arr = {1, 6, 3, 8, 4};
    int k = 5;

    cout<<"Solution of 2Sum problem with Brute approach is: "<<endl;
    cout<<"-------------------------------------------------"<<endl;
    string res = brute_approach(arr, k);
    cout<<"-------------------------------------------------"<<endl;

    cout<<"Solution of 2Sum problem with Better approach is: "<<endl;
    cout<<"-------------------------------------------------"<<endl;
    res = better_approach(arr, k);
    cout<<"-------------------------------------------------"<<endl;

    cout<<"Solution of 2Sum problem with Optimal approach is: "<<endl;
    cout<<"-------------------------------------------------"<<endl;
    res = optimal_approach(arr, k);
    cout<<"-------------------------------------------------"<<endl;
    return 0;
}