#include <bits/stdc++.h>
using namespace std;

long double minimiseMaxDistance(vector<int> a, int k){
    int n = a.size();
    vector<int> howMany(n-1, 0);

    for(int gasStations = 1; gasStations <= k; gasStations++){
        long double maxLen = -1;
        int maxInd = -1;

        for(int i = 0; i < n; i++){
            long double diff = a[i+1] - a[i];
            long double sectionLength = diff/ (long double)(howMany[i]+1);

            if(sectionLength > maxLen){
                maxLen = sectionLength;
                maxInd = i;
            }
        }

        howMany[maxInd]++;
    }

    // Check Minimise Maximum Distance i.e find Output
    long double maxAns = -1;

    for(int i = 0; i < n; i++){
        long double diff = a[i+1] - a[i];
        long double sectionLength = diff/(long double)(howMany[i]+1);
        maxAns = max(maxAns, sectionLength);
    }

    return maxAns;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
