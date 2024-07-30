#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k){
    int n = a.size();
    int cnt = 0, sum = 0;
    map<int, int> hashMap;

    hashMap[0] = 1;

    for(int i = 0; i < n; i++){
        sum ^= a[i];

        int x = sum ^ k;
        if(hashMap.find(x) != hashMap.end()){
            cnt += hashMap[x];
        }
        hashMap[sum]++;
    }

    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
        << ans << "\n";
    return 0;
}