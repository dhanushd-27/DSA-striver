#include <bits/stdc++.h>
using namespace std;

// Leetcode - 792
// Number of Matching Subsequences

// TC -  O(s + n*logn)
// SC - O(s) for hashmap

bool isSubsequence(string currSubSeq, int subSeqSize, int prev, unordered_map<char, vector<int>> mp){
    for(int i = 0; i < subSeqSize; i++){
                    
        char ch = currSubSeq[i];

        if(mp.find(ch) == mp.end()) return false;

        // vector<int> indices = mp[ch];
        // the above sentence take the extra to copy all elements from mp[ch] to new vector
        auto it = upper_bound(mp[ch].begin(), mp[ch].end(), prev);

        if(it == mp[ch].end()) return false;

        prev = *it;

        if(i == subSeqSize - 1) return true;
    }
    return true;
}

int numMatchingSubseq(string s, vector<string>& words) {
    unordered_map<string, int> wordsFreq;
    int mainStringSize = s.size();

    unordered_map<char, vector<int>> mp;
    int cnt = 0;

    // add elements to the hash map
    for(int i = 0; i < mainStringSize; i++){
        mp[s[i]].push_back(i);
    }

    // loop the given array of words
    int arrSize = words.size();
    for(int i = 0; i < arrSize; i++){
        // intialize prev value for each new string
        string currSubSeq = words[i];
        int subSeqSize = currSubSeq.size();

        // don't run repeated elements just add them to cnt
        if(wordsFreq.find(words[i]) == wordsFreq.end()){
            // add only if they are a subsequence
            if(isSubsequence(currSubSeq, subSeqSize, -1, mp)){
                cnt++;
                wordsFreq[words[i]]++;
            } 
        }
        else{
            cnt++;
        }
    }

    return cnt;
}