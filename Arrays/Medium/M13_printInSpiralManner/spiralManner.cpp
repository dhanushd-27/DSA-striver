#include <bits/stdc++.h>
using namespace std;

void sprialManner(vector<vector<int>> A, int n, int m){

    int top = 0, left = 0;
    int right = m - 1, bottom = n - 1;

    while(top <= bottom && left <= right){
        for(int i = left; i <= right; i++){
            cout<< A[top][i]<< " ";
        }
        top++;

        for(int i = top; i <= bottom; i++){
            cout<< A[i][right]<< " ";
        }

        right--;

        for(int i = right; i >= left; i--){
            cout<< A[bottom][i]<< " ";
        }

        bottom--;

        for(int i = bottom; i >= top; i--){
            cout<< A[i][left]<< " ";
        }

        left++;
    }

}

int main(){
    vector<vector<int>> A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> B = {{1, 2, 3, 4},
    {5, 6, 7, 8}, 
    {9, 10, 11, 12}, 
    {13, 14, 15, 16}, 
    {17, 18, 19, 20}};

    sprialManner(A, A.size(), A[0].size());
    cout<<"\n\n";
    sprialManner(B, B.size(), B[0].size());
    return 0;
}