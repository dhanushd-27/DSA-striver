// In the optimal approach we will be using Lower Bound and Upper Bound
// In case the lower bound returns the value n or the value at lb is not equal to key return {-1, -1}

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

pair<int, int> firstAndLastOccurences(vector<int> a, int key){
    int n = a.size();
    int firstOcc = lowerBound(a, key);
    int lastOcc = upperBound(a, key) - 1;

    if((firstOcc == n) || a[firstOcc] != key){
        return make_pair(-1, -1);
    }
    return make_pair(firstOcc, lastOcc);
}

int main() {
    int key = 13, key2 = 12;
    vector < int > v = {3,4,13,13,13,20,40};

    // Case 1
    // returning the first and last occurrence index if the element is present otherwise -1, -1
    pair<int, int> ans = firstAndLastOccurences(v, key);
    cout << "First Occurence: "<< ans.first<< " and Last Occurence: "<< ans.second<< endl;


    // Case 1
    // returning the first and last occurrence index if the element is present otherwise -1, -1
    ans = firstAndLastOccurences(v, key2);
    cout << "First Occurence: "<< ans.first<< " and Last Occurence: "<< ans.second<< endl;
    return 0;
}