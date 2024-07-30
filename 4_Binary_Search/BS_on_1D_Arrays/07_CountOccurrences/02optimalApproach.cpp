#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> a, int key){
    int n = a.size();
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high){
        int mid = (low + high) / 2;

        if(a[mid] >= key){
            ans = mid;
            high = mid - 1;
        }

        else{
            low = mid + 1;
        }
    }

    return ans;
}

int upperBound(vector<int> a, int key){
    int n = a.size();
    int low = 0, high = n - 1;
    int ans = n;

    while(low <= high){
        int mid = (low + high) / 2;

        if(a[mid] > key){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

int firstAndLastOccurences(vector<int> a, int key){
    int n = a.size();
    int firstOcc = lowerBound(a, key);
    int lastOcc = upperBound(a, key) - 1;

    if((firstOcc == n) || a[firstOcc] != key){
        return 0;
    }
    return lastOcc - firstOcc + 1;
}

int main() {
    int key = 13, key2 = 12;
    vector < int > v = {3,4,13,13,13,20,40};

    // Case 1
    //Key value is present in given array
    int ans = firstAndLastOccurences(v, key);
    cout << "The number of occurences is: " <<ans<< endl;


    // Case 1
    //Key element is not present in given array
    ans = firstAndLastOccurences(v, key2);
    cout << "The number of occurences is: "<< ans<< endl;
    return 0;
}