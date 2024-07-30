#include <bits/stdc++.h>
using namespace std;

void brute_approach(vector<int> arr){
    int n = arr.size();
    vector<int> neg;
    vector<int> pos;

    for(int i = 0; i < n; i++){
        if(arr[i] > 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }

    for(int i = 0; i < pos.size(); i++){
        arr[i * 2] = pos[i];
        arr[i * 2 + 1] = neg[i];
    }

    cout<<"[ ";
    for(int i = 0; i < n; i++){
        cout<<arr[i] <<" ";
    }
    cout<<"]";

}

void optimal_approach(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n, 0);
    int posIndex = 0;
    int negIndex = 1;

    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
        else{
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
    }

    cout<< "[ ";
    for(int i = 0; i < n; i++){
        cout<< ans[i]<< " ";
    }
    cout<< "]";
}

int main(){
    vector<int> arr = {1, 3, 4, -2, -4, -5};
    vector<int> ans;

    brute_approach(arr);
    optimal_approach(arr);
    return 0;
}