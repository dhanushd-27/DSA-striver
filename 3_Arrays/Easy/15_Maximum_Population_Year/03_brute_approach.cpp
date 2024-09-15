#include <bits/stdc++.h>
using namespace std;

int maxPopulationYear(vector<pair<int, int>> logs){
    int maxCount = 0;
    int maxPopulationYear = 0;

    for(int i = 1950; i <= 2050; i++){
        int count = 0;
        for(auto log: logs){
            if(log.first <= i && i < log.second){
                count++;
            }
        }

        if(count > maxCount){
            maxCount = count;
            maxPopulationYear = i;
        }
    }

    return maxPopulationYear;
}

int main(){
    vector<pair<int, int>> logs = {{1991, 1997}, {1990, 1994}, {1993, 2000}};
    cout<< "The Maximum Population Year is: "<< maxPopulationYear(logs)<< endl;
    return 0;
}