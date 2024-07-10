#include <bits/stdc++.h>
using namespace std;

pair<int, int> solve(vector<int> v, int key, int n){
    int first = -1, last = -1;

    for(int i = 0; i < n; i++){
        if(v[i] == key){
            if(first == -1) first = i;
            last = i;
        }
    }

    return make_pair(first, last);
}

int main(){
    int n = 7;
    int key = 13;
    vector < int > v = {3,4,13,13,13,20,40};
    
    pair<int, int> ans = solve(v, key, n);

    cout<< "The first occurence of value "<< key<< " is at: "<< ans.first<< endl;
    cout<< "The second occurence of value "<< key<< " is at: "<< ans.second<< endl;
    return 0;
}