#include <bits/stdc++.h>
using namespace std;

int median(vector<int> a,vector<int> b){
    int m = a.size();
    int n = b.size();

    vector<int> arr3;
    int i = 0, j = 0;

    while(i < m && j < n){
        if(a[i] < b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
    }

    while (i < m) arr3.push_back(a[i++]);
    while (j < n) arr3.push_back(b[j++]);

    int k = m + n;

    if(k % 2 == 1) return arr3[k/2];
    else{
        int median = ((double)arr3[k/2] + (double)arr3[(k/2) - 1]) / 2;
        return median;
    }

    return -1;
}

int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << median(a, b) << '\n';
}
