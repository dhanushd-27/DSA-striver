#include <bits/stdc++.h>
using namespace std;

// Find Floor and ceil of x in a sorted array
int findFloor(int a[], int n, int x){
    int low = 0, high = n - 1;
    int ans = -1;

    while(low <= high){
        int mid = (low + high)/2;

        if(a[mid] <= x){
            ans = a[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return ans;
}

int findCeil(int a[], int n, int x){
    int low = 0, high = n - 1;
    int ans = -1;

    while(low <= high){
        int mid = (low + high)/2;

        if(a[mid] >= x){
            ans = a[mid];
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

pair<int, int> getFloorAndCeil(int a[], int n, int x){
    int floor = findFloor(a, n, x);
    int ceil = findCeil(a, n, x);
    return make_pair(floor, ceil);
}

int main() {
	int arr[] = {3, 4, 4, 7, 8, 10};
	int n = 6, x = 5;
	pair<int, int> ans = getFloorAndCeil(arr, n, x);
	cout << "The floor and ceil are: " << ans.first
	     << " " << ans.second << endl;
	return 0;
}