// find the sqrt of a number using Binary Search

#include <bits/stdc++.h>
using namespace std;

int findSQRT(int n){
    int low = 1, high = n - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        int val = mid * mid;

        if(val <= n){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return high;
}

int main(){
    int n = 26;
    int sqrt = findSQRT(n);
    cout<< "The Sqrt of number "<< sqrt<< endl;
    return 0;
}