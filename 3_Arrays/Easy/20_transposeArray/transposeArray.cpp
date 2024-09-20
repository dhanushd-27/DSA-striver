#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& twoDArray) {
    int rows = twoDArray.size();
    int cols = twoDArray[0].size();
    vector<vector<int>> output(cols, vector<int>(rows));

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            output[j][i] = twoDArray[i][j];
        }
    }

    return output;
}

int main(){
    vector<vector<int>> twoDArray = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = twoDArray.size();
    int cols = twoDArray[0].size();

    cout<< "Given 2D array has "<< rows<< " rows and "<< cols<< " columns."<< endl;

    cout<< endl<< endl<< "Before Transpose: "<< endl;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout<< twoDArray[i][j]<< " ";
        }
        cout<< endl;
    }

    vector<vector<int>> output = transpose(twoDArray);

    cout<< endl<< endl<< "After Transpose: "<< endl;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout<< output[i][j]<< " ";
        }
        cout<< endl;
    }
    return 0;
}