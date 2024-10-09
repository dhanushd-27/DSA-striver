#include <bits/stdc++.h>
using namespace std;

// Leetcode: 885
vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    vector<vector<int>> res;

    vector<vector<int>> dir = {
        // East
        {0, 1},
        //South
        {1, 0},
        // West
        {0, -1},
        // North
        {-1, 0}
    };

    int steps = 0;
    int pos = 0;
    int totalEles = rows * cols;

    res.push_back({rStart, cStart});
    
    while(res.size() != totalEles){
        if(pos == 0 || pos == 2){
            steps++;
        }

        for(int i = 0; i < steps; i++){
            rStart += dir[pos][0];
            cStart += dir[pos][1];

            if(rStart >= 0 && cStart >= 0 && rStart < rows && cStart < cols){
                res.push_back({rStart, cStart});
            }
        }

        pos = (pos + 1) % 4;
    }

    return res;
}