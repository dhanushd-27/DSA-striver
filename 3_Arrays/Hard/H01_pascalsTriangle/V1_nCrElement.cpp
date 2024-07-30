#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r){
    int res = 1;

    for(int i = 0; i < r; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }

    return res;
}

int main(){
    int n, r, res;
    cout<< "Pascal's Ele\n";
    cout<< "-----------------------------------\n\n";

    cout<< "Enter the row number: ";
    cin>> n;
    cout<< "Enter the column number: ";
    cin>> r;

    res = nCr(n-1, r-1);
    cout<< "The element is: "<< res;
}