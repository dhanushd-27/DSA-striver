// *Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

#include <bits/stdc++.h>
using namespace std;

int brute_approach(vector<int> arr){
    int size = arr.size();
    int cnt = 0;

    for(int i = 0; i < size; i++){
        cnt = 0;
        for(int j = 0; j < size; j++){
            if(arr[i] == arr[j]){
                cnt++;
            }
        }

        if(cnt > int(size/2)){
            return arr[i];
        }
    }
}

int better_approach(vector<int> arr){
    map<int, int> cnt;

    for(int i = 0; i < arr.size(); i++){
        cnt[arr[i]]++;
    }

    for (auto it : cnt){
        if(it.second > (arr.size()/2))
            return it.first;
    }

    return -1;
}

int optimal_approach(vector<int> arr){
    // *If the array contains a majority element, its occurrence must be greater than the floor(N/2). Now, we can say that the count of minority elements and majority elements is equal up to a certain point in the array. So when we traverse through the array we try to keep track of the count of elements and the element itself for which we are tracking the count. 

    // *After traversing the whole array, we will check the element stored in the variable. If the question states that the array must contain a majority element, the stored element will be that one but if the question does not state so, then we need to check if the stored element is the majority element or not. If not, then the array does not contain any majority element.

    // Moore's Votin Algorithm
    int size = arr.size();
    int el = 0, cnt = 0;

    for(int i = 0; i < size; i++){
        if(cnt == 0){
            el = arr[i];
            cnt++;
        }
        else if(el == arr[i]) cnt++;
        else{
            cnt--;
        }
    }

    // to count the no of times el appears
    int cnt1 = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] == el) cnt1++;
    }

    if (cnt1 > (size / 2)) return el;
    return -1;
}


int main(){
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = brute_approach(arr);
    cout << "The majority element by brute approach is: " << ans << endl;
    ans = better_approach(arr);
    cout << "The majority element by brute approach is: " << ans << endl;
    ans = optimal_approach(arr);
    cout << "The majority element by brute approach is: " << ans << endl;
    return 0;
}