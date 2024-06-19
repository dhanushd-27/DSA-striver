#include <bits/stdc++.h>
using namespace std;

void turnBy90Degree(vector<vector<int>>  &A, int n){

    // Transpose of the array
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            swap(A[i][j], A[j][i]);
        }
    }

    // Reverse Each row after transpose
    for(int i = 0; i < n; i++){
        reverse(A[i].begin(), A[i].end());
    }
}   

int main(){
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = A.size();

    cout<<"The Before Array:   \n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<< A[i][j]<< " ";
        }
        cout<<"\n";
    }

    turnBy90Degree(A, n);

    cout<<"The After Array:   \n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<< A[i][j]<< " ";
        }
        cout<<"\n";
    }
    return 0;
}