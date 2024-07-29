#include <bits/stdc++.h>
using namespace std;

int countDigits(int n){
    int cnt = (int)(log10(n) + 1);

    return cnt;
}

int main(){
    int n;
    cout<< "Enter a number: ";
    cin>> n;
    int digits = countDigits(n);
    cout<< "The number of digits are: "<< digits<< endl;
}