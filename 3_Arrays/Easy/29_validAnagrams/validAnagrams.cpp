#include <bits/stdc++.h>
using namespace std;

// leetcode - 242
// Solve using hashmap or sorting
bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;

    int n = s.size(); // both strings are of same size

    unordered_map<char, int> hash;

    // Increment for each occurence of a character
    for(int i = 0; i < n; i++){
        hash[s[i]]++;
    }

    // Decremenet for each occurence of a character
    for(int j = 0; j < n; j++){
        hash[t[j]]--;
    }

    // If both are anagrams all the values in hash has to be 0
    for(auto it: hash){
        if(it.second != 0) return false;
    }

    return true;
}

int main(){
    string s = "nagaram";
    string t = "anagram";

    if(isAnagram(s, t)){
        printf("Given strings %s and %s are Anagrams\n", s.c_str(), t.c_str());
    }
    else{
        printf("Given strings %s and %s are not Anagrams\n", s.c_str(), t.c_str());
    }

    string s1 = "tigebnorpqwsdfghjklmnbvcxzabcdefg";
    string t1 = "ghjklmnbvcxzabcdefgtigebnorpqwds";

    if(isAnagram(s1, t1)){
        printf("Given strings %s and %s are Anagrams\n", s1.c_str(), t1.c_str());
    }
    else{
        printf("Given strings %s and %s are not Anagrams\n", s1.c_str(), t1.c_str());
    }
}