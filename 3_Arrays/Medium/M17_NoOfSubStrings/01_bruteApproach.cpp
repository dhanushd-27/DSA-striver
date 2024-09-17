#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string str){
    int count = 0;
    int n = str.length();

    for(int i = 0; i < n; i++){
        bool statusA = false, statusB = false, statusC = false;
        string curSubStr;

        for(int j = i; j < n; j++){
            curSubStr += str[j];

            if(str[j] == 'a') {
                statusA = true;
            }
            if(str[j] == 'b') {
                statusB = true;
            }
            if(str[j] == 'c'){
                statusC = true;
            }

            if(statusA && statusB && statusC){
                count++;
            }
        }
    }

    return count;
}

int main(){
    string str = "abcabc";
    cout<< "Number of substrings containing all three character are: "<< numberOfSubstrings(str)<< endl;
    return 0;
}