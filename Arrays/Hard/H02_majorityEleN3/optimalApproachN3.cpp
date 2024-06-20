#include <bits/stdc++.h>
using namespace std;

vector<int> majorEles(vector<int> a){
    vector<int> ls;
    int cnt1 = 0, cnt2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN;

    int n = a.size();
    for(int i = 0; i < n; i++){
        if(cnt1 == 0 && a[i] != ele2){
            cnt1 = 1;
            ele1 = a[i];
        }
        else if(cnt2 == 0 && a[i] != ele1){
            cnt2 = 1;
            ele2 = a[i];
        }
        else if(a[i] == ele1) cnt1++;
        else if(a[i] == ele2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }

    int mini = int(n/3);
    cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == ele1){
            cnt1++;
        }
        if(a[i] == ele2){
            cnt2++;
        }
    }

    if(cnt1 > mini && cnt2 > mini){
        ls.push_back(ele1);
        ls.push_back(ele2);
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