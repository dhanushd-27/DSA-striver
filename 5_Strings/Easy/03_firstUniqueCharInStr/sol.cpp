#include <bits/stdc++.h>
using namespace std;

// Leetcode 387 - first unique char in a string

int firstUniqChar(string s) {
    // TC - O(2n)
    // SC - O(n)

    int arr[26] = {0};

    int n = s.length();

    for(int i = 0; i < n; i++){
        char ch = s[i];
        arr[ch - 'a']++;
    }

    for(int i = 0; i < n; i++){
        char ch = s[i];
        if(arr[ch - 'a'] == 1) return i;
    }

    return -1;
}