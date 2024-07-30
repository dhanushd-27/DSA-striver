#include <bits/stdc++.h>
using namespace std;

int brute_approach(vector<int> arr, int k){
    int n = arr.size();
    int sum = 0;
    int max_len = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum += arr[j];

            if(sum == k){
                max_len = max(max_len, j - i + 1);
            }
        }
    }
    return max_len;
}


int better_approach(vector<int> arr, int k){
    map<int, int> hash;
    int n = arr.size();
    int max_len = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
        /* code */
        sum += arr[i];

        if(sum == k){
            max_len = max(max_len, i + 1);
        }

        int rem = sum - k;

        if(hash.find(rem) != hash.end()){
            int len = i - hash[rem];
            max_len = max(max_len, len);
        }

        if(hash.find(sum) == hash.end()){
            hash[sum] = i;
        }
    }
    return max_len;
}

int optimal_approach(vector<int> arr, int k){
    //* Two pointer method
    int n = arr.size();
    int left = 0, right = 0;
    int sum = arr[left], max_len = 0;

    while(right < n){
        while(sum > k && left <= right){
            sum-=arr[left];
            left++;
        }

        if(sum == k){
            max_len = max(max_len, right - left + 1);
        }
        right++;

        if(right < n) sum += arr[right];
    }
    return max_len;
} 


int main(){
    vector<int> a = {2, 3, 5, 1, 9};
    int k = 10;
    int len = brute_approach(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    len = better_approach(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";

    len = optimal_approach(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}