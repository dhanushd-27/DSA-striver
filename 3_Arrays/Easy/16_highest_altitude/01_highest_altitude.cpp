#include <bits/stdc++.h>
using namespace std;

int largestAltitude(vector<int> gain) {
    int sum = 0;
    int max_altitude = INT_MIN;
    int n = gain.size();

    for(int i = 0; i < n; i++){
        sum += gain[i];
        max_altitude = max(max_altitude, sum);
    }

    return max_altitude;
}

int main(){
    vector<int> gain = {-5, 1, 5, 0, -7};
    vector<int> gain2 = {-4, -3, -2, -1, 4, 3, 2};

    int h_alt = largestAltitude(gain);
    int h_alt2 = largestAltitude(gain2);
    printf("The highest is %d.\n", h_alt);
    printf("The highest is %d.\n", h_alt2);
    return 0;
}