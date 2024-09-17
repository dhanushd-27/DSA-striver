#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string str){
    int count = 0;
    int n = str.length();

    for(int i = 0; i < n; i++){
        int hash[3] = {0};
        for(int j = i; j < n; j++){
            hash[str[j] - 'a'] = 1;
            if(hash[0] + hash[1] + hash[2] == 3){
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