#include <bits/stdc++.h>
using namespace std;

int countSubstrings(string s) {
    int size = s.size();
    int cnt = 0;

    // Odd Palindrome's
    for(int mid = 0; mid < size; mid ++){
        int i = mid - 1;
        int j = mid + 1;

        while(i >= 0 && j < size && s[i] == s[j]){
            i--;
            j++;
            cnt += 1;
        }
    }

    // Even Palindrome's
    for(int mid = 0; mid < size; mid ++){
        int i = mid;
        int j = mid + 1;

        while(i >= 0 && j < size && s[i] == s[j]){
            i--;
            j++;
            cnt += 1;
        }
    }

    return cnt + size;
}

int main(){
    string s = "abcbxbcdobbod";
    
    int res = countSubstrings(s);
    cout<< "Number of Palindromic Substrings are: "<< res<< endl;
}