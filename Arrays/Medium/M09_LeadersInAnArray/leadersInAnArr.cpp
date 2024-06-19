#include <bits/stdc++.h>
using namespace std;

vector<int> brute_approach(vector<int> A){
    int n = A.size();
    bool leader = true;
    vector<int> ans;

    for(int i = 0; i < n; i++){
        leader = true;
        for(int j = i+1; j < n; j++){
            if(A[j] > A[i]){
                leader = false;
                break;
            }
        }
        if(leader){
            ans.push_back(A[i]);
        }
    }

    return ans;
}

vector<int> optimal_approach(vector<int> arr){
    //Let us check from back
    int n = arr.size();

    //Last element is always a leader
    vector<int> ans;
    int max = arr[n-1];
    ans.push_back(arr[n-1]);

    for(int i = n - 2; i >= 0; i--){

        if(arr[i] > max){
            ans.push_back(arr[i]);
            max = arr[i];
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> leaders_brute = brute_approach(arr);

    cout << "Leaders in the array using brute approach are: ";
    for (auto leader : leaders_brute) {
        cout << leader << " ";
    }
    cout << endl;

    vector<int> leaders_optimal = optimal_approach(arr);

    cout << "Leaders in the array using optimal approach are: ";
    for (auto leader : leaders_optimal) {
        cout << leader << " ";
    }
    cout << endl;

    return 0;
}