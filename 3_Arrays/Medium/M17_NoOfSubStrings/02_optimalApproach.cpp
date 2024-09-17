#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string str){
    int count = 0;
    int hash[3] = {-1, -1, -1};
    int n = str.length();

    for(int i = 0; i < n; i++){
        hash[str[i] - 'a'] = i;

        if(hash[0] != -1 && hash[1] != -1 && hash[2] != -1){
            count += (1 + min(hash[0], min(hash[1], hash[2])));
        }
    }

    return count;
}

int main(){
    string str = "abcabc";
    cout<< "Number of substrings containing all three character are: "<< numberOfSubstrings(str)<< endl;
    return 0;
}