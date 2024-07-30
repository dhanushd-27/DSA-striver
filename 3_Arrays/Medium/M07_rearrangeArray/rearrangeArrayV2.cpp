#include <bits/stdc++.h>
using namespace std;

// *Problem Statement:
// *There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values. The leftover elements should be placed at the very end in the same order as in array A.

void one_approach(vector<int> A){
    int n = A.size();
    vector<int> pos;
    vector<int> neg;
    vector<int> ans(n, 0);

    for(int i = 0; i < n; i++){
        if(A[i] < 0) neg.push_back(A[i]);
        else pos.push_back(A[i]);
    }

    if(pos.size() < neg.size()){
        for(int i = 0; i < pos.size(); i++){
            ans[2 * i] = pos[i];
            ans[2 * i + 1] = neg[i];
        }

        int index = pos.size() * 2;
        for(int i = pos.size(); i < neg.size(); i++){
            ans[index] = neg[i];
            index++;
        }
    }

    else{
        for(int i = 0; i < neg.size(); i++){
            ans[2 * i] = pos[i];
            ans[2 * i + 1] = neg[i];
        }

        int index = neg.size() * 2;
        for(int i = neg.size(); i < pos.size(); i++){
            ans[index] = pos[i];
            index++;
        }
    }

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}


int main(){
    vector<int> A = {1,2,-4,-5,3,4};

    one_approach(A);
}