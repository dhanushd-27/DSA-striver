#include <bits/stdc++.h>
using namespace std;

// TC: O(N^3) N*N*N, last N is for palindrome check
// SC: O(1)

bool isPalindrome(string s){
    int i = 0, j = s.size() - 1;

    while(i < j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }

    return true;
}

string longestPalindrome(string s) {
    string res;

    for(int i = 0; i < s.size(); i++){
        string subStr = "";
        for(int j = i; j < s.size(); j++){
            subStr += s[j];

            if(isPalindrome(subStr) && subStr.size() > res.size()){
                res = subStr;
            }
        }
    }

    return res;
}

int main(){
    string str = "babad";

    string res = longestPalindrome(str);

    cout<< "Longest Substring of given string "<< str<< " is "<< res<< endl;
}