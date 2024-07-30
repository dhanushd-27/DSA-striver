#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {1,1,4,2,2,5,9,3};
    // Brute force
    // TC: Nlog(N) * N
    set<int> unqele = {};
    for(int i: arr){
        unqele.insert(i);
    }

    auto index = 0;
    for(int i: unqele){
        index++;
    }
    cout<<index<<endl;
    // optimal approach
    int i = 0;
    for(int j = 1; j < arr.size(); j++){
        if(arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }

    cout<< "The number of unique elements are:  "<<i+1;
}