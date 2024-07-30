#include <bits/stdc++.h>
using namespace std;

//* Brute Approach
bool linearSearch(vector<int> arr, int num){
    int n = arr.size();

    for(int i = 0; i < n; i++){
        if(num == arr[i]) return true;
    }

    return false;
}

int bruteApproach(vector<int> arr){
    int n = arr.size();
    int maxLen = 1;

    for(int i = 0; i < n; i++){
        int len = 1;
        int x = arr[i] + 1;

        while(linearSearch(arr, x)){
            x += 1;
            len += 1;
        }

        maxLen = max(len, maxLen);
    }

    return maxLen;
}

int betterApproachByMe(vector<int> arr){
    int n = arr.size();
    int longest = INT_MIN;
    int cnt = 1;
    int lastEle = arr[0];

    //Sort the array before in this approach
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++){
        if(arr[i] == lastEle + 1){
            cnt++;
            lastEle = arr[i];
        }
        else if(arr[i] == lastEle) continue;
        else{
            longest = max(cnt, longest);
            cnt = 1;
            lastEle = arr[i];
        }
    }

    return longest;
}

int striverBetterApproach(vector<int> a){
    int n = a.size();
    if (n == 0) return 0;

    //sort the array:
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    //find longest sequence:
    for (int i = 0; i < n; i++) {
        if (a[i] - 1 == lastSmaller) {
            //a[i] is the next element of the
            //current sequence.
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}

int optimalApproach(vector<int> arr){
    int n = arr.size();

    if(n == 0) return 0;

    unordered_set<int> st;
    int longest = 1;

    for(int i = 0; i < n; i++){
        st.insert(arr[i]);
    }

    for(auto it: st){
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }

    return longest;
}

int main(){
    vector<int> arr = {101, 100, 2, 104, 1, 4, 5, 102, 3, 1, 3};
    int maxLen = bruteApproach(arr);
    cout<<"The Longest Consecutive sequence is of length:   "<<maxLen<<"\n\n";
    int betterMaxLen = betterApproachByMe(arr);
    cout<<"The Longest Consecutive sequence is of length:   "<<betterMaxLen;
    int striverMaxLen = striverBetterApproach(arr);
    cout<<"\n\nThe Longest Consecutive sequence is of length:   "<<betterMaxLen;
    int optimalMaxLen = optimalApproach(arr);
    cout<<"\n\nThe Longest Consecutive sequence is of length:   "<<optimalMaxLen;

    return 0;
}