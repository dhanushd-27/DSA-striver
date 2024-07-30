#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &a, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int cnt = 0;
    while(left <= mid && right <= high){
        if(a[left] <= a[right]){
            temp.push_back(a[left++]);
        }
        else{
            temp.push_back(a[right]);
            cnt+= (mid - left) + 1;
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(a[left++]);
    }
    while(right <= high){
        temp.push_back(a[right++]);
    }

    for(int i = low; i <= high; i++){
        a[i] = temp[i - low];
    }

    return cnt;
}

int mergesort(vector<int> &a, int low, int high){
    int cnt = 0;
    if(low >= high) return cnt;

    int mid = (low + high) / 2;
    cnt += mergesort(a, low, mid);
    cnt += mergesort(a, mid+1, high);
    cnt += merge(a, low, mid, high);
    return cnt;
}

int numberOfInversions(vector<int>&a, int n){
    return mergesort(a, 0, n-1);
}

int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions are: "
         << cnt << endl;
    return 0;
}