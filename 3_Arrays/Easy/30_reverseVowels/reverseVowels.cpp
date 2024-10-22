// Leetcode - 345

// Reverse vowels of a string

#include <bits/stdc++.h>
using namespace std;

// Find given character is a vowel or not
bool isVowel(char c){
    c = (char)tolower(c);
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u'){
        return true;
    }

    return false;
}

// Reverse Vowels
string reverseVowels(string s) {
    int n = s.length();
    int i = 0;
    int j = n - 1;

    while(i < j){

        // If s[i] is not a vowel move forward
        if(!isVowel(s[i])){
            i++;
        }

        // If s[j] is not a vowel reduce j value
        else if(!isVowel(s[j])){
            j--;
        }

        //swap both position
        else{
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    return s;
}