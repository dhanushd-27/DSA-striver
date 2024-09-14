// The approach is same the size but we are trying to use a hash function instead of a map
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int, int>> logs = {{1991, 1997}, {1990, 1994}, {1993, 2000}};
    int maxCount = INT_MIN;
    int maxPopulationYear = 0;
    vector<int> count(101, 0);

    for(auto it : logs){
        count[it.first - 1950]++;
        count[it.second - 1950]--;
    }
    
    for(int i = 1; i < 101; i++){
        count[i] += count[i-1];
        if(count[i] > maxCount){
            maxCount = count[i];
            maxPopulationYear = 1950 + i;
        }
    }

    printf("Max population year is: %d\n", maxPopulationYear);
    return 0;
}