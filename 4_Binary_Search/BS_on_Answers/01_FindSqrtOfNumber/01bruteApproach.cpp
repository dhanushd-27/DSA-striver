#include <bits/stdc++.h>
using namespace std;

int findSQRT(int n){
    int ans;
    for(int i = 1; i < n; i++){
        if(i * i <= n){
            ans = i;
        }
        else{
            break;
        }
    }

    return ans;
}

int main(){
    int n = 26;
    int sqrt = findSQRT(n);
    cout<< "The Sqrt of number "<< sqrt<< endl;
    return 0;
}