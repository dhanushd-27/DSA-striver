#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> a){
    int n = a.size();

    if(a[0] > a[1]) return a[0];
    if(a[n-1] > a[n-2]) return a[n-1];

    for(int i = 1; i <= n-2; i++){
        if(a[i-1] < a[i] && a[i] > a[i+1]) return a[i];
    }

    return -1;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 1};
    int ind = findPeakElement(arr);
    cout<< "The index of the peak element is: "<< ind<< endl;
    return 0;
}