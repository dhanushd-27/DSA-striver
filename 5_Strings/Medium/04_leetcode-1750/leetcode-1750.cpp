// Leetcode 1750
// Minimum Length of String After Deleting Similar Ends

// TC: O(n)
// SC: O(1)

// Lessons: Missed few edge cases like
// what if i == j
// what if all characters are same 'aaaaaa'

#include <bits/stdc++.h>
using namespace std;

int minimumLength(string s) {
    int n = s.length();

    // Intialize two pointers
    int i = 0, j = n - 1;

    // Read point 3 - i should be always less than j
    // Loop breaks if i gets ahead of j, i.e all prefix and suffix have been deleted
    // remove prefix and suffix if they are the same
    while(i < j && s[i] == s[j]){
        char ch = s[i];

            // prefix should be a set of same character, either 'a', 'b' or 'c'
            while(s[i] == ch && i < j) i++;

            // suffix should be a set of same character, either 'a', 'b' or 'c'
            // j >= i i.e j should cross i if (i == j)
            while(s[j] == ch && j >= i) j--;
    }
    // tried and tested
    return j - i + 1;
}