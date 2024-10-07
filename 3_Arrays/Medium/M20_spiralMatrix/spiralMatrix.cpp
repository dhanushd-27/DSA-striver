#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> res;

    int left = 0, right = cols - 1;
    int up = 0, down = rows - 1;

    while(left <= right && up <= down){

        //Move left to right (lr)
        for(int i = left; i <= right; i++){
            res.push_back(matrix[up][i]);
        }
        up++;

        for(int j = up; j <= down; j++){
            res.push_back(matrix[j][right]);
        }

        right--;

        if(up <= down){
            for(int k = right; k >= left; k--){
                res.push_back(matrix[down][k]);
            }
        }
        
        down--;

        if(left <= right){
            for(int l = down; l >= up; l--){
                res.push_back(matrix[l][left]);
            }
        }
        left++;
    }

    return res;
}

int main(){
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    vector<int> res = spiralOrder(matrix);

    cout<< "The Spiral Order is ";
    for(int it: res){
        cout<< it<< " ";
    }

    return 0;
}