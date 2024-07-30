#include <bits/stdc++.h>
using namespace std;

int max_cont_ones(vector<int> arr, int arr_size){
    int maxo= 0;
    int cnt = 0;

    for(int i = 0; i < arr_size; i++){
        if(arr[i] == 1){
            cnt++;
        }
        else{
            maxo = max(maxo, cnt);
            cnt = 0;
        }
    }

    return maxo;
}

int main(){
    vector<int> arr = {1, 1, 0, 1, 1, 1, 0, 1, 1};

    int max1 = max_cont_ones(arr, arr.size());
    cout<< "Maximum consecutive one's are:  "<< max1;
}