#include <bits/stdc++.h>
using namespace std;

int maxScore(string s) {
    int j = 1;
    int size = s.size();
    int maxSum = INT_MIN;

    while(j < size){
        string subStr1 = s.substr(0, j);
        string subStr2 = s.substr(j);

        int sum = count(subStr1.begin(), subStr1.end(), '0') + count(subStr2.begin(), subStr2.end(), '1');
        maxSum = max(sum, maxSum);
        j++;
    }

    return maxSum;
}