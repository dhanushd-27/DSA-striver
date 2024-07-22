#include <bits/stdc++.h>
using namespace std;

int findNthRoot(int n, int m){
    for(int i = 0; i < m; i++){
        if(pow(i, n) == m) return i;
        else if(pow(i, n) > m) break;
    }
    return -1;
}

int main(){
    int n = 3, m = 27;
    int ans = findNthRoot(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}