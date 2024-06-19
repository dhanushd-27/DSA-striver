// *Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

#include <bits/stdc++.h>
using namespace std;

void setRow(vector<vector<int>> &A, int m, int i){
    for(int j = 0; j < m; j++){
        if(A[i][j] != 0) A[i][j] = -1;
    }
}

void setCol(vector<vector<int>> &A, int n, int j){
    for (int i = 0; i < n; i++) {
        if (A[i][j] != 0) {
            A[i][j] = -1;
        }
    }
}

void bruteApproach(vector<vector<int>> &A, int n, int m){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(A[i][j] == 0){
                setRow(A, m, i);
                setCol(A, n, j);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == -1) A[i][j] = 0;
        }
    }
}

int main(){
    vector<vector<int>> A = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = A.size();
    int m = A[0].size();

    cout << "The Before matrix is: \n";
    for (auto it : A) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }

    bruteApproach(A, n, m);

    cout << "\nThe Final matrix is: \n";
    for (auto it : A) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}