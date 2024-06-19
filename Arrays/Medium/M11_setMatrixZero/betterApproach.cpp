#include <bits/stdc++.h>
using namespace std;

void setMatrixZero(vector<vector<int>> &A, int n, int m){
    int row[n] = {0};
    int col[m] = {0};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == 0) 
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(row[i] || col[j]) A[i][j] = 0;
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

    setMatrixZero(A, n, m);

    cout << "The After matrix is: \n";
    for (auto it : A) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }

    return 0;
}