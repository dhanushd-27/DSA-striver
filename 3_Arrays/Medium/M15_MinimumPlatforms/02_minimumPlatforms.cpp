#include <bits/stdc++.h>
using namespace std;

int findPlatform(vector<int> arr, vector<int> dep){
    int n = arr.size();
    int start = *min_element(arr.begin(), arr.begin());
    int end = *max_element(dep.begin(), dep.end());
    vector<int> trackIt(end+5, 0);

    for(int i = 0; i < n; i++){
        trackIt[arr[i]]++;
        trackIt[dep[i]+1]--;
    }

    int plats = 0;
    int maxPlats = 0;

    for(int i = 0; i < trackIt.size(); i++){
        plats += trackIt[i];
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