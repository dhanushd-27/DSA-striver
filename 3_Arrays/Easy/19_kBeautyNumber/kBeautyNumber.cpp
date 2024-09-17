#include <bits/stdc++.h>
using namespace std;

// Leetcode - 2269. Find the K-Beauty of a Number

int divisorSubStrings(int num, int k){
    string str = to_string(num);
    int n = str.length();
    int count = 0;
    string curSubStr;

    for(int i = 0; i < k; i++) curSubStr += str[i];
    
    if(num % stoi(curSubStr) == 0){
            count++;
    }

    for(int i = k; i < n; i++){
        // in operation
        curSubStr += str[i];
        
        // out operation
        curSubStr = curSubStr.erase(0, 1);

        if(stoi(curSubStr) == 0) continue;

        if(num % stoi(curSubStr) == 0){
            count++;
        }
    }

    return count;
}

int main(){
    int num = 240;
    int k = 2;
    cout<< "K-Beauty number for "<< num<< " is: "<< divisorSubStrings(num, k)<< endl;
    return 0;
}