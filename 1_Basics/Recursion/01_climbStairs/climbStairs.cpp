#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> cache;

int climbStairs(int n) {
    if(n == 0 || n == 1) return 1;

    if(cache[n] != 0) return cache[n];

    cache[n] = climbStairs(n-1) + climbStairs(n-2);
    return climbStairs(n-1) + climbStairs(n-2);
}

int main(){
    int stairs = 4;
    cout<< "There are "<< climbStairs(stairs)<< " ways to climb to the top";
    return 0;
}