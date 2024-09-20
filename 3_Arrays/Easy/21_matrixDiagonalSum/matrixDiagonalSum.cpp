#include <bits/stdc++.h>
using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
    int primarySum = 0;
    int secondarySum = 0;
    int n = mat.size();

    for(int i = 0; i < n; i++){
        primarySum += mat[i][i];

        if(i != n-1-i){
            secondarySum += mat[i][n-1-i];
        }
    }

    return primarySum + secondarySum;
}

int main(){
    vector<vector<int>> twoDArray = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout<< "Sum of the Diagonal elements is: "<< diagonalSum(twoDArray)<< endl;
    return 0;
}