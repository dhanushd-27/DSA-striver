#include <bits/stdc++.h>
using namespace std;

// max occuring character gfg

//Function to find the maximum occurring character in a string.
char getMaxOccuringChar(string str)
{
    // Your code here
    unordered_map<char, int> hash;
    int len = str.size();
    int maxOcc = INT_MIN;
    char res = 'a';
    
    for(int i = 0; i < len; i++){
        hash[str[i]]++;
        
        if(hash[str[i]] > maxOcc){
            res = str[i];
            maxOcc = hash[str[i]];
        }
        
        if(hash[str[i]] == maxOcc && str[i] < res){
            res = str[i];
        }
    }
    
    return res;
}

int main(){
    string str = "testsample";

    cout<< getMaxOccuringChar(str)<< endl;
    return 0;
}