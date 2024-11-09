#include <bits/stdc++.h>
using namespace std;

// Leetcode - 3
// Longest Substring without repeating characters

int lengthOfLongestSubstring(string s){
    int size = s.size();

    int maxLen;
    // Sliding Window points
    int i = 0, j = 0;
    // Unordered Set to store unique elements
    unordered_set<char> hash;


    while(j < size){

        // If the element doesn't exist increase the window size by 1
        if(hash.find(s[i]) == hash.end()){
            hash.insert(s[i]);
            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        //If not reduce the window size by 1
        else{
            // remove that element from the hash
            hash.erase(s[i]);
            i++;
        }
    }

    return maxLen;
}