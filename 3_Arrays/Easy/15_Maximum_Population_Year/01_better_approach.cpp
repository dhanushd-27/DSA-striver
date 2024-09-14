#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int, int>> logs = {{1991, 1997}, {1990, 1994}, {1993, 2000}};
    map<int, int> countPopulation;
    int maxCount = INT_MIN;
    int maxPopulationYear = 0;

    for(auto it: logs){
        int born = it.first;
        int death = it.second;

        for(int year = born; year < death; year++){
            countPopulation[year]++;
            
            if(maxCount < countPopulation[year]){
                maxCount = countPopulation[year];
                maxPopulationYear = year;
            }
        }
    }
    
    printf("Max population year is: %d\n", maxPopulationYear);
    return 0;
}