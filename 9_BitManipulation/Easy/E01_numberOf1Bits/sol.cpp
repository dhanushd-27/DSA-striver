#include <bits/stdc++.h>
using namespace std;

// Leetcode 191

// check whether right most bit is 1 or not
// (n >> i) & 1 == 1

// unset the right most set bit of n
// n = (n & (n-1))

// TC - O(cnt)
// SC - O(1)

int hammingWeight(int n) {
    int cnt = 0;

    while(n != 0){
        // unset right most bit using this technique
        n = (n & (n-1));
        cnt++;
    }

    return cnt;
}