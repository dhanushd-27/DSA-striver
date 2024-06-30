#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a){
    int n = a.size();

    long long S = 0;
    long long S2 = 0;
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2*n + 1)) / 6;

    for(int i = 0; i < n; i++){
        S += a[i];
        S2 += (a[i] * a[i]);
    }

    long long val1 = S - SN; //(x-y)
    long long val2 = S2 - S2N;
    val2 = val2/val1; //(x+y)

    int x = (val1 + val2) / 2;
    int y = x - val1;

    return {x, y};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
        << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}
