#include <bits/stdc++.h>
using namespace std;

int sumByD(vector<int> a, int n, int divisor){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += ceil(double (a[i])/ divisor);
        
    }
    
    return sum;
}

int findSmallestDivisor(vector<int> arr, int n, int threshold){
    int low = 1, high = *max_element(arr.begin(), arr.end());
    int ans = 0;
    while(low <= high){
        int mid = (low + high) / 2;
        if(sumByD(arr, n, mid) <= threshold){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

int main(){
    vector<int> a = {1, 2, 3, 4, 5};
    int threshold = 8;
    int n = a.size();

    int divisor = findSmallestDivisor(a, n, threshold);
    cout<< "The smallest Divisor for the given array is: "<< divisor <<endl;
}