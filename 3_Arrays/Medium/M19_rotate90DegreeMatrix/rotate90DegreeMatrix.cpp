// Leetcode 48

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

#include <bits/stdc++.h>
using namespace std;

void transposeMatrix(vector<vector<int>>& matrix){
    int rows = matrix.size();
    int cols = rows;

    for(int i = 0; i < rows; i++){
        for(int j = i + 1; j < cols; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void rotate(vector<vector<int>>& matrix){
    transposeMatrix(matrix);
    int rows = matrix.size();
    for(int i = 0; i < rows; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main(){
    vector<vector<int>> matrix = { {1, 2, 3},  {4, 5, 6}, {7, 8, 9}};
    int rows = matrix.size();
    int cols = rows;

    cout<< "Before Rotate "<< endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout<< matrix[i][j]<< " ";
        }
        cout<< endl;
    }

    rotate(matrix);

    cout<< "After Rotate "<< endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout<< matrix[i][j]<< " ";
        }
        cout<< endl;
    }
}