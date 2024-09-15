#include <bits/stdc++.h>
using namespace std;

int findPlatform(vector<int>& arr, vector<int>& dep) {
    int maxPlats = 0;
    int start = arr[0];
    int noOfTrains = arr.size();
    int end = arr[noOfTrains - 1];
    
    for(int i = start; i <= end; i++){
        int plats = 0;
        for(int j = 0; j < noOfTrains; j++){
            if(arr[j] <= i && dep[j] > i){
                plats++;
            }
        }
        maxPlats = max(maxPlats, plats);
    }
    
    return maxPlats;
}

int main(){
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    cout<< "The Minimum Number of Platforms required are: "<< findPlatform(arr, dep)<< endl;
    return 0;
}