#include <bits/stdc++.h>
using namespace std;

// TC - O(n)
// SC - O(1)

// Leetcode - 392 - isSubsequence

bool isSubsequence(string s, string t) {
    int sPtr = 0;

    int sSize = s.size();
    int tSize = t.size();

    for(int i = 0; i < tSize; i++){
        if(t[i] == s[sPtr]){
            sPtr++;
        }
    }

    return sSize == sPtr;
}