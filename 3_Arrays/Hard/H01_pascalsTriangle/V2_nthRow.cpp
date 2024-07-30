#include <bits/stdc++.h>
using namespace std;

vector<int> nCr(int n){
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
    vector<int> res;
    cout<< "Pascal's Triangle\n";
    cout<< "-----------------------------------\n\n";

    cout<< "Enter the row number: ";
    cin>> n;

    res = nCr(n-1);
    cout<< "The elements are: ";

    for(int i = 0; i < res.size(); i++){
        cout<< res[i]<< " ";
    }
}