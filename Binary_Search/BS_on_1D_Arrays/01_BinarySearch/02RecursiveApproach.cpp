#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> a, int low, int high, int target){
    if(low > high) return -1;

    int mid = (low + high)/2;

    if(a[mid] == target) return mid;
    else if(a[mid] < target) return binarySearch(a, mid+1, high, target);

    return binarySearch(a, low, mid-1, target);
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int low = 0;
    int high = a.size() - 1;
    int ind = binarySearch(a, low, high, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    return 0;
}