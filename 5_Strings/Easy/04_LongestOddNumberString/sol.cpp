#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {
    // Learning - integer char - '0' will return the actual integer itself;
    // '7' - '0' = 7

    int size = num.size();

    for(int i = size-1; i >= 0; i--){
        if((num[i] - '0') % 2 == 1){
            return num.substr(0, i+1);
        }
    }

    return "";
}