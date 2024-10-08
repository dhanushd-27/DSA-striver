#include <bits/stdc++.h>
using namespace std;

// Leetcode 59: Spiral Matrix 2

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));

    int max = n * n;
    int cnt = 1;
    int left = 0, right = n - 1;
    int up = 0, down = n - 1;

    while(left <= right){

        // Push Elements from left to right
        for(int i = left; i <= right; i ++){
            res[up][i] = cnt ++;
        }
        up ++;

        // Push Element from up to down
        for(int j = up; j <= down; j ++){
            res[j][right] = cnt ++;
        }
        right --;

        // Push Element from right to left
        if(up <= down){
            for(int k = right; k >= left; k --){
                res[down][k] = cnt ++;
            }
        }
        down --;

        // Push Element from down to up
        if(left <= right){
            for(int l = down; l >= up; l --){
                res[l][left] = cnt ++;
            }
        }
        left ++;
    }

    return res;
}

int main(){
    vector<vector<int>> res;
    int n = 7;
    res = generateMatrix(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<< res[i][j]<< " ";
        }
        cout<< endl;
    }
}