#include <bits/stdc++.h>
using namespace std;

void setMatrixZero(vector<vector<int>> &A, int n, int m){
    int col0 = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == 0){
                A[i][0] = 0;

                if(j != 0) A[0][j] = 0;
                else col0 = 0;
            }
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(A[i][j] != 0){
                if(A[i][0] == 0 || A[0][j] == 0){
                    A[i][j] = 0;
                }
            }
        }
    }

    if(A[0][0] == 0){
        for(int j = 0; j < m; j++) A[0][j] = 0;
    }
    if(col0 == 0){
        for(int i = 0; i < n; i++) A[i][0] = 0;
    }
}

int main(){
    vector<vector<int>> A = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = A.size();
    int m = A[0].size();

    cout<<"The Matrix before change:    \n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<< A[i][j]<< "  ";
        }
        cout<<"\n";
    }

    setMatrixZero(A, n, m);

    cout<<"The Matrix After change:    \n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<< A[i][j]<< "  ";
        }
        cout<<"\n";
    }
    return 0;
}