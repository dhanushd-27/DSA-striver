#include<bits/stdc++.h>
using namespace std;

void turnBy90Degree(vector<vector<int>> &A, int n){
    vector<vector<int>> ans(n, vector<int> (n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans[j][n - 1 - i] = A[i][j];
        }
    }

    //Print the output Array
    cout<<"The rotated array is:    \n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<< ans[i][j]<< " ";
        }
        cout<< "\n";
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
    return 0;
}