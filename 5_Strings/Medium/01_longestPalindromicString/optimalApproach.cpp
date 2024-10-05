#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2)
// SC: O(1)

string longestPalindrome(string s) {
    int maxSize = -1;
        string res = "";
        int len = s.size();

        // Longest Odd Palindromic SubString
        for(int mid = 0; mid < len; mid++){
            int curSize = 0;

            int i = mid - 1;
            int j = mid + 1;

            while(i >= 0 && j < len && s[i] == s[j]){
                i--;
                j++;
                curSize += 2;
            }

            if(curSize > maxSize){
                res = s.substr(i + 1, curSize + 1);
                maxSize = curSize;
            }
        }

        // Longest Even Palindromic SubString
        for(int mid = 0; mid < len; mid++){
            int curSize = 0;
            int i = mid;
            int j = mid + 1;

            while(i >= 0 && j < len && s[i] == s[j]){
                i--;
                j++;
                curSize += 2;
            }

            if(curSize > maxSize){
                res = s.substr(i + 1, curSize);
                maxSize = curSize;
            }
        }

        return res;

    return res;
}

int main(){
    string str = "babad";

    string res = longestPalindrome(str);

    cout<< "Longest Substring of given string "<< str<< " is "<< res<< endl;
}