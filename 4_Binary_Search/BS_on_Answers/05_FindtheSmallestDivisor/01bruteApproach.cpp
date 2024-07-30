#include <bits/stdc++.h>
using namespace std;

int findSmallestDivisor(vector<int> a, int n, int threshold){
    int maxele = *max_element(a.begin(), a.end());
    for(int i = 1; i <= maxele; i++){
        int d = i;
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += ceil((double) a[j]/ (double) d);
        }

        if(sum <= threshold) return d;
    }
    return -1;
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5};
    int threshold = 8;
    int n = a.size();

    int divisor = findSmallestDivisor(a, n, threshold);
    cout<< "The smallest Divisor for the given array is: "<< divisor <<endl;
}