//Leetcode - 49
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> hashMap;

    for(string str: strs){
        vector<int> freq(26, 0);
        string hashString = "";

        for(char ch: str) freq[ch - 'a']++;

        for(int i = 0; i < 26; i++){
            hashString.push_back(freq[i]);
            hashString.push_back('#');
        }

        hashMap[hashString].push_back(str);
    }

    vector<vector<string>> res;
    for(auto it: hashMap){
        res.push_back(it.second);
    }

    return res;
}

