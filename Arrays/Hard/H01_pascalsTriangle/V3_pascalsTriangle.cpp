#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int n){
    int ans = 1;
    vector<int> res;

    res.push_back(1);
    for(int i = 0; i < n; i++){
        ans = ans * (n - i);
        ans = ans / (i + 1);
        res.push_back(ans);
    }

    return res;
}

int main(){
    int n;
    vector<vector<int>> res;
    cout<< "Pascal's Triangle\n";
    cout<< "-----------------------------------\n\n";

    cout<< "Enter the row number: ";
    cin>> n;

    for(int i = 0; i < n; i++){
        res.push_back(generateRow(i));
    }
    cout<< "The elements are: "<<endl;


    for(int i = 0; i < n; i++){
        for(int j = 0; j < res[i].size(); j++){
            cout<< res[i][j]<< " ";
        }
        cout<< endl;
    }
}