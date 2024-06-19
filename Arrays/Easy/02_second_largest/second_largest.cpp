#include <bits/stdc++.h>
using namespace std;

int brute_approach(vector<int> arr){
    sort(arr.begin(), arr.end());
    cout<<"Using brute approach:    "<<endl;
    cout<<"The second largest element is:   "<< *(arr.end() - 2)<< endl;
}

int better_approach(vector<int> arr){
    int sec_max = -1, max = arr[0];

    for(int i : arr){
        if(max < i){
            max = i;
        }
    }

    for(int i : arr){
        if(i > sec_max && i < max){
            sec_max = i;
        }
    }
    cout<<"Using better approach:    "<<endl;
    cout<<"Second largest value is: "<<sec_max<<endl;
}

int optimal_approach(vector<int> arr){
    int max = arr[0];
    int sec_max = -1;

    for(int i: arr){
        if(i > max){
            sec_max = max;
            max = i;
        }
        else if(i < max && sec_max < i){
            sec_max = i;
        }
    }
    cout<<"Using optimal approach:    "<<endl;
    cout<<"Second largest value is: "<<sec_max;
}
int main(){
    vector<int> arr = {40, 20, 54, 89, 69};
    brute_approach(arr);
    better_approach(arr);
    optimal_approach(arr);
    return 0;
}