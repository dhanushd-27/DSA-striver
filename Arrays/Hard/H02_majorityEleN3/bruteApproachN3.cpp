#include <bits/stdc++.h>
using namespace std;

vector<int> majorEles(vector<int> arr){
    int n = arr.size(); //size of the array
    vector<int> ls; // list of answers

    for (int i = 0; i < n; i++) {
        if (ls.size() == 0 || ls[0] != arr[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                // counting the frequency of v[i]
                if (arr[j] == arr[i]) {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ls.push_back(arr[i]);
        }

        if (ls.size() == 2) break;
    }

    return ls;
}

int main(){
    cout<< "Majority Elements N/3\n";
    cout<< "-------------------------------\n";

    vector<int> res;
    vector<int> arr = {1, 2, 4, 1, 3, 2, 1, 2};

    res = majorEles(arr);
    cout<< "Majority elements are: ";
    for(auto it: res){
        cout<< it<< " ";
    }
}