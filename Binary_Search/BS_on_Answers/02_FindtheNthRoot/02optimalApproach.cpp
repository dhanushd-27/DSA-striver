#include <bits/stdc++.h>
using namespace std;

int findNthRoot(int n, int m){
    int low = 1, high = m;

    while(low <= high){
        int mid = (low + high) / 2;

        if(pow(mid, n) == m) return mid;

        if(pow(mid, n) > m) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
}

int main(){
    int n = 3, m = 27;
    int ans = findNthRoot(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
